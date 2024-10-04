set (ENGINE_SOURCES
    clone.cc
    entity_mapper.cc
    feature_balloon.cc
    feature_view.cc
    feature_visitor.cc
    find.cc
    find_xml_namespaces.cc
    get_link_parents.cc
    get_link_parents.h
    get_links.cc
    href.cc
    id_mapper.cc
    kml_cache.cc
    kml_file.cc
    kml_stream.cc
    kml_uri.cc
    kmz_cache.cc
    kmz_file.cc
    link_util.cc
    location_util.cc
    merge.cc
    parse_old_schema.cc
    style_inliner.cc
    style_merger.cc
    style_resolver.cc
    style_splitter.cc
    update.cc
    update_processor.cc
)

set (ENGINE_HEADERS
    bbox.h
    clone.h
    engine_constants.h
    engine_types.h
    entity_mapper.h
    feature_balloon.h
    feature_view.h
    feature_visitor.h
    find.h
    find_xml_namespaces.h
    get_links.h
    href.h
    id_mapper.h
    id_mapper_internal.h
    kml_cache.h
    kml_file.h
    kml_stream.h
    kml_uri.h
    kml_uri_internal.h
    kmz_cache.h
    kmz_file.h
    link_util.h
    location_util.h
    merge.h
    object_id_parser_observer.h
    old_schema_parser_observer.h
    parse_old_schema.h
    schema_parser_observer.h
    shared_style_parser_observer.h
    style_inliner.h
    style_inliner_internal.h
    style_merger.h
    style_resolver.h
    style_splitter.h
    style_splitter_internal.h
    update.h
    update_processor.h
)

add_library(kmlengine
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
)

add_library (LibKML::kmlengine ALIAS kmlengine)

set_target_properties (kmlengine PROPERTIES
    PUBLIC_HEADER "${ENGINE_HEADERS}"
)

target_compile_options(kmlengine
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmlengine
    PUBLIC LibKML::kmldom
)

install(TARGETS kmlengine
    EXPORT LibKMLTargets
)

