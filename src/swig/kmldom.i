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

// This is the SWIG interface file for the KML DOM.
// This was developed with SWIG version 1.3.35.

%module kmldom

%import "kmlbase.i"

// Include the headers needed to build kmldom_wrap.cc.
%{
#include "kml2/dom.h"
#include "kml2/dom/xsd.h"
%}

// Tell SWIG about std::shared_ptr.  SWIG tracks the inheritance hierarchy
// declared below the %shared_ptr lines so that, e.g., PlacemarkPtr
// "is a" FeaturePtr "is a" ObjectPtr "is a" ElementPtr.
%include <std_shared_ptr.i>

%include "typemaps.i"

// Classes for abstract elements and internal convenience classes.
%shared_ptr(kmlbase::Referent)
%shared_ptr(kmlbase::XmlElement)
%shared_ptr(kmldom::Element)
%shared_ptr(kmldom::AbstractLatLonBox)
%shared_ptr(kmldom::AbstractView)
%shared_ptr(kmldom::BasicLink)
%shared_ptr(kmldom::Container)
%shared_ptr(kmldom::ColorStyle)
%shared_ptr(kmldom::Feature)
%shared_ptr(kmldom::Geometry)
%shared_ptr(kmldom::Object)
%shared_ptr(kmldom::Overlay)
%shared_ptr(kmldom::SnippetCommon)
%shared_ptr(kmldom::StyleSelector)
%shared_ptr(kmldom::SubStyle)
%shared_ptr(kmldom::TimePrimitive)
%shared_ptr(kmldom::UpdateOperation)
%shared_ptr(kmldom::Vec2)

// Classes for concrete elements.
%shared_ptr(kmldom::Alias)
%shared_ptr(kmldom::AtomAuthor)
%shared_ptr(kmldom::AtomLink)
%shared_ptr(kmldom::BalloonStyle)
%shared_ptr(kmldom::Camera)
%shared_ptr(kmldom::Change)
%shared_ptr(kmldom::Coordinates)
%shared_ptr(kmldom::Create)
%shared_ptr(kmldom::Data)
%shared_ptr(kmldom::Delete)
%shared_ptr(kmldom::Document)
%shared_ptr(kmldom::ExtendedData)
%shared_ptr(kmldom::Folder)
%shared_ptr(kmldom::GroundOverlay)
%shared_ptr(kmldom::HotSpot)
%shared_ptr(kmldom::Icon)
%shared_ptr(kmldom::IconStyle)
%shared_ptr(kmldom::IconStyleIcon)
%shared_ptr(kmldom::ImagePyramid)
%shared_ptr(kmldom::InnerBoundaryIs)
%shared_ptr(kmldom::ItemIcon)
%shared_ptr(kmldom::Kml)
%shared_ptr(kmldom::LabelStyle)
%shared_ptr(kmldom::LatLonBox)
%shared_ptr(kmldom::LatLonAltBox)
%shared_ptr(kmldom::LinearRing)
%shared_ptr(kmldom::LineString)
%shared_ptr(kmldom::LineStyle)
%shared_ptr(kmldom::Link)
%shared_ptr(kmldom::LinkSnippet)
%shared_ptr(kmldom::ListStyle)
%shared_ptr(kmldom::Location)
%shared_ptr(kmldom::Lod)
%shared_ptr(kmldom::LookAt)
%shared_ptr(kmldom::Model)
%shared_ptr(kmldom::MultiGeometry)
%shared_ptr(kmldom::NetworkLink)
%shared_ptr(kmldom::Orientation)
%shared_ptr(kmldom::NetworkLinkControl)
%shared_ptr(kmldom::OuterBoundaryIs)
%shared_ptr(kmldom::OverlayXY)
%shared_ptr(kmldom::Pair)
%shared_ptr(kmldom::PhotoOverlay)
%shared_ptr(kmldom::Placemark)
%shared_ptr(kmldom::Polygon)
%shared_ptr(kmldom::Point)
%shared_ptr(kmldom::PolyStyle)
%shared_ptr(kmldom::Region)
%shared_ptr(kmldom::ResourceMap)
%shared_ptr(kmldom::RotationXY)
%shared_ptr(kmldom::Scale)
%shared_ptr(kmldom::Schema)
%shared_ptr(kmldom::SchemaData)
%shared_ptr(kmldom::ScreenOverlay)
%shared_ptr(kmldom::ScreenXY)
%shared_ptr(kmldom::Size)
%shared_ptr(kmldom::SimpleData)
%shared_ptr(kmldom::SimpleField)
%shared_ptr(kmldom::Snippet)
%shared_ptr(kmldom::Style)
%shared_ptr(kmldom::StyleMap)
%shared_ptr(kmldom::TimeSpan)
%shared_ptr(kmldom::TimeStamp)
%shared_ptr(kmldom::ViewVolume)
%shared_ptr(kmldom::Update)

