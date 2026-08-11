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

#include <string>
#include "kml/dom/kmldom.h"
#include "kml/base/util.h"

namespace kmldom {

// A singleton factory class.
class KmlFactory {
 public:
  static KmlFactory* GetFactory();

  // Factory functions used by the parser to create any KML element.
  ElementPtr CreateElementById(KmlDomType id) const;
  ElementPtr CreateElementFromName(const string& element_name) const;
  FieldPtr CreateFieldById(KmlDomType type_id) const;

  // Factory functions to create all KML complex elements.
  AliasPtr CreateAlias() const;
  AtomAuthorPtr CreateAtomAuthor() const;
  AtomCategoryPtr CreateAtomCategory() const;
  AtomContentPtr CreateAtomContent() const;
  AtomEntryPtr CreateAtomEntry() const;
  AtomFeedPtr CreateAtomFeed() const;
  AtomLinkPtr CreateAtomLink() const;
  BalloonStylePtr CreateBalloonStyle() const;
  CoordinatesPtr CreateCoordinates() const;
  CameraPtr CreateCamera() const;
  ChangePtr CreateChange() const;
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
  MetadataPtr CreateMetadata() const;
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
  UrlPtr CreateUrl() const;
  XalAddressDetailsPtr CreateXalAddressDetails() const;
  XalAdministrativeAreaPtr CreateXalAdministrativeArea() const;
  XalCountryPtr CreateXalCountry() const;
  XalLocalityPtr CreateXalLocality() const;
  XalPostalCodePtr CreateXalPostalCode() const;
  XalSubAdministrativeAreaPtr CreateXalSubAdministrativeArea() const;
  XalThoroughfarePtr CreateXalThoroughfare() const;

  // These methods create the elements in the Google extensions to KML 2.2.
  GxAnimatedUpdatePtr CreateGxAnimatedUpdate() const;
  GxFlyToPtr CreateGxFlyTo() const;
  GxLatLonQuadPtr CreateGxLatLonQuad() const;
  GxMultiTrackPtr CreateGxMultiTrack() const;
  GxPlaylistPtr CreateGxPlaylist() const;
  GxSimpleArrayDataPtr CreateGxSimpleArrayData() const;
  GxSimpleArrayFieldPtr CreateGxSimpleArrayField() const;
  GxSoundCuePtr CreateGxSoundCue() const;
  GxTimeSpanPtr CreateGxTimeSpan() const;
  GxTimeStampPtr CreateGxTimeStamp() const;
  GxTourPtr CreateGxTour() const;
  GxTourControlPtr CreateGxTourControl() const;
  GxTrackPtr CreateGxTrack() const;
  GxWaitPtr CreateGxWait() const;

 private:
  KmlFactory() {}  // Singleton class, use GetFactory().
  KmlFactory(const KmlFactory&) = delete;
  KmlFactory& operator=(const KmlFactory&) = delete;
};

}  // namespace kmldom

