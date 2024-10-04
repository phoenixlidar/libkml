set (DOM_SOURCES
    abstractlatlonbox.cc
    abstractview.cc
    atom.cc
    balloonstyle.cc
    colorstyle.cc
    container.cc
    document.cc
    element.cc
    extendeddata.cc
    feature.cc
    folder.cc
    geometry.cc
    gx_timeprimitive.cc
    gx_tour.cc
    hotspot.cc
    iconstyle.cc
    kml22.cc
    kml_cast.cc
    kml.cc
    kml_factory.cc
    kml_handler.cc
    kml_handler_ns.cc
    labelstyle.cc
    linestyle.cc
    link.cc
    liststyle.cc
    model.cc
    networklink.cc
    networklinkcontrol.cc
    object.cc
    overlay.cc
    parser.cc
    placemark.cc
    polystyle.cc
    region.cc
    schema.cc
    serializer.cc
    snippet.cc
    style.cc
    stylemap.cc
    styleselector.cc
    substyle.cc
    timeprimitive.cc
    vec2.cc
    visitor.cc
    visitor_driver.cc
    xal.cc
    xml_serializer.cc
    xsd.cc
)

set (DOM_PUBLIC_HEADERS
    abstractlatlonbox.h
    abstractview.h
    atom.h
    balloonstyle.h
    colorstyle.h
    container.h
    document.h
    element.h
    extendeddata.h
    feature.h
    folder.h
    geometry.h
    gx_timeprimitive.h
    gx_tour.h
    hotspot.h
    iconstyle.h
    kml.h
    kml_ptr.h
    kml22.h
    kmldom.h
    labelstyle.h
    linestyle.h
    link.h
    liststyle.h
    model.h
    networklink.h
    networklinkcontrol.h
    object.h
    overlay.h
    placemark.h
    polystyle.h
    region.h
    schema.h
    snippet.h
    style.h
    stylemap.h
    styleselector.h
    substyle.h
    timeprimitive.h
    vec2.h
    visitor.h
    visitor_driver.h
    xal.h
)

set(DOM_PRIVATE_HEADERS
    kml_cast.h
    kml_factory.h
    kml_funcs.h
    parser.h
    parser_observer.h
    xml_serializer.h
    xsd.h
)

add_library(kmldom
    ${DOM_SOURCES}
    ${DOM_PRIVATE_HEADERS}
    ${DOM_PUBLIC_HEADERS}
)

add_library (LibKML::kmldom ALIAS kmldom)

set_target_properties (kmldom PROPERTIES
    PRIVATE_HEADER "${DOM_PRIVATER_HEADERS}"
    PUBLIC_HEADER "${DOM_PUBLIC_HEADERS}"
)

target_compile_options(kmldom
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmldom
    PUBLIC LibKML::kmlbase
)

install(TARGETS kmldom
    EXPORT LibKMLTargets
)
