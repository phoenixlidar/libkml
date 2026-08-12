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

#include "kml_cast.h"
#include "kml_ptr.h"
#include <memory>

namespace kmldom {
inline namespace v2 {

AbstractLatLonBoxPtr AsAbstractLatLonBox(const ElementPtr& element) {
  if (element && element->IsA(Type_AbstractLatLonBox)) {
    return std::static_pointer_cast<AbstractLatLonBox>(element);
  }
  return nullptr;
}

AbstractViewPtr AsAbstractView(const ElementPtr& element) {
  if (element && element->IsA(Type_AbstractView)) {
    return std::static_pointer_cast<AbstractView>(element);
  }
  return nullptr;
}

ColorStylePtr AsColorStyle(const ElementPtr& element) {
  if (element && element->IsA(Type_ColorStyle)) {
    return std::static_pointer_cast<ColorStyle>(element);
  }
  return nullptr;
}

ContainerPtr AsContainer(const ElementPtr& element) {
  if (element && element->IsA(Type_Container)) {
    return std::static_pointer_cast<Container>(element);
  }
  return nullptr;
}

FeaturePtr AsFeature(const ElementPtr& element) {
  if (element && element->IsA(Type_Feature)) {
    return std::static_pointer_cast<Feature>(element);
  }
  return nullptr;
}

GeometryPtr AsGeometry(const ElementPtr& element) {
  if (element && element->IsA(Type_Geometry)) {
    return std::static_pointer_cast<Geometry>(element);
  }
  return nullptr;
}

ObjectPtr AsObject(const ElementPtr& element) {
  if (element && element->IsA(Type_Object)) {
    return std::static_pointer_cast<Object>(element);
  }
  return nullptr;
}

OverlayPtr AsOverlay(const ElementPtr& element) {
  if (element && element->IsA(Type_Overlay)) {
    return std::static_pointer_cast<Overlay>(element);
  }
  return nullptr;
}

StyleSelectorPtr AsStyleSelector(const ElementPtr& element) {
  if (element && element->IsA(Type_StyleSelector)) {
    return std::static_pointer_cast<StyleSelector>(element);
  }
  return nullptr;
}

SubStylePtr AsSubStyle(const ElementPtr& element) {
  if (element && element->IsA(Type_SubStyle)) {
    return std::static_pointer_cast<SubStyle>(element);
  }
  return nullptr;
}

TimePrimitivePtr AsTimePrimitive(const ElementPtr& element) {
  if (element && element->IsA(Type_TimePrimitive)) {
    return std::static_pointer_cast<TimePrimitive>(element);
  }
  return nullptr;
}

AliasPtr AsAlias(const ElementPtr& element) {
  if (element && element->Type() == Type_Alias) {
    return std::static_pointer_cast<Alias>(element);
  }
  return nullptr;
}

BalloonStylePtr AsBalloonStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_BalloonStyle) {
    return std::static_pointer_cast<BalloonStyle>(element);
  }
  return nullptr;
}

CameraPtr AsCamera(const ElementPtr& element) {
  if (element && element->Type() == Type_Camera) {
    return std::static_pointer_cast<Camera>(element);
  }
  return nullptr;
}

ChangePtr AsChange(const ElementPtr& element) {
  if (element && element->Type() == Type_Change) {
    return std::static_pointer_cast<Change>(element);
  }
  return nullptr;
}

CreatePtr AsCreate(const ElementPtr& element) {
  if (element && element->Type() == Type_Create) {
    return std::static_pointer_cast<Create>(element);
  }
  return nullptr;
}

DataPtr AsData(const ElementPtr& element) {
  if (element && element->Type() == Type_Data) {
    return std::static_pointer_cast<Data>(element);
  }
  return nullptr;
}

DeletePtr AsDelete(const ElementPtr& element) {
  if (element && element->Type() == Type_Delete) {
    return std::static_pointer_cast<Delete>(element);
  }
  return nullptr;
}

DocumentPtr AsDocument(const ElementPtr& element) {
  if (element && element->Type() == Type_Document) {
    return std::static_pointer_cast<Document>(element);
  }
  return nullptr;
}

FolderPtr AsFolder(const ElementPtr& element) {
  if (element && element->Type() == Type_Folder) {
    return std::static_pointer_cast<Folder>(element);
  }
  return nullptr;
}

GroundOverlayPtr AsGroundOverlay(const ElementPtr& element) {
  if (element && element->Type() == Type_GroundOverlay) {
    return std::static_pointer_cast<GroundOverlay>(element);
  }
  return nullptr;
}

HotSpotPtr AsHotSpot(const ElementPtr& element) {
  if (element && element->Type() == Type_hotSpot) {
    return std::static_pointer_cast<HotSpot>(element);
  }
  return nullptr;
}

