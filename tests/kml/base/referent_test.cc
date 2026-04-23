// Copyright 2008, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. Neither the name of Google Inc. nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// This file contains the unit tests for the Referent class and
// std::shared_ptr usage.

#include "kml/base/referent.h"
#include <vector>
#include <memory>
#include "gtest/gtest.h"

namespace kmlbase {

class ReferentTest : public testing::Test {
 protected:
  virtual void SetUp() {
    derived_ = std::make_shared<Derived>();
  }

  // This forward declaration is for the benefit of the using alias.
  class Derived;
  using DerivedPtr = std::shared_ptr<Derived>;

  // This is a test class for exercising expected usage scenarios of the
  // Referent class.
  class Derived : public Referent {
   public:
    void set_child(DerivedPtr child) {
      child_ = child;
    }
    void clear_child() {
      child_ = nullptr;
    }
    DerivedPtr child() const {
      return child_;
    }
    // This method avoids returning child_ by value for tests that just
    // wish to verify the use count of the child.
    // This is valid to call only if Derived has a child.
    long child_use_count() const {
      return child_.use_count();
    }

   private:
    DerivedPtr child_;
  };

  DerivedPtr derived_;
  void FuncByValue(DerivedPtr d, long expected_use_count);
  void FuncByReference(DerivedPtr& d, long expected_use_count);
};

// This tests the Referent class itself (which is now just a base class
// providing enable_shared_from_this support).
TEST_F(ReferentTest, TestReferent) {
  auto referent = std::make_shared<Referent>();
  // std::shared_ptr manages reference counting internally.
  ASSERT_EQ(1, referent.use_count());

  // Copy the shared_ptr to increase the use count.
  auto copy = referent;
  ASSERT_EQ(2, referent.use_count());
  ASSERT_EQ(2, copy.use_count());
}

TEST_F(ReferentTest, TestDelete) {
  // SetUp created one instance of Derived.
  ASSERT_EQ(1, derived_.use_count());

  {
    // Copy the pointer and verify that both see the same underlying object and
    // use count.
    DerivedPtr copy = derived_;
    ASSERT_EQ(copy.get(), derived_.get());
    ASSERT_EQ(2, derived_.use_count());
    ASSERT_EQ(2, copy.use_count());
  }

  // copy is now out of scope so use count is back to 1
  ASSERT_EQ(1, derived_.use_count());
}

TEST_F(ReferentTest, TestVector) {
  const int kCount = 101;
  {
    std::vector<DerivedPtr> derived_vec;
    int n = kCount;
    while (n--) {
      // STL vector makes a copy of the smart pointer hence bumps use count.
      derived_vec.push_back(derived_);
      ASSERT_EQ(kCount - n + 1, derived_.use_count());
    }
  // End of scope of vector deletes all vector members.
  }
  // derived_vec is now out of scope so use count is back to 1
  ASSERT_EQ(1, derived_.use_count());
}

// Helper function for TestFunc().  This verifies that passing a DerivedPtr
// by value increases the use count.
void ReferentTest::FuncByValue(DerivedPtr d, long expected_use_count) {
  ASSERT_EQ(expected_use_count, derived_.use_count());
  ASSERT_EQ(d.get(), derived_.get());
}

// Helper function for TestFunc().  This verifies that passing a DerivedPtr
// by reference does not increase the use count.
void ReferentTest::FuncByReference(DerivedPtr& d, long expected_use_count) {
  ASSERT_EQ(1, derived_.use_count());
  ASSERT_EQ(d.get(), derived_.get());
}

// This verifies std::shared_ptr's use count is proper for pass by value
// and pass by reference.
TEST_F(ReferentTest, TestFunc) {
  // Verify initial conditions:
  ASSERT_EQ(1, derived_.use_count());
  // Pass a std::shared_ptr by value thus increasing the use count.
  FuncByValue(derived_, 2);
  // Pass by value now out of scope so use count back to where it was:
  ASSERT_EQ(1, derived_.use_count());
  // Pass by reference does not increase the use count.
  FuncByReference(derived_, 1);
}

// This test verifies that giving a given child object to a parent increments
// the use count.
TEST_F(ReferentTest, TestBasicParentChild) {
  Derived* bare_pointer;
  {
    DerivedPtr child = std::make_shared<Derived>();
    bare_pointer = child.get();

    // Verify that adding this child to the parent increments the use count.
    derived_->set_child(child);
    ASSERT_EQ(2, child.use_count());

    // Verify that deleting this child from the parent decrements the use count.
    derived_->clear_child();
    ASSERT_EQ(1, child.use_count());

    // Set it to the parent again.
    derived_->set_child(child);
    ASSERT_EQ(2, child.use_count());
    // End scope for child.
  }

  // The parent now owns the only reference.
  ASSERT_EQ(bare_pointer, derived_->child().get());
  ASSERT_EQ(1, derived_->child_use_count());
}

// This verifies that holding a reference to a child of a given parent is still
// valid even after the parent is destroyed.
TEST_F(ReferentTest, TestGetChild) {
  // Verify initial conditions: test fixture is only owner of object.
  ASSERT_EQ(1, derived_.use_count());
  // Introduce a block to own child.
  {
    DerivedPtr child;
    // Introduce a block to own parent.
    {
      DerivedPtr parent = std::make_shared<Derived>();
      parent->set_child(derived_);
      child = parent->child();
      ASSERT_EQ(derived_, parent->child());
      // ReferentTest derived_, child, and child_ within parent.
      ASSERT_EQ(3, parent->child_use_count());
      // parent now goes out of scope and is destroyed releasing its reference
      // to the child.
    }
    // child is now the only user of the object along with derived_.
    ASSERT_EQ(2, child.use_count());
  }
  // Only the test fixture refers to the object.
  ASSERT_EQ(1, derived_.use_count());
  // The object is released when child goes out of scope.
}

}  // end namespace kmlbase
