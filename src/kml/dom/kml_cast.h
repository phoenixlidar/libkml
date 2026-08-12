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



#include "kml/base/xml_element.h"
#include "kml/dom/kmldom.h"
#include "kml/dom/kml_ptr.h"

namespace kmldom {
inline namespace v2 {

// This function template operates akin to dynamic_cast.  If the given
// Element-derived type is of the template type then a pointer is returned,
// else nullptr.  It is safe to pass a nullptr to this function.
template<class T>
inline std::shared_ptr<T> ElementCast(
    const ElementPtr& element) {
  if (element && element->IsA(T::ElementType())) {
    return std::static_pointer_cast<T>(element);
  }
  return nullptr;
}

inline ElementPtr AsElement(const kmlbase::XmlElementPtr& xml_element) {
  return std::static_pointer_cast<Element>(xml_element);
}

// Abstract element groups.
AbstractLatLonBoxPtr AsAbstractLatLonBox(const ElementPtr& element);
AbstractViewPtr AsAbstractView(const ElementPtr& element);
ColorStylePtr AsColorStyle(const ElementPtr& element);
ContainerPtr AsContainer(const ElementPtr& element);
FeaturePtr AsFeature(const ElementPtr& element);
GeometryPtr AsGeometry(const ElementPtr& element);
ObjectPtr AsObject(const ElementPtr& element);
OverlayPtr AsOverlay(const ElementPtr& element);
StyleSelectorPtr AsStyleSelector(const ElementPtr& element);
SubStylePtr AsSubStyle(const ElementPtr& element);
TimePrimitivePtr AsTimePrimitive(const ElementPtr& element);

// Concrete elements.
AliasPtr AsAlias(const ElementPtr& element);
BalloonStylePtr AsBalloonStyle(const ElementPtr& element);
CameraPtr AsCamera(const ElementPtr& element);
ChangePtr AsChange(const ElementPtr& element);
inline CoordinatesPtr AsCoordinates(const ElementPtr& element) {
  return ElementCast<Coordinates>(element);
}
CreatePtr AsCreate(const ElementPtr& element);
DataPtr AsData(const ElementPtr& element);
DeletePtr AsDelete(const ElementPtr& element);
DocumentPtr AsDocument(const ElementPtr& element);
inline ExtendedDataPtr AsExtendedData(const ElementPtr& element) {
  return ElementCast<ExtendedData>(element);
}
FolderPtr AsFolder(const ElementPtr& element);
GroundOverlayPtr AsGroundOverlay(const ElementPtr& element);
HotSpotPtr AsHotSpot(const ElementPtr& element);
IconPtr AsIcon(const ElementPtr& element);
IconStylePtr AsIconStyle(const ElementPtr& element);
IconStyleIconPtr AsIconStyleIcon(const ElementPtr& element);
ImagePyramidPtr AsImagePyramid(const ElementPtr& element);
InnerBoundaryIsPtr AsInnerBoundaryIs(const ElementPtr& element);
ItemIconPtr AsItemIcon(const ElementPtr& element);
inline KmlPtr AsKml(const ElementPtr& element) {
  return ElementCast<Kml>(element);
}
LabelStylePtr AsLabelStyle(const ElementPtr& element);
LatLonAltBoxPtr AsLatLonAltBox(const ElementPtr& element);
LatLonBoxPtr AsLatLonBox(const ElementPtr& element);
LineStringPtr AsLineString(const ElementPtr& element);
LineStylePtr AsLineStyle(const ElementPtr& element);
LinearRingPtr AsLinearRing(const ElementPtr& element);
LinkPtr AsLink(const ElementPtr& element);
LinkSnippetPtr AsLinkSnippet(const ElementPtr& element);
ListStylePtr AsListStyle(const ElementPtr& element);
LocationPtr AsLocation(const ElementPtr& element);
LodPtr AsLod(const ElementPtr& element);
LookAtPtr AsLookAt(const ElementPtr& element);
inline MetadataPtr AsMetadata(const ElementPtr& element) {
  return ElementCast<Metadata>(element);
}
ModelPtr AsModel(const ElementPtr& element);
MultiGeometryPtr AsMultiGeometry(const ElementPtr& element);
NetworkLinkPtr AsNetworkLink(const ElementPtr& element);
inline NetworkLinkControlPtr AsNetworkLinkControl(
    const ElementPtr& element) {
  return ElementCast<NetworkLinkControl>(element);
}
OrientationPtr AsOrientation(const ElementPtr& element);
OuterBoundaryIsPtr AsOuterBoundaryIs(const ElementPtr& element);
OverlayXYPtr AsOverlayXY(const ElementPtr& element);
PairPtr AsPair(const ElementPtr& element);
PhotoOverlayPtr AsPhotoOverlay(const ElementPtr& element);
PlacemarkPtr AsPlacemark(const ElementPtr& element);
PointPtr AsPoint(const ElementPtr& element);
PolyStylePtr AsPolyStyle(const ElementPtr& element);
PolygonPtr AsPolygon(const ElementPtr& element);
RegionPtr AsRegion(const ElementPtr& element);
ResourceMapPtr AsResourceMap(const ElementPtr& element);
RotationXYPtr AsRotationXY(const ElementPtr& element);
ScalePtr AsScale(const ElementPtr& element);
SchemaPtr AsSchema(const ElementPtr& element);
SchemaDataPtr AsSchemaData(const ElementPtr& element);
ScreenOverlayPtr AsScreenOverlay(const ElementPtr& element);
ScreenXYPtr AsScreenXY(const ElementPtr& element);
inline SimpleDataPtr AsSimpleData(const ElementPtr& element) {
  return ElementCast<SimpleData>(element);
}
inline SimpleFieldPtr AsSimpleField(const ElementPtr& element) {
  return ElementCast<SimpleField>(element);
}
SizePtr AsSize(const ElementPtr& element);
SnippetPtr AsSnippet(const ElementPtr& element);
StylePtr AsStyle(const ElementPtr& element);
StyleMapPtr AsStyleMap(const ElementPtr& element);
TimeSpanPtr AsTimeSpan(const ElementPtr& element);
TimeStampPtr AsTimeStamp(const ElementPtr& element);
inline UpdatePtr AsUpdate(const ElementPtr& element) {
  return ElementCast<Update>(element);
}
ViewVolumePtr AsViewVolume(const ElementPtr& element);

// Atom
inline AtomAuthorPtr AsAtomAuthor(const ElementPtr& element) {
  return ElementCast<AtomAuthor>(element);
}
inline AtomCategoryPtr AsAtomCategory(const ElementPtr& element) {
  return ElementCast<AtomCategory>(element);
}
inline AtomContentPtr AsAtomContent(const ElementPtr& element) {
  return ElementCast<AtomContent>(element);
}
inline AtomEntryPtr AsAtomEntry(const ElementPtr& element) {
  return ElementCast<AtomEntry>(element);
}
inline AtomFeedPtr AsAtomFeed(const ElementPtr& element) {
  return ElementCast<AtomFeed>(element);
}
inline AtomLinkPtr AsAtomLink(const ElementPtr& element) {
  return ElementCast<AtomLink>(element);
}

// xAL
inline XalAddressDetailsPtr AsXalAddressDetails(
    const ElementPtr& element) {
  return ElementCast<XalAddressDetails>(element);
}
inline XalAdministrativeAreaPtr AsXalAdministrativeArea(
    const ElementPtr& element) {
  return ElementCast<XalAdministrativeArea>(element);
}

inline XalCountryPtr AsXalCountry(const ElementPtr& element) {
  return ElementCast<XalCountry>(element);
}

inline XalLocalityPtr AsXalLocality(const ElementPtr& element) {
  return ElementCast<XalLocality>(element);
}

inline XalPostalCodePtr AsXalPostalCode(const ElementPtr& element) {
  return ElementCast<XalPostalCode>(element);
}

inline XalSubAdministrativeAreaPtr AsXalSubAdministrativeArea(
    const ElementPtr& element) {
  return ElementCast<XalSubAdministrativeArea>(element);
}

inline XalThoroughfarePtr AsXalThoroughfare(const ElementPtr& element) {
  return ElementCast<XalThoroughfare>(element);
}

// gx

inline GxAnimatedUpdatePtr AsGxAnimatedUpdate(const ElementPtr& element) {
  return ElementCast<GxAnimatedUpdate>(element);
}

inline GxFlyToPtr AsGxFlyTo(const ElementPtr& element) {
  return ElementCast<GxFlyTo>(element);
}

inline GxLatLonQuadPtr AsGxLatLonQuad(const ElementPtr& element) {
  return ElementCast<GxLatLonQuad>(element);
}

inline GxMultiTrackPtr AsGxMultiTrack(const ElementPtr& element) {
  return ElementCast<GxMultiTrack>(element);
}

inline GxPlaylistPtr AsGxPlaylist(const ElementPtr& element) {
  return ElementCast<GxPlaylist>(element);
}

inline GxSimpleArrayFieldPtr AsGxSimpleArrayField(
    const ElementPtr& element) {
  return ElementCast<GxSimpleArrayField>(element);
}

inline GxSimpleArrayDataPtr AsGxSimpleArrayData(
    const ElementPtr& element) {
  return ElementCast<GxSimpleArrayData>(element);
}

inline GxSoundCuePtr AsGxSoundCue(const ElementPtr& element) {
  return ElementCast<GxSoundCue>(element);
}

inline GxTimeSpanPtr AsGxTimeSpan(const ElementPtr& element) {
  return ElementCast<GxTimeSpan>(element);
}

inline GxTimeStampPtr AsGxTimeStamp(const ElementPtr& element) {
  return ElementCast<GxTimeStamp>(element);
}

inline GxTourPtr AsGxTour(const ElementPtr& element) {
  return ElementCast<GxTour>(element);
}

inline GxTourControlPtr AsGxTourControl(const ElementPtr& element) {
  return ElementCast<GxTourControl>(element);
}

inline GxTourPrimitivePtr AsGxTourPrimitive(const ElementPtr& element) {
  return ElementCast<GxTourPrimitive>(element);
}

inline GxTrackPtr AsGxTrack(const ElementPtr& element) {
  return ElementCast<GxTrack>(element);
}

inline GxWaitPtr AsGxWait(const ElementPtr& element) {
  return ElementCast<GxWait>(element);
}

}  // end inline namespace v2
}  // end namespace kmldom

