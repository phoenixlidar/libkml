set (CONVENIENCE_SOURCES
    atom_util.cc
    convenience.cc
    csv_file.cc
    csv_parser.cc
    feature_list.cc
    google_doc_list.cc
    google_maps_data.cc
    google_picasa_web.cc
    google_spreadsheets.cc
    http_client.cc
    kmz_check_links.cc
)

set (CONVENIENCE_HEADERS
    atom_util.h
    convenience.h
    csv_file.h
    csv_parser.h
    element_counter.h
    feature_list.h
    google_doc_list.h
    google_maps_data.h
    google_picasa_web.h
    google_spreadsheets.h
    gpx_trk_pt_handler.h
    http_client.h
    kml_feature_list_saver.h
    kmz_check_links.h
)

add_library(kmlconvenience SHARED
    ${CONVENIENCE_SOURCES}
    ${CONVENIENCE_HEADERS}
)

add_library (LibKML2::kmlconvenience ALIAS kmlconvenience)

set_target_properties (kmlconvenience PROPERTIES
    PUBLIC_HEADER "${CONVENIENCE_HEADERS}"
    OUTPUT_NAME "kmlconvenience-2.0"
    SOVERSION "${LibKML_VERSION_MAJOR}"
    VERSION   "${LibKML_VERSION}"
)

target_compile_options(kmlconvenience
    PRIVATE -Wall
    PRIVATE $<$<NOT:$<BOOL:${MSVC}>>:-Wextra -Wno-unused-parameter -pedantic>
)

target_link_libraries (kmlconvenience
    PUBLIC LibKML2::kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKML2
    LIBRARY
        COMPONENT Runtime
    PUBLIC_HEADER
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/kml2/convenience/"
)