%shared_ptr(kmldom::GxTourPrimitive)
%shared_ptr(kmldom::GxAnimatedUpdate)
%shared_ptr(kmldom::GxFlyTo)
%shared_ptr(kmldom::GxLatLonQuad)
%shared_ptr(kmldom::GxPlaylist)
%shared_ptr(kmldom::GxSoundCue)
%shared_ptr(kmldom::GxTimeSpan)
%shared_ptr(kmldom::GxTimeStamp)
%shared_ptr(kmldom::GxTour)
%shared_ptr(kmldom::GxTourControl)
%shared_ptr(kmldom::GxWait)

// Tell SWIG about C++ Standard Library std::string.
%include "std_string.i"


%include "kml2/dom/xsd.h"

// Tell SWIG about the kmldom type ids (Type_Placemark, etc).

%include "kml2/dom/kml22.h"

// Tell SWIG about the intrusive_ptr typedefs.
%include "kml2/dom/kml_ptr.h"

namespace kmlbase {

%nodefaultctor Referent;
class Referent {
};

%nodefaultctor XmlElement;
class XmlElement {
 public:
  // TODO: XmlnsId get_xmlns() const;
};

}  // end namespace kmlbase

namespace kmldom {

// All complex elements in KML are derived from Element.  Element-derived
// classes are constructed using KmlFactory thus no constructor is available.
// All elements are "%nodefaultctor" given that the constructor is private
// in the underlying class since only the factory creates an element instance.

%nodefaultctor Element;
class Element : public kmlbase::XmlElement {
public:
  virtual KmlDomType Type();
  virtual bool IsA(KmlDomType type_id);
};

// This is <coordinates> in the KML 2.2 XSD.
%nodefaultctor Coordinates;
class Coordinates : public Element {
public:
  void add_latlng(double latitude, double longitude);
  void add_latlngalt(double latitude, double longitude, double altitude);
  size_t get_coordinates_array_size();
  const kmlbase::Vec3 get_coordinates_array_at(unsigned int index);
};

// This is vec2Type in the KML 2.2 XSD.
%nodefaultctor Vec2;
class Vec2 : public Element {
public:
  // x=
  double get_x();
  void set_x(double value);
  bool has_x();
  void clear_x();

  // y=
  double get_y();
  void set_y(double value);
  bool has_y();
  void clear_y();

  // xunits=
  int get_xunits();
  void set_xunits(int value);
  bool has_xunits();
  void clear_xunits();

  // yunits=
  int get_yunits();
  void set_yunits(int value);
  bool has_yunits();
  void clear_yunits();
};

%include "libkml_kmlelements.i"

%nodefaultctor KmlFactory;
class KmlFactory {
public:
  static KmlFactory* GetFactory();

  // This method creates any complex element in Element type.
  ElementPtr CreateElementById(KmlDomType id) const;

