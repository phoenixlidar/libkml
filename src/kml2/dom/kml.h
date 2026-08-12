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

#pragma once

#include "kml2/dom/element.h"
#include "kml2/dom/feature.h"
#include "kml2/dom/kml22.h"
#include "kml2/dom/kml_ptr.h"
#include "kml2/dom/networklinkcontrol.h"

namespace kmlbase {
inline namespace v2 {
class Attributes;
}  // end inline namespace v2
}

namespace kmldom {
inline namespace v2 {

class Serializer;
class Visitor;
class VisitorDriver;

// <kml>
class Kml : public BasicElement<Type_kml> {
 public:
  virtual ~Kml();

  const string& get_hint() { return hint_; }
  bool has_hint() const { return has_hint_; }
  void set_hint(const string& hint) {
    hint_ = hint;
    has_hint_ = true;
  }
  void clear_hint() {
    hint_.clear();
    has_hint_ = false;
  }

  const NetworkLinkControlPtr& get_networklinkcontrol() const {
    return networklinkcontrol_;
  }
  bool has_networklinkcontrol() const { return networklinkcontrol_ != nullptr; }
  void set_networklinkcontrol(const NetworkLinkControlPtr& networklinkcontrol) {
    SetComplexChild(networklinkcontrol, &networklinkcontrol_);
  }
  void clear_networklinkcontrol() {
    set_networklinkcontrol(nullptr);
  }

  const FeaturePtr& get_feature() const { return feature_; }
  bool has_feature() const { return feature_ != nullptr; }
  void set_feature(const FeaturePtr& feature) {
    SetComplexChild(feature, &feature_);
  }
  void clear_feature() {
    set_feature(nullptr);
  }

  // Visitor API methods, see visitor.h.
  virtual void Accept(Visitor* visitor);
  virtual void AcceptChildren(VisitorDriver* driver);

 private:
  friend class KmlFactory;
  Kml();
  friend class KmlHandler;
  virtual void AddElement(const ElementPtr& element);
  virtual void ParseAttributes(kmlbase::Attributes* attributes);
  friend class Serializer;
  virtual void Serialize(Serializer& serializer) const;
  virtual void SerializeAttributes(kmlbase::Attributes* attributes) const;
  string hint_;
  bool has_hint_;
  NetworkLinkControlPtr networklinkcontrol_;
  FeaturePtr feature_;
  Kml(const Kml&) = delete;
  Kml& operator=(const Kml&) = delete;
};

}  // end inline namespace v2
}  // end namespace kmldom

