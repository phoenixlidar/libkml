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

#include "kml/dom/kml_factory.h"
#include "kml/dom/kml22.h"
#include "kml/dom/kml_ptr.h"
#include "kml/dom/kmldom.h"
#include "kml/dom/xsd.h"

namespace kmldom {

KmlFactory* KmlFactory::factory_ = nullptr;

// static
KmlFactory* KmlFactory::GetFactory() {
  if (factory_ == nullptr) {
    factory_ = new KmlFactory();
  }
  return factory_;
}

ElementPtr KmlFactory::CreateElementById(KmlDomType id) const {
  switch (id) {
  case Type_Alias: return CreateAlias();
  case Type_AtomAuthor: return CreateAtomAuthor();
  case Type_AtomCategory: return CreateAtomCategory();
  case Type_AtomContent: return CreateAtomContent();
  case Type_AtomEntry: return CreateAtomEntry();
  case Type_AtomFeed: return CreateAtomFeed();
  case Type_AtomLink: return CreateAtomLink();
  case Type_BalloonStyle: return CreateBalloonStyle();
  case Type_Camera: return CreateCamera();
  case Type_Change: return CreateChange();
  case Type_Create: return CreateCreate();
  case Type_Data: return CreateData();
  case Type_Delete: return CreateDelete();
  case Type_Document: return CreateDocument();
  case Type_ExtendedData: return CreateExtendedData();
  case Type_Folder: return CreateFolder();
  case Type_GroundOverlay: return CreateGroundOverlay();
  case Type_Icon: return CreateIcon();
  case Type_IconStyle: return CreateIconStyle();
  case Type_IconStyleIcon: return CreateIconStyleIcon();
  case Type_ImagePyramid: return CreateImagePyramid();
  case Type_ItemIcon: return CreateItemIcon();
  case Type_LabelStyle: return CreateLabelStyle();
  case Type_LatLonBox: return CreateLatLonBox();
  case Type_LatLonAltBox: return CreateLatLonAltBox();
  case Type_LinearRing: return CreateLinearRing();
  case Type_LineString: return CreateLineString();
  case Type_LineStyle: return CreateLineStyle();
  case Type_Link: return CreateLink();
  case Type_ListStyle: return CreateListStyle();
  case Type_Location: return CreateLocation();
  case Type_Lod: return CreateLod();
  case Type_LookAt: return CreateLookAt();
  case Type_Metadata: return CreateMetadata();
  case Type_Model: return CreateModel();
  case Type_MultiGeometry: return CreateMultiGeometry();
  case Type_NetworkLink: return CreateNetworkLink();
  case Type_NetworkLinkControl: return CreateNetworkLinkControl();
  case Type_Orientation: return CreateOrientation();
  case Type_Pair: return CreatePair();
  case Type_PhotoOverlay: return CreatePhotoOverlay();
  case Type_Placemark: return CreatePlacemark();
  case Type_PolyStyle: return CreatePolyStyle();
  case Type_Point: return CreatePoint();
  case Type_Polygon: return CreatePolygon();
  case Type_Region: return CreateRegion();
  case Type_ResourceMap: return CreateResourceMap();
  case Type_Scale: return CreateScale();
  case Type_Schema: return CreateSchema();
  case Type_SchemaData: return CreateSchemaData();
  case Type_ScreenOverlay: return CreateScreenOverlay();
  case Type_SimpleData: return CreateSimpleData();
  case Type_SimpleField: return CreateSimpleField();
  case Type_Snippet: return CreateSnippet();
  case Type_Style: return CreateStyle();
  case Type_StyleMap: return CreateStyleMap();
  case Type_TimeSpan: return CreateTimeSpan();
  case Type_TimeStamp: return CreateTimeStamp();
  case Type_ViewVolume: return CreateViewVolume();
  case Type_Update: return CreateUpdate();
  case Type_Url: return CreateUrl();
  case Type_coordinates: return CreateCoordinates();
  case Type_hotSpot: return CreateHotSpot();
  case Type_innerBoundaryIs: return CreateInnerBoundaryIs();
  case Type_kml: return CreateKml();
  case Type_linkSnippet: return CreateLinkSnippet();
  case Type_overlayXY: return CreateOverlayXY();
  case Type_outerBoundaryIs: return CreateOuterBoundaryIs();
  case Type_rotationXY: return CreateRotationXY();
  case Type_screenXY: return CreateScreenXY();
  case Type_size: return CreateSize();
  case Type_XalAddressDetails: return CreateXalAddressDetails();
  case Type_XalAdministrativeArea: return CreateXalAdministrativeArea();
  case Type_XalCountry: return CreateXalCountry();
  case Type_XalLocality: return CreateXalLocality();
  case Type_XalPostalCode: return CreateXalPostalCode();
  case Type_XalSubAdministrativeArea: return CreateXalSubAdministrativeArea();
  case Type_XalThoroughfare: return CreateXalThoroughfare();

  case Type_GxAnimatedUpdate: return CreateGxAnimatedUpdate();
  case Type_GxFlyTo: return CreateGxFlyTo();
  case Type_GxLatLonQuad: return CreateGxLatLonQuad();
  case Type_GxMultiTrack: return CreateGxMultiTrack();
  case Type_GxPlaylist: return CreateGxPlaylist();
  case Type_GxSimpleArrayData: return CreateGxSimpleArrayData();
  case Type_GxSimpleArrayField: return CreateGxSimpleArrayField();
  case Type_GxSoundCue: return CreateGxSoundCue();
  case Type_GxTimeSpan: return CreateGxTimeSpan();
  case Type_GxTimeStamp: return CreateGxTimeStamp();
  case Type_GxTour: return CreateGxTour();
  case Type_GxTourControl: return CreateGxTourControl();
  case Type_GxTrack: return CreateGxTrack();
  case Type_GxWait: return CreateGxWait();

  default: return nullptr;
  }
}

ElementPtr KmlFactory::CreateElementFromName(const string& element_name) const {
  return CreateElementById(
      static_cast<KmlDomType>(Xsd::GetSchema()->ElementId(element_name)));
}

FieldPtr KmlFactory::CreateFieldById(KmlDomType type_id) const {
  return std::shared_ptr<Field>(new Field(type_id));
}

AliasPtr KmlFactory::CreateAlias() const {
  return std::shared_ptr<Alias>(new Alias());
}

AtomAuthorPtr KmlFactory::CreateAtomAuthor() const {
  return std::shared_ptr<AtomAuthor>(new AtomAuthor());
}

AtomCategoryPtr KmlFactory::CreateAtomCategory() const {
  return std::shared_ptr<AtomCategory>(new AtomCategory());
}

AtomContentPtr KmlFactory::CreateAtomContent() const {
  return std::shared_ptr<AtomContent>(new AtomContent());
}

AtomEntryPtr KmlFactory::CreateAtomEntry() const {
  return std::shared_ptr<AtomEntry>(new AtomEntry());
}

AtomFeedPtr KmlFactory::CreateAtomFeed() const {
  return std::shared_ptr<AtomFeed>(new AtomFeed());
}

AtomLinkPtr KmlFactory::CreateAtomLink() const {
  return std::shared_ptr<AtomLink>(new AtomLink());
}

BalloonStylePtr KmlFactory::CreateBalloonStyle() const {
  return std::shared_ptr<BalloonStyle>(new BalloonStyle());
}

CameraPtr KmlFactory::CreateCamera() const {
  return std::shared_ptr<Camera>(new Camera());
}

ChangePtr KmlFactory::CreateChange() const {
  return std::shared_ptr<Change>(new Change());
}

CreatePtr KmlFactory::CreateCreate() const {
  return std::shared_ptr<Create>(new Create());
}

DataPtr KmlFactory::CreateData() const {
  return std::shared_ptr<Data>(new Data());
}

DeletePtr KmlFactory::CreateDelete() const {
  return std::shared_ptr<Delete>(new Delete());
}

DocumentPtr KmlFactory::CreateDocument() const {
  return std::shared_ptr<Document>(new Document());
}

ExtendedDataPtr KmlFactory::CreateExtendedData() const {
  return std::shared_ptr<ExtendedData>(new ExtendedData());
}

FolderPtr KmlFactory::CreateFolder() const {
  return std::shared_ptr<Folder>(new Folder());
}

GroundOverlayPtr KmlFactory::CreateGroundOverlay() const {
  return std::shared_ptr<GroundOverlay>(new GroundOverlay());
}

HotSpotPtr KmlFactory::CreateHotSpot() const {
  return std::shared_ptr<HotSpot>(new HotSpot());
}

IconPtr KmlFactory::CreateIcon() const {
  return std::shared_ptr<Icon>(new Icon());
}

IconStylePtr KmlFactory::CreateIconStyle() const {
  return std::shared_ptr<IconStyle>(new IconStyle());
}

IconStyleIconPtr KmlFactory::CreateIconStyleIcon() const {
  return std::shared_ptr<IconStyleIcon>(new IconStyleIcon());
}

ImagePyramidPtr KmlFactory::CreateImagePyramid() const {
  return std::shared_ptr<ImagePyramid>(new ImagePyramid());
}

InnerBoundaryIsPtr KmlFactory::CreateInnerBoundaryIs() const {
  return std::shared_ptr<InnerBoundaryIs>(new InnerBoundaryIs());
}

ItemIconPtr KmlFactory::CreateItemIcon() const {
  return std::shared_ptr<ItemIcon>(new ItemIcon());
}

KmlPtr KmlFactory::CreateKml() const {
  return std::shared_ptr<Kml>(new Kml());
}

LabelStylePtr KmlFactory::CreateLabelStyle() const {
  return std::shared_ptr<LabelStyle>(new LabelStyle());
}

LatLonBoxPtr KmlFactory::CreateLatLonBox() const {
  return std::shared_ptr<LatLonBox>(new LatLonBox());
}

LatLonAltBoxPtr KmlFactory::CreateLatLonAltBox() const {
  return std::shared_ptr<LatLonAltBox>(new LatLonAltBox());
}

LinearRingPtr KmlFactory::CreateLinearRing() const {
  return std::shared_ptr<LinearRing>(new LinearRing());
}

LineStringPtr KmlFactory::CreateLineString() const {
  return std::shared_ptr<LineString>(new LineString());
}

LineStylePtr KmlFactory::CreateLineStyle() const {
  return std::shared_ptr<LineStyle>(new LineStyle());
}

LinkPtr KmlFactory::CreateLink() const {
  return std::shared_ptr<Link>(new Link());
}

LinkSnippetPtr KmlFactory::CreateLinkSnippet() const {
  return std::shared_ptr<LinkSnippet>(new LinkSnippet());
}

ListStylePtr KmlFactory::CreateListStyle() const {
  return std::shared_ptr<ListStyle>(new ListStyle());
}

LocationPtr KmlFactory::CreateLocation() const {
  return std::shared_ptr<Location>(new Location());
}

LodPtr KmlFactory::CreateLod() const {
  return std::shared_ptr<Lod>(new Lod());
}

LookAtPtr KmlFactory::CreateLookAt() const {
  return std::shared_ptr<LookAt>(new LookAt());
}

MetadataPtr KmlFactory::CreateMetadata() const {
  return std::shared_ptr<Metadata>(new Metadata());
}

ModelPtr KmlFactory::CreateModel() const {
  return std::shared_ptr<Model>(new Model());
}

MultiGeometryPtr KmlFactory::CreateMultiGeometry() const {
  return std::shared_ptr<MultiGeometry>(new MultiGeometry());
}

NetworkLinkPtr KmlFactory::CreateNetworkLink() const {
  return std::shared_ptr<NetworkLink>(new NetworkLink());
}

NetworkLinkControlPtr KmlFactory::CreateNetworkLinkControl() const {
  return std::shared_ptr<NetworkLinkControl>(new NetworkLinkControl());
}

OrientationPtr KmlFactory::CreateOrientation() const {
  return std::shared_ptr<Orientation>(new Orientation());
}

OuterBoundaryIsPtr KmlFactory::CreateOuterBoundaryIs() const {
  return std::shared_ptr<OuterBoundaryIs>(new OuterBoundaryIs());
}

OverlayXYPtr KmlFactory::CreateOverlayXY() const {
  return std::shared_ptr<OverlayXY>(new OverlayXY());
}

PairPtr KmlFactory::CreatePair() const {
  return std::shared_ptr<Pair>(new Pair());
}

PhotoOverlayPtr KmlFactory::CreatePhotoOverlay() const {
  return std::shared_ptr<PhotoOverlay>(new PhotoOverlay());
}

PlacemarkPtr KmlFactory::CreatePlacemark() const {
  return std::shared_ptr<Placemark>(new Placemark());
}

PointPtr KmlFactory::CreatePoint() const {
  return std::shared_ptr<Point>(new Point());
}

PolygonPtr KmlFactory::CreatePolygon() const {
  return std::shared_ptr<Polygon>(new Polygon());
}

PolyStylePtr KmlFactory::CreatePolyStyle() const {
  return std::shared_ptr<PolyStyle>(new PolyStyle());
}

RegionPtr KmlFactory::CreateRegion() const {
  return std::shared_ptr<Region>(new Region());
}

ResourceMapPtr KmlFactory::CreateResourceMap() const {
  return std::shared_ptr<ResourceMap>(new ResourceMap());
}

RotationXYPtr KmlFactory::CreateRotationXY() const {
  return std::shared_ptr<RotationXY>(new RotationXY());
}

ScalePtr KmlFactory::CreateScale() const {
  return std::shared_ptr<Scale>(new Scale());
}

ScreenOverlayPtr KmlFactory::CreateScreenOverlay() const {
  return std::shared_ptr<ScreenOverlay>(new ScreenOverlay());
}

CoordinatesPtr KmlFactory::CreateCoordinates() const {
  return std::shared_ptr<Coordinates>(new Coordinates());
}

ScreenXYPtr KmlFactory::CreateScreenXY() const {
  return std::shared_ptr<ScreenXY>(new ScreenXY());
}

SchemaPtr KmlFactory::CreateSchema() const {
  return std::shared_ptr<Schema>(new Schema());
}

SchemaDataPtr KmlFactory::CreateSchemaData() const {
  return std::shared_ptr<SchemaData>(new SchemaData());
}

UpdatePtr KmlFactory::CreateUpdate() const {
  return std::shared_ptr<Update>(new Update());
}

UrlPtr KmlFactory::CreateUrl() const {
  return std::shared_ptr<Url>(new Url());
}

SimpleDataPtr KmlFactory::CreateSimpleData() const {
  return std::shared_ptr<SimpleData>(new SimpleData());
}

SimpleFieldPtr KmlFactory::CreateSimpleField() const {
  return std::shared_ptr<SimpleField>(new SimpleField());
}

SizePtr KmlFactory::CreateSize() const {
  return std::shared_ptr<Size>(new Size());
}

SnippetPtr KmlFactory::CreateSnippet() const {
  return std::shared_ptr<Snippet>(new Snippet());
}

StylePtr KmlFactory::CreateStyle() const {
  return std::shared_ptr<Style>(new Style());
}

StyleMapPtr KmlFactory::CreateStyleMap() const {
  return std::shared_ptr<StyleMap>(new StyleMap());
}

TimeSpanPtr KmlFactory::CreateTimeSpan() const {
  return std::shared_ptr<TimeSpan>(new TimeSpan());
}

TimeStampPtr KmlFactory::CreateTimeStamp() const {
  return std::shared_ptr<TimeStamp>(new TimeStamp());
}

ViewVolumePtr KmlFactory::CreateViewVolume() const {
  return std::shared_ptr<ViewVolume>(new ViewVolume());
}

XalAddressDetailsPtr KmlFactory::CreateXalAddressDetails() const {
  return std::shared_ptr<XalAddressDetails>(new XalAddressDetails());
}

XalAdministrativeAreaPtr KmlFactory::CreateXalAdministrativeArea() const {
  return std::shared_ptr<XalAdministrativeArea>(new XalAdministrativeArea());
}

XalCountryPtr KmlFactory::CreateXalCountry() const {
  return std::shared_ptr<XalCountry>(new XalCountry());
}

XalLocalityPtr KmlFactory::CreateXalLocality() const {
  return std::shared_ptr<XalLocality>(new XalLocality());
}

XalPostalCodePtr KmlFactory::CreateXalPostalCode() const {
  return std::shared_ptr<XalPostalCode>(new XalPostalCode());
}

XalSubAdministrativeAreaPtr KmlFactory::CreateXalSubAdministrativeArea() const {
  return std::shared_ptr<XalSubAdministrativeArea>(new XalSubAdministrativeArea());
}

XalThoroughfarePtr KmlFactory::CreateXalThoroughfare() const {
  return std::shared_ptr<XalThoroughfare>(new XalThoroughfare());
}

GxAnimatedUpdatePtr KmlFactory::CreateGxAnimatedUpdate() const {
  return std::shared_ptr<GxAnimatedUpdate>(new GxAnimatedUpdate());
}

GxFlyToPtr KmlFactory::CreateGxFlyTo() const {
  return std::shared_ptr<GxFlyTo>(new GxFlyTo());
}

GxLatLonQuadPtr KmlFactory::CreateGxLatLonQuad() const {
  return std::shared_ptr<GxLatLonQuad>(new GxLatLonQuad());
}

GxMultiTrackPtr KmlFactory::CreateGxMultiTrack() const {
  return std::shared_ptr<GxMultiTrack>(new GxMultiTrack());
}

GxPlaylistPtr KmlFactory::CreateGxPlaylist() const {
  return std::shared_ptr<GxPlaylist>(new GxPlaylist());
}

GxSimpleArrayDataPtr KmlFactory::CreateGxSimpleArrayData() const {
  return std::shared_ptr<GxSimpleArrayData>(new GxSimpleArrayData());
}

GxSimpleArrayFieldPtr KmlFactory::CreateGxSimpleArrayField() const {
  return std::shared_ptr<GxSimpleArrayField>(new GxSimpleArrayField());
}

GxSoundCuePtr KmlFactory::CreateGxSoundCue() const {
  return std::shared_ptr<GxSoundCue>(new GxSoundCue());
}

GxTimeSpanPtr KmlFactory::CreateGxTimeSpan() const {
  return std::shared_ptr<GxTimeSpan>(new GxTimeSpan());
}

GxTimeStampPtr KmlFactory::CreateGxTimeStamp() const {
  return std::shared_ptr<GxTimeStamp>(new GxTimeStamp());
}

GxTourPtr KmlFactory::CreateGxTour() const {
  return std::shared_ptr<GxTour>(new GxTour());
}

GxTourControlPtr KmlFactory::CreateGxTourControl() const {
  return std::shared_ptr<GxTourControl>(new GxTourControl());
}

GxTrackPtr KmlFactory::CreateGxTrack() const {
  return std::shared_ptr<GxTrack>(new GxTrack());
}

GxWaitPtr KmlFactory::CreateGxWait() const {
  return std::shared_ptr<GxWait>(new GxWait());
}

}  // namespace kmldom
