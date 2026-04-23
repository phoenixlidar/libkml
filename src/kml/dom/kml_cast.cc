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

const AbstractLatLonBoxPtr AsAbstractLatLonBox(const ElementPtr element) {
  if (element && element->IsA(Type_AbstractLatLonBox)) {
    return std::static_pointer_cast<AbstractLatLonBox>(element);
  }
  return nullptr;
}

const AbstractViewPtr AsAbstractView(const ElementPtr element) {
  if (element && element->IsA(Type_AbstractView)) {
    return std::static_pointer_cast<AbstractView>(element);
  }
  return nullptr;
}

const ColorStylePtr AsColorStyle(const ElementPtr element) {
  if (element && element->IsA(Type_ColorStyle)) {
    return std::static_pointer_cast<ColorStyle>(element);
  }
  return nullptr;
}

const ContainerPtr AsContainer(const ElementPtr element) {
  if (element && element->IsA(Type_Container)) {
    return std::static_pointer_cast<Container>(element);
  }
  return nullptr;
}

const FeaturePtr AsFeature(const ElementPtr element) {
  if (element && element->IsA(Type_Feature)) {
    return std::static_pointer_cast<Feature>(element);
  }
  return nullptr;
}

const GeometryPtr AsGeometry(const ElementPtr element) {
  if (element && element->IsA(Type_Geometry)) {
    return std::static_pointer_cast<Geometry>(element);
  }
  return nullptr;
}

const ObjectPtr AsObject(const ElementPtr element) {
  if (element && element->IsA(Type_Object)) {
    return std::static_pointer_cast<Object>(element);
  }
  return nullptr;
}

const OverlayPtr AsOverlay(const ElementPtr element) {
  if (element && element->IsA(Type_Overlay)) {
    return std::static_pointer_cast<Overlay>(element);
  }
  return nullptr;
}

const StyleSelectorPtr AsStyleSelector(const ElementPtr element) {
  if (element && element->IsA(Type_StyleSelector)) {
    return std::static_pointer_cast<StyleSelector>(element);
  }
  return nullptr;
}

const SubStylePtr AsSubStyle(const ElementPtr element) {
  if (element && element->IsA(Type_SubStyle)) {
    return std::static_pointer_cast<SubStyle>(element);
  }
  return nullptr;
}

const TimePrimitivePtr AsTimePrimitive(const ElementPtr element) {
  if (element && element->IsA(Type_TimePrimitive)) {
    return std::static_pointer_cast<TimePrimitive>(element);
  }
  return nullptr;
}

const AliasPtr AsAlias(const ElementPtr element) {
  if (element && element->Type() == Type_Alias) {
    return std::static_pointer_cast<Alias>(element);
  }
  return nullptr;
}

const BalloonStylePtr AsBalloonStyle(const ElementPtr element) {
  if (element && element->Type() == Type_BalloonStyle) {
    return std::static_pointer_cast<BalloonStyle>(element);
  }
  return nullptr;
}

const CameraPtr AsCamera(const ElementPtr element) {
  if (element && element->Type() == Type_Camera) {
    return std::static_pointer_cast<Camera>(element);
  }
  return nullptr;
}

const ChangePtr AsChange(const ElementPtr element) {
  if (element && element->Type() == Type_Change) {
    return std::static_pointer_cast<Change>(element);
  }
  return nullptr;
}

const CreatePtr AsCreate(const ElementPtr element) {
  if (element && element->Type() == Type_Create) {
    return std::static_pointer_cast<Create>(element);
  }
  return nullptr;
}

const DataPtr AsData(const ElementPtr element) {
  if (element && element->Type() == Type_Data) {
    return std::static_pointer_cast<Data>(element);
  }
  return nullptr;
}

const DeletePtr AsDelete(const ElementPtr element) {
  if (element && element->Type() == Type_Delete) {
    return std::static_pointer_cast<Delete>(element);
  }
  return nullptr;
}

const DocumentPtr AsDocument(const ElementPtr element) {
  if (element && element->Type() == Type_Document) {
    return std::static_pointer_cast<Document>(element);
  }
  return nullptr;
}

const FolderPtr AsFolder(const ElementPtr element) {
  if (element && element->Type() == Type_Folder) {
    return std::static_pointer_cast<Folder>(element);
  }
  return nullptr;
}

const GroundOverlayPtr AsGroundOverlay(const ElementPtr element) {
  if (element && element->Type() == Type_GroundOverlay) {
    return std::static_pointer_cast<GroundOverlay>(element);
  }
  return nullptr;
}

const HotSpotPtr AsHotSpot(const ElementPtr element) {
  if (element && element->Type() == Type_hotSpot) {
    return std::static_pointer_cast<HotSpot>(element);
  }
  return nullptr;
}

const IconPtr AsIcon(const ElementPtr element) {
  if (element && element->Type() == Type_Icon) {
    return std::static_pointer_cast<Icon>(element);
  }
  return nullptr;
}