IconPtr AsIcon(const ElementPtr& element) {
  if (element && element->Type() == Type_Icon) {
    return std::static_pointer_cast<Icon>(element);
  }
  return nullptr;
}

IconStylePtr AsIconStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_IconStyle) {
    return std::static_pointer_cast<IconStyle>(element);
  }
  return nullptr;
}

IconStyleIconPtr AsIconStyleIcon(const ElementPtr& element) {
  if (element && element->Type() == Type_IconStyleIcon) {
    return std::static_pointer_cast<IconStyleIcon>(element);
  }
  return nullptr;
}

ImagePyramidPtr AsImagePyramid(const ElementPtr& element) {
  if (element && element->Type() == Type_ImagePyramid) {
    return std::static_pointer_cast<ImagePyramid>(element);
  }
  return nullptr;
}

InnerBoundaryIsPtr AsInnerBoundaryIs(const ElementPtr& element) {
  if (element && element->Type() == Type_innerBoundaryIs) {
    return std::static_pointer_cast<InnerBoundaryIs>(element);
  }
  return nullptr;
}

ItemIconPtr AsItemIcon(const ElementPtr& element) {
  if (element && element->Type() == Type_ItemIcon) {
    return std::static_pointer_cast<ItemIcon>(element);
  }
  return nullptr;
}

LabelStylePtr AsLabelStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_LabelStyle) {
    return std::static_pointer_cast<LabelStyle>(element);
  }
  return nullptr;
}

LatLonAltBoxPtr AsLatLonAltBox(const ElementPtr& element) {
  if (element && element->Type() == Type_LatLonAltBox) {
    return std::static_pointer_cast<LatLonAltBox>(element);
  }
  return nullptr;
}

LatLonBoxPtr AsLatLonBox(const ElementPtr& element) {
  if (element && element->Type() == Type_LatLonBox) {
    return std::static_pointer_cast<LatLonBox>(element);
  }
  return nullptr;
}

LineStringPtr AsLineString(const ElementPtr& element) {
  if (element && element->Type() == Type_LineString) {
    return std::static_pointer_cast<LineString>(element);
  }
  return nullptr;
}

LineStylePtr AsLineStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_LineStyle) {
    return std::static_pointer_cast<LineStyle>(element);
  }
  return nullptr;
}

LinearRingPtr AsLinearRing(const ElementPtr& element) {
  if (element && element->Type() == Type_LinearRing) {
    return std::static_pointer_cast<LinearRing>(element);
  }
  return nullptr;
}

LinkPtr AsLink(const ElementPtr& element) {
  if (element && element->Type() == Type_Link) {
    return std::static_pointer_cast<Link>(element);
  }
  return nullptr;
}

LinkSnippetPtr AsLinkSnippet(const ElementPtr& element) {
  if (element && element->Type() == Type_linkSnippet) {
    return std::static_pointer_cast<LinkSnippet>(element);
  }
  return nullptr;
}

ListStylePtr AsListStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_ListStyle) {
    return std::static_pointer_cast<ListStyle>(element);
  }
  return nullptr;
}

LocationPtr AsLocation(const ElementPtr& element) {
  if (element && element->Type() == Type_Location) {
    return std::static_pointer_cast<Location>(element);
  }
  return nullptr;
}

LodPtr AsLod(const ElementPtr& element) {
  if (element && element->Type() == Type_Lod) {
    return std::static_pointer_cast<Lod>(element);
  }
  return nullptr;
}

LookAtPtr AsLookAt(const ElementPtr& element) {
  if (element && element->Type() == Type_LookAt) {
    return std::static_pointer_cast<LookAt>(element);
  }
  return nullptr;
}

ModelPtr AsModel(const ElementPtr& element) {
  if (element && element->Type() == Type_Model) {
    return std::static_pointer_cast<Model>(element);
  }
  return nullptr;
}

MultiGeometryPtr AsMultiGeometry(const ElementPtr& element) {
  if (element && element->Type() == Type_MultiGeometry) {
    return std::static_pointer_cast<MultiGeometry>(element);
  }
  return nullptr;
}

NetworkLinkPtr AsNetworkLink(const ElementPtr& element) {
  if (element && element->Type() == Type_NetworkLink) {
    return std::static_pointer_cast<NetworkLink>(element);
  }
  return nullptr;
}

OrientationPtr AsOrientation(const ElementPtr& element) {
  if (element && element->Type() == Type_Orientation) {
    return std::static_pointer_cast<Orientation>(element);
  }
  return nullptr;
}

OuterBoundaryIsPtr AsOuterBoundaryIs(const ElementPtr& element) {
  if (element && element->Type() == Type_outerBoundaryIs) {
    return std::static_pointer_cast<OuterBoundaryIs>(element);
  }
  return nullptr;
}

