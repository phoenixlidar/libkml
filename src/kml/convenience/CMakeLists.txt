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

set (CONVENIENCE_PRIVATE_HEADERS
    atom_util.h
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

set (CONVENIENCE_PUBLIC_HEADERS
    convenience.h
)

add_library(kmlconvenience
    ${CONVENIENCE_SOURCES}
    ${CONVENIENCE_PRIVATE_HEADERS}
    ${CONVENIENCE_PUBLIC_HEADERS}
)

set_target_properties (kmlbase PROPERTIES
    PRIVATE_HEADER "${CONVENIENCE_PRIVATER_HEADERS}"
    PUBLIC_HEADER "${CONVENIENCE_PUBLIC_HEADERS}"
)

target_compile_options(kmlconvenience
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmlconvenience
    PUBLIC kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
)
