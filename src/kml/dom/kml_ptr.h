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

#include <memory>

namespace kmldom {
inline namespace v2 {

class Element;
class Field;

class AbstractLatLonBox;
class AbstractLink;
class AbstractView;
class BasicLink;
class ColorStyle;
class Container;
class Feature;
class Geometry;
class Object;
class Overlay;
class StyleSelector;
class SubStyle;
class TimePrimitive;
class Vec2;

class Alias;
class AtomAuthor;
class AtomCategory;
class AtomContent;
class AtomEntry;
class AtomFeed;
class AtomLink;
class BalloonStyle;
class Camera;
class Change;
class Coordinates;
class Create;
class Data;
class Delete;
class Document;
class ExtendedData;
class Folder;
class GroundOverlay;
class Icon;
class IconStyle;
class IconStyleIcon;
class ImagePyramid;
class ItemIcon;
class LabelStyle;
class LatLonAltBox;
class LatLonBox;
class LineString;
class LineStyle;
class LinearRing;
class Link;
class ListStyle;
class Location;
class Lod;
class LookAt;
class Metadata;
class Model;
class MultiGeometry;
class NetworkLink;
class NetworkLinkControl;
class Orientation;
class Pair;
class PhotoOverlay;
class Placemark;
class Point;
class PolyStyle;
class Polygon;
class Region;
class ResourceMap;
class Scale;
class Schema;
class SchemaData;
class ScreenOverlay;
class SimpleData;
class SimpleField;
class Snippet;
class Style;
class StyleMap;
class TimeSpan;
class TimeStamp;
class Update;
class UpdateOperation;
class Url;
class ViewVolume;
class HotSpot;
class InnerBoundaryIs;
class Kml;
class LinkSnippet;
class OuterBoundaryIs;
class OverlayXY;
class RotationXY;
class ScreenXY;
class Size;

class XalAddressDetails;
class XalAdministrativeArea;
class XalCountry;
class XalLocality;
class XalPostalCode;
class XalSubAdministrativeArea;
class XalThoroughfare;

class GxAnimatedUpdate;
class GxFlyTo;
class GxLatLonQuad;
class GxMultiTrack;
class GxPlaylist;
class GxSimpleArrayField;
class GxSimpleArrayData;
class GxSoundCue;
class GxTimeSpan;
class GxTimeStamp;
class GxTimePrimitive;
class GxTour;
class GxTourControl;
class GxTourPrimitive;
class GxTrack;
class GxWait;

using ElementPtr = std::shared_ptr<Element>;
using FieldPtr = std::shared_ptr<Field>;

using AbstractLatLonBoxPtr = std::shared_ptr<AbstractLatLonBox>;
using AbstractLinkPtr = std::shared_ptr<AbstractLink>;
using AbstractViewPtr = std::shared_ptr<AbstractView>;
using BasicLinkPtr = std::shared_ptr<BasicLink>;
using ColorStylePtr = std::shared_ptr<ColorStyle>;
using ContainerPtr = std::shared_ptr<Container>;
using FeaturePtr = std::shared_ptr<Feature>;
using GeometryPtr = std::shared_ptr<Geometry>;
using ObjectPtr = std::shared_ptr<Object>;
using OverlayPtr = std::shared_ptr<Overlay>;
using StyleSelectorPtr = std::shared_ptr<StyleSelector>;
using SubStylePtr = std::shared_ptr<SubStyle>;
using TimePrimitivePtr = std::shared_ptr<TimePrimitive>;
using Vec2Ptr = std::shared_ptr<Vec2>;

using AliasPtr = std::shared_ptr<Alias>;
using AtomAuthorPtr = std::shared_ptr<AtomAuthor>;
using AtomCategoryPtr = std::shared_ptr<AtomCategory>;
using AtomContentPtr = std::shared_ptr<AtomContent>;
using AtomEntryPtr = std::shared_ptr<AtomEntry>;
using AtomFeedPtr = std::shared_ptr<AtomFeed>;
using AtomLinkPtr = std::shared_ptr<AtomLink>;
using BalloonStylePtr = std::shared_ptr<BalloonStyle>;
using CameraPtr = std::shared_ptr<Camera>;
using ChangePtr = std::shared_ptr<Change>;
using CoordinatesPtr = std::shared_ptr<Coordinates>;
using CreatePtr = std::shared_ptr<Create>;
using DataPtr = std::shared_ptr<Data>;
using DeletePtr = std::shared_ptr<Delete>;
using DocumentPtr = std::shared_ptr<Document>;
using ExtendedDataPtr = std::shared_ptr<ExtendedData>;
using FolderPtr = std::shared_ptr<Folder>;
using GroundOverlayPtr = std::shared_ptr<GroundOverlay>;
using IconPtr = std::shared_ptr<Icon>;
using IconStylePtr = std::shared_ptr<IconStyle>;
using IconStyleIconPtr = std::shared_ptr<IconStyleIcon>;
using ImagePyramidPtr = std::shared_ptr<ImagePyramid>;
using ItemIconPtr = std::shared_ptr<ItemIcon>;
using LabelStylePtr = std::shared_ptr<LabelStyle>;
using LatLonAltBoxPtr = std::shared_ptr<LatLonAltBox>;
using LatLonBoxPtr = std::shared_ptr<LatLonBox>;
using LineStringPtr = std::shared_ptr<LineString>;
using LineStylePtr = std::shared_ptr<LineStyle>;
using LinearRingPtr = std::shared_ptr<LinearRing>;
using LinkPtr = std::shared_ptr<Link>;
using ListStylePtr = std::shared_ptr<ListStyle>;
using LocationPtr = std::shared_ptr<Location>;
using LodPtr = std::shared_ptr<Lod>;
using LookAtPtr = std::shared_ptr<LookAt>;
using MetadataPtr = std::shared_ptr<Metadata>;
using ModelPtr = std::shared_ptr<Model>;
using MultiGeometryPtr = std::shared_ptr<MultiGeometry>;
using NetworkLinkPtr = std::shared_ptr<NetworkLink>;
using NetworkLinkControlPtr = std::shared_ptr<NetworkLinkControl>;
using OrientationPtr = std::shared_ptr<Orientation>;
using PairPtr = std::shared_ptr<Pair>;
using PhotoOverlayPtr = std::shared_ptr<PhotoOverlay>;
using PlacemarkPtr = std::shared_ptr<Placemark>;
using PointPtr = std::shared_ptr<Point>;
using PolyStylePtr = std::shared_ptr<PolyStyle>;
using PolygonPtr = std::shared_ptr<Polygon>;
using RegionPtr = std::shared_ptr<Region>;
using ResourceMapPtr = std::shared_ptr<ResourceMap>;
using ScalePtr = std::shared_ptr<Scale>;
using SchemaPtr = std::shared_ptr<Schema>;
using SchemaDataPtr = std::shared_ptr<SchemaData>;
using ScreenOverlayPtr = std::shared_ptr<ScreenOverlay>;
using SimpleDataPtr = std::shared_ptr<SimpleData>;
using SimpleFieldPtr = std::shared_ptr<SimpleField>;
using SnippetPtr = std::shared_ptr<Snippet>;
using StylePtr = std::shared_ptr<Style>;
using StyleMapPtr = std::shared_ptr<StyleMap>;
using TimeSpanPtr = std::shared_ptr<TimeSpan>;
using TimeStampPtr = std::shared_ptr<TimeStamp>;
using UpdatePtr = std::shared_ptr<Update>;
using UpdateOperationPtr = std::shared_ptr<UpdateOperation>;
using UrlPtr = std::shared_ptr<Url>;
using ViewVolumePtr = std::shared_ptr<ViewVolume>;
using HotSpotPtr = std::shared_ptr<HotSpot>;
using InnerBoundaryIsPtr = std::shared_ptr<InnerBoundaryIs>;
using KmlPtr = std::shared_ptr<Kml>;
using LinkSnippetPtr = std::shared_ptr<LinkSnippet>;
using OuterBoundaryIsPtr = std::shared_ptr<OuterBoundaryIs>;
using OverlayXYPtr = std::shared_ptr<OverlayXY>;
using RotationXYPtr = std::shared_ptr<RotationXY>;
using ScreenXYPtr = std::shared_ptr<ScreenXY>;
using SizePtr = std::shared_ptr<Size>;

using XalAddressDetailsPtr = std::shared_ptr<XalAddressDetails>;
using XalAdministrativeAreaPtr = std::shared_ptr<XalAdministrativeArea>;
using XalCountryPtr = std::shared_ptr<XalCountry>;
using XalLocalityPtr = std::shared_ptr<XalLocality>;
using XalPostalCodePtr = std::shared_ptr<XalPostalCode>;
using XalSubAdministrativeAreaPtr = std::shared_ptr<XalSubAdministrativeArea>;
using XalThoroughfarePtr = std::shared_ptr<XalThoroughfare>;

using GxAnimatedUpdatePtr = std::shared_ptr<GxAnimatedUpdate>;
using GxFlyToPtr = std::shared_ptr<GxFlyTo>;
using GxLatLonQuadPtr = std::shared_ptr<GxLatLonQuad>;
using GxMultiTrackPtr = std::shared_ptr<GxMultiTrack>;
using GxPlaylistPtr = std::shared_ptr<GxPlaylist>;
using GxSimpleArrayFieldPtr = std::shared_ptr<GxSimpleArrayField>;
using GxSimpleArrayDataPtr = std::shared_ptr<GxSimpleArrayData>;
using GxSoundCuePtr = std::shared_ptr<GxSoundCue>;
using GxTimeSpanPtr = std::shared_ptr<GxTimeSpan>;
using GxTimeStampPtr = std::shared_ptr<GxTimeStamp>;
using GxTourPtr = std::shared_ptr<GxTour>;
using GxTourControlPtr = std::shared_ptr<GxTourControl>;
using GxTourPrimitivePtr = std::shared_ptr<GxTourPrimitive>;
using GxTrackPtr = std::shared_ptr<GxTrack>;
using GxWaitPtr = std::shared_ptr<GxWait>;

}  // end inline namespace v2
}  // end namespace kmldom