OverlayXYPtr AsOverlayXY(const ElementPtr& element) {
  if (element && element->Type() == Type_overlayXY) {
    return std::static_pointer_cast<OverlayXY>(element);
  }
  return nullptr;
}

PairPtr AsPair(const ElementPtr& element) {
  if (element && element->Type() == Type_Pair) {
    return std::static_pointer_cast<Pair>(element);
  }
  return nullptr;
}

PhotoOverlayPtr AsPhotoOverlay(const ElementPtr& element) {
  if (element && element->Type() == Type_PhotoOverlay) {
    return std::static_pointer_cast<PhotoOverlay>(element);
  }
  return nullptr;
}

PlacemarkPtr AsPlacemark(const ElementPtr& element) {
  if (element && element->Type() == Type_Placemark) {
    return std::static_pointer_cast<Placemark>(element);
  }
  return nullptr;
}

PointPtr AsPoint(const ElementPtr& element) {
  if (element && element->Type() == Type_Point) {
    return std::static_pointer_cast<Point>(element);
  }
  return nullptr;
}

PolyStylePtr AsPolyStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_PolyStyle) {
    return std::static_pointer_cast<PolyStyle>(element);
  }
  return nullptr;
}

PolygonPtr AsPolygon(const ElementPtr& element) {
  if (element && element->Type() == Type_Polygon) {
    return std::static_pointer_cast<Polygon>(element);
  }
  return nullptr;
}

RegionPtr AsRegion(const ElementPtr& element) {
  if (element && element->Type() == Type_Region) {
    return std::static_pointer_cast<Region>(element);
  }
  return nullptr;
}

ResourceMapPtr AsResourceMap(const ElementPtr& element) {
  if (element && element->Type() == Type_ResourceMap) {
    return std::static_pointer_cast<ResourceMap>(element);
  }
  return nullptr;
}

RotationXYPtr AsRotationXY(const ElementPtr& element) {
  if (element && element->Type() == Type_rotationXY) {
    return std::static_pointer_cast<RotationXY>(element);
  }
  return nullptr;
}

ScalePtr AsScale(const ElementPtr& element) {
  if (element && element->Type() == Type_Scale) {
    return std::static_pointer_cast<Scale>(element);
  }
  return nullptr;
}

SchemaPtr AsSchema(const ElementPtr& element) {
  if (element && element->Type() == Type_Schema) {
    return std::static_pointer_cast<Schema>(element);
  }
  return nullptr;
}

SchemaDataPtr AsSchemaData(const ElementPtr& element) {
  if (element && element->Type() == Type_SchemaData) {
    return std::static_pointer_cast<SchemaData>(element);
  }
  return nullptr;
}

ScreenOverlayPtr AsScreenOverlay(const ElementPtr& element) {
  if (element && element->Type() == Type_ScreenOverlay) {
    return std::static_pointer_cast<ScreenOverlay>(element);
  }
  return nullptr;
}

ScreenXYPtr AsScreenXY(const ElementPtr& element) {
  if (element && element->Type() == Type_screenXY) {
    return std::static_pointer_cast<ScreenXY>(element);
  }
  return nullptr;
}

SizePtr AsSize(const ElementPtr& element) {
  if (element && element->Type() == Type_size) {
    return std::static_pointer_cast<Size>(element);
  }
  return nullptr;
}

SnippetPtr AsSnippet(const ElementPtr& element) {
  if (element && element->Type() == Type_Snippet) {
    return std::static_pointer_cast<Snippet>(element);
  }
  return nullptr;
}

StylePtr AsStyle(const ElementPtr& element) {
  if (element && element->Type() == Type_Style) {
    return std::static_pointer_cast<Style>(element);
  }
  return nullptr;
}

StyleMapPtr AsStyleMap(const ElementPtr& element) {
  if (element && element->Type() == Type_StyleMap) {
    return std::static_pointer_cast<StyleMap>(element);
  }
  return nullptr;
}

TimeSpanPtr AsTimeSpan(const ElementPtr& element) {
  if (element && element->IsA(Type_TimeSpan)) {
    return std::static_pointer_cast<TimeSpan>(element);
  }
  return nullptr;
}

TimeStampPtr AsTimeStamp(const ElementPtr& element) {
  if (element && element->IsA(Type_TimeStamp)) {
    return std::static_pointer_cast<TimeStamp>(element);
  }
  return nullptr;
}

ViewVolumePtr AsViewVolume(const ElementPtr& element) {
  if (element && element->Type() == Type_ViewVolume) {
    return std::static_pointer_cast<ViewVolume>(element);
  }
  return nullptr;
}

}  // end inline namespace v2
}  // end namespace kmldom