  // Factory functions to create all KML complex elements in their native type.
  AliasPtr CreateAlias() const;
  AtomAuthorPtr CreateAtomAuthor() const;
  AtomLinkPtr CreateAtomLink() const;
  BalloonStylePtr CreateBalloonStyle() const;
  CameraPtr CreateCamera() const;
  ChangePtr CreateChange() const;
  CoordinatesPtr CreateCoordinates() const;
  CreatePtr CreateCreate() const;
  DataPtr CreateData() const;
  DeletePtr CreateDelete() const;
  DocumentPtr CreateDocument() const;
  ExtendedDataPtr CreateExtendedData() const;
  FolderPtr CreateFolder() const;
  GroundOverlayPtr CreateGroundOverlay() const;
  HotSpotPtr CreateHotSpot() const;
  IconPtr CreateIcon() const;
  IconStylePtr CreateIconStyle() const;
  IconStyleIconPtr CreateIconStyleIcon() const;
  ImagePyramidPtr CreateImagePyramid() const;
  InnerBoundaryIsPtr CreateInnerBoundaryIs() const;
  ItemIconPtr CreateItemIcon() const;
  KmlPtr CreateKml() const;
  LabelStylePtr CreateLabelStyle() const;
  LatLonBoxPtr CreateLatLonBox() const;
  LatLonAltBoxPtr CreateLatLonAltBox() const;
  LinearRingPtr CreateLinearRing() const;
  LineStringPtr CreateLineString() const;
  LineStylePtr CreateLineStyle() const;
  LinkPtr CreateLink() const;
  LinkSnippetPtr CreateLinkSnippet() const;
  ListStylePtr CreateListStyle() const;
  LocationPtr CreateLocation() const;
  LodPtr CreateLod() const;
  LookAtPtr CreateLookAt() const;
  ModelPtr CreateModel() const;
  MultiGeometryPtr CreateMultiGeometry() const;
  NetworkLinkPtr CreateNetworkLink() const;
  OrientationPtr CreateOrientation() const;
  NetworkLinkControlPtr CreateNetworkLinkControl() const;
  OuterBoundaryIsPtr CreateOuterBoundaryIs() const;
  OverlayXYPtr CreateOverlayXY() const;
  PairPtr CreatePair() const;
  PhotoOverlayPtr CreatePhotoOverlay() const;
  PlacemarkPtr CreatePlacemark() const;
  PolygonPtr CreatePolygon() const;
  PointPtr CreatePoint() const;
  PolyStylePtr CreatePolyStyle() const;
  RegionPtr CreateRegion() const;
  ResourceMapPtr CreateResourceMap() const;
  RotationXYPtr CreateRotationXY() const;
  ScalePtr CreateScale() const;
  SchemaPtr CreateSchema() const;
  SchemaDataPtr CreateSchemaData() const;
  ScreenOverlayPtr CreateScreenOverlay() const;
  ScreenXYPtr CreateScreenXY() const;
  SizePtr CreateSize() const;
  SimpleDataPtr CreateSimpleData() const;
  SimpleFieldPtr CreateSimpleField() const;
  SnippetPtr CreateSnippet() const;
  StylePtr CreateStyle() const;
  StyleMapPtr CreateStyleMap() const;
  TimeSpanPtr CreateTimeSpan() const;
  TimeStampPtr CreateTimeStamp() const;
  ViewVolumePtr CreateViewVolume() const;
  UpdatePtr CreateUpdate() const;

  GxAnimatedUpdatePtr CreateGxAnimatedUpdate() const;
  GxFlyToPtr CreateGxFlyTo() const;
  GxLatLonQuadPtr CreateGxLatLonQuad() const;
  GxPlaylistPtr CreateGxPlaylist() const;
  GxSoundCuePtr CreateGxSoundCue() const;
  GxTimeSpanPtr CreateGxTimeSpan() const;
  GxTimeStampPtr CreateGxTimeStamp() const;
  GxTourPtr CreateGxTour() const;
  GxTourControlPtr CreateGxTourControl() const;
  GxWaitPtr CreateGxWait() const;
};

// Parse KML from memory buffer to Element hierarchy.
ElementPtr ParseKml(const std::string& kml);

// Serialize "pretty": newlines and indentation.
std::string SerializePretty(const ElementPtr& element);

// Serialize "raw": no newlines or indentation added.
std::string SerializeRaw(const ElementPtr& element);

}  // end namespace kmldom

// This must come after the elements declared above in kmlelements.i.
%include "kml2/dom/kml_cast.h"