const IconStylePtr AsIconStyle(const ElementPtr element) {
  if (element && element->Type() == Type_IconStyle) {
    return std::static_pointer_cast<IconStyle>(element);
  }
  return nullptr;
}

const IconStyleIconPtr AsIconStyleIcon(const ElementPtr element) {
  if (element && element->Type() == Type_IconStyleIcon) {
    return std::static_pointer_cast<IconStyleIcon>(element);
  }
  return nullptr;
}

const ImagePyramidPtr AsImagePyramid(const ElementPtr element) {
  if (element && element->Type() == Type_ImagePyramid) {
    return std::static_pointer_cast<ImagePyramid>(element);
  }
  return nullptr;
}

const InnerBoundaryIsPtr AsInnerBoundaryIs(const ElementPtr element) {
  if (element && element->Type() == Type_innerBoundaryIs) {
    return std::static_pointer_cast<InnerBoundaryIs>(element);
  }
  return nullptr;
}

const ItemIconPtr AsItemIcon(const ElementPtr element) {
  if (element && element->Type() == Type_ItemIcon) {
    return std::static_pointer_cast<ItemIcon>(element);
  }
  return nullptr;
}

const LabelStylePtr AsLabelStyle(const ElementPtr element) {
  if (element && element->Type() == Type_LabelStyle) {
    return std::static_pointer_cast<LabelStyle>(element);
  }
  return nullptr;
}

const LatLonAltBoxPtr AsLatLonAltBox(const ElementPtr element) {
  if (element && element->Type() == Type_LatLonAltBox) {
    return std::static_pointer_cast<LatLonAltBox>(element);
  }
  return nullptr;
}

const LatLonBoxPtr AsLatLonBox(const ElementPtr element) {
  if (element && element->Type() == Type_LatLonBox) {
    return std::static_pointer_cast<LatLonBox>(element);
  }
  return nullptr;
}

const LineStringPtr AsLineString(const ElementPtr element) {
  if (element && element->Type() == Type_LineString) {
    return std::static_pointer_cast<LineString>(element);
  }
  return nullptr;
}

const LineStylePtr AsLineStyle(const ElementPtr element) {
  if (element && element->Type() == Type_LineStyle) {
    return std::static_pointer_cast<LineStyle>(element);
  }
  return nullptr;
}

const LinearRingPtr AsLinearRing(const ElementPtr element) {
  if (element && element->Type() == Type_LinearRing) {
    return std::static_pointer_cast<LinearRing>(element);
  }
  return nullptr;
}

const LinkPtr AsLink(const ElementPtr element) {
  if (element && element->Type() == Type_Link) {
    return std::static_pointer_cast<Link>(element);
  }
  return nullptr;
}

const LinkSnippetPtr AsLinkSnippet(const ElementPtr element) {
  if (element && element->Type() == Type_linkSnippet) {
    return std::static_pointer_cast<LinkSnippet>(element);
  }
  return nullptr;
}

const ListStylePtr AsListStyle(const ElementPtr element) {
  if (element && element->Type() == Type_ListStyle) {
    return std::static_pointer_cast<ListStyle>(element);
  }
  return nullptr;
}

const LocationPtr AsLocation(const ElementPtr element) {
  if (element && element->Type() == Type_Location) {
    return std::static_pointer_cast<Location>(element);
  }
  return nullptr;
}

const LodPtr AsLod(const ElementPtr element) {
  if (element && element->Type() == Type_Lod) {
    return std::static_pointer_cast<Lod>(element);
  }
  return nullptr;
}

const LookAtPtr AsLookAt(const ElementPtr element) {
  if (element && element->Type() == Type_LookAt) {
    return std::static_pointer_cast<LookAt>(element);
  }
  return nullptr;
}

const ModelPtr AsModel(const ElementPtr element) {
  if (element && element->Type() == Type_Model) {
    return std::static_pointer_cast<Model>(element);
  }
  return nullptr;
}

const MultiGeometryPtr AsMultiGeometry(const ElementPtr element) {
  if (element && element->Type() == Type_MultiGeometry) {
    return std::static_pointer_cast<MultiGeometry>(element);
  }
  return nullptr;
}

const NetworkLinkPtr AsNetworkLink(const ElementPtr element) {
  if (element && element->Type() == Type_NetworkLink) {
    return std::static_pointer_cast<NetworkLink>(element);
  }
  return nullptr;
}

const OrientationPtr AsOrientation(const ElementPtr element) {
  if (element && element->Type() == Type_Orientation) {
    return std::static_pointer_cast<Orientation>(element);
  }
  return nullptr;
}

const OuterBoundaryIsPtr AsOuterBoundaryIs(const ElementPtr element) {
  if (element && element->Type() == Type_outerBoundaryIs) {
    return std::static_pointer_cast<OuterBoundaryIs>(element);
  }
  return nullptr;
}

