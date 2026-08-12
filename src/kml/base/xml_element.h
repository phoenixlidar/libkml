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

// This file contains the definition of the XmlElement class.

#pragma once

#include <memory>
#include "kml/base/referent.h"
#include "kml/base/util.h"
#include "kml/base/xml_namespaces.h"

namespace kmlbase {
inline namespace v2 {

class XmlFile;

// Forward declare XmlElement to create typedef used within class XmlElement.
class XmlElement;

using XmlElementPtr = std::shared_ptr<XmlElement>;

// This class represents an XML element.  An XmlElement may be in one XmlFile,
// and may have one parent XmlElement.  This class is derived from Referent
// such that derived classes can use std::shared_ptr.
class XmlElement : public Referent {
 public:
  // Get the parent XmlElement if any.  Returns nullptr if this element has
  // no parent or the parent has already been destroyed.
  XmlElementPtr GetParent() const {
    return parent_.lock();
  }

  // Get the parent XmlFile if any.
  const XmlFile* GetXmlFile() const {
    return xml_file_;
  }

  XmlnsId get_xmlns() const {
    return xmlns_id_;
  }

  // This returns true if the passed element is in the same XmlFile or if both
  // this XmlElement and the passed element are in no XmlFile.  Passing a nullptr
  // always causes a false return value.
  bool InSameXmlFile(const XmlElementPtr& element) const {
    return element && xml_file_ == element->xml_file_;
  }

  bool InSameXmlFile(const XmlElement* element) const {
    return element && xml_file_ == element->xml_file_;
  }

  // If this element is not already in an XmlFile this associates this element
  // with the given XmlFile and true is returned.  If this element is already
  // in an XmlFile false is returned and that association remains.  There is
  // no means to detach an XmlElement from an XmlFile.
  bool SetXmlFile(const XmlFile* xml_file) {
    if (!xml_file_ && xml_file) {
      xml_file_ = xml_file;
      return true;
    }
    return false;
  }

 protected:
  // This is an abstract base class and is never created directly.
  XmlElement() : xmlns_id_(XMLNS_NONE), xml_file_(nullptr) {}

  void set_xmlns(XmlnsId xmlns_id) {
    xmlns_id_ = xmlns_id;
  }

  // Only a derived class can set its parent.  This returns false if this
  // XmlElement already has a (live) parent or if this XmlElement is in a
  // different XmlFile.  The parent is stored as a weak_ptr to avoid strong
  // circular references; the parent must be owned by a shared_ptr.
  bool SetParent(XmlElement* parent) {
    if (!parent_.lock() && parent && InSameXmlFile(parent)) {
      parent_ = std::static_pointer_cast<XmlElement>(parent->shared_from_this());
      return true;
    }
    return false;
  }

 private:
  XmlnsId xmlns_id_;
  std::weak_ptr<XmlElement> parent_;
  const XmlFile* xml_file_;
  XmlElement(const XmlElement&) = delete;
  XmlElement& operator=(const XmlElement&) = delete;
};

}  // end inline namespace v2
}  // end namespace kmlbase