const OverlayXYPtr AsOverlayXY(const ElementPtr element) {
  if (element && element->Type() == Type_overlayXY) {
    return std::static_pointer_cast<OverlayXY>(element);
  }
  return nullptr;
}

const PairPtr AsPair(const ElementPtr element) {
  if (element && element->Type() == Type_Pair) {
    return std::static_pointer_cast<Pair>(element);
  }
  return nullptr;
}

const PhotoOverlayPtr AsPhotoOverlay(const ElementPtr element) {
  if (element && element->Type() == Type_PhotoOverlay) {
    return std::static_pointer_cast<PhotoOverlay>(element);
  }
  return nullptr;
}

const PlacemarkPtr AsPlacemark(const ElementPtr element) {
  if (element && element->Type() == Type_Placemark) {
    return std::static_pointer_cast<Placemark>(element);
  }
  return nullptr;
}

const PointPtr AsPoint(const ElementPtr element) {
  if (element && element->Type() == Type_Point) {
    return std::static_pointer_cast<Point>(element);
  }
  return nullptr;
}

const PolyStylePtr AsPolyStyle(const ElementPtr element) {
  if (element && element->Type() == Type_PolyStyle) {
    return std::static_pointer_cast<PolyStyle>(element);
  }
  return nullptr;
}

const PolygonPtr AsPolygon(const ElementPtr element) {
  if (element && element->Type() == Type_Polygon) {
    return std::static_pointer_cast<Polygon>(element);
  }
  return nullptr;
}

const RegionPtr AsRegion(const ElementPtr element) {
  if (element && element->Type() == Type_Region) {
    return std::static_pointer_cast<Region>(element);
  }
  return nullptr;
}

const ResourceMapPtr AsResourceMap(const ElementPtr element) {
  if (element && element->Type() == Type_ResourceMap) {
    return std::static_pointer_cast<ResourceMap>(element);
  }
  return nullptr;
}

const RotationXYPtr AsRotationXY(const ElementPtr element) {
  if (element && element->Type() == Type_rotationXY) {
    return std::static_pointer_cast<RotationXY>(element);
  }
  return nullptr;
}

const ScalePtr AsScale(const ElementPtr element) {
  if (element && element->Type() == Type_Scale) {
    return std::static_pointer_cast<Scale>(element);
  }
  return nullptr;
}

const SchemaPtr AsSchema(const ElementPtr element) {
  if (element && element->Type() == Type_Schema) {
    return std::static_pointer_cast<Schema>(element);
  }
  return nullptr;
}

const SchemaDataPtr AsSchemaData(const ElementPtr element) {
  if (element && element->Type() == Type_SchemaData) {
    return std::static_pointer_cast<SchemaData>(element);
  }
  return nullptr;
}

const ScreenOverlayPtr AsScreenOverlay(const ElementPtr element) {
  if (element && element->Type() == Type_ScreenOverlay) {
    return std::static_pointer_cast<ScreenOverlay>(element);
  }
  return nullptr;
}

const ScreenXYPtr AsScreenXY(const ElementPtr element) {
  if (element && element->Type() == Type_screenXY) {
    return std::static_pointer_cast<ScreenXY>(element);
  }
  return nullptr;
}

const SizePtr AsSize(const ElementPtr element) {
  if (element && element->Type() == Type_size) {
    return std::static_pointer_cast<Size>(element);
  }
  return nullptr;
}

const SnippetPtr AsSnippet(const ElementPtr element) {
  if (element && element->Type() == Type_Snippet) {
    return std::static_pointer_cast<Snippet>(element);
  }
  return nullptr;
}

const StylePtr AsStyle(const ElementPtr element) {
  if (element && element->Type() == Type_Style) {
    return std::static_pointer_cast<Style>(element);
  }
  return nullptr;
}

const StyleMapPtr AsStyleMap(const ElementPtr element) {
  if (element && element->Type() == Type_StyleMap) {
    return std::static_pointer_cast<StyleMap>(element);
  }
  return nullptr;
}

const TimeSpanPtr AsTimeSpan(const ElementPtr element) {
  if (element && element->IsA(Type_TimeSpan)) {
    return std::static_pointer_cast<TimeSpan>(element);
  }
  return nullptr;
}

const TimeStampPtr AsTimeStamp(const ElementPtr element) {
  if (element && element->IsA(Type_TimeStamp)) {
    return std::static_pointer_cast<TimeStamp>(element);
  }
  return nullptr;
}

const UpdatePtr AsUpdate(const ElementPtr element) {
  if (element && element->Type() == Type_Update) {
    return std::static_pointer_cast<Update>(element);
  }
  return nullptr;
}

const ViewVolumePtr AsViewVolume(const ElementPtr element) {
  if (element && element->Type() == Type_ViewVolume) {
    return std::static_pointer_cast<ViewVolume>(element);
  }
  return nullptr;
}

}  // end namespace kmldom
