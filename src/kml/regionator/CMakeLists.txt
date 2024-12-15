set(REGIONATOR_SOURCES
    feature_list_region_handler.cc
    regionator.cc
    regionator_util.cc
)

set (REGIONATOR_HEADERS
    feature_list_regionator.h
    feature_list_region_handler.h
    region_handler.h
    regionator.h
    regionator_qid.h
    regionator_util.h
)

add_library(kmlregionator
    ${REGIONATOR_SOURCES}
    ${REGIONATOR_HEADERS}
)

add_library (LibKML::kmlregionator ALIAS kmlregionator)

set_target_properties (kmlregionator PROPERTIES
    PUBLIC_HEADER "${REGIONATOR_HEADERS}"
    SOVERSION "${LibKML_VERSION_MAJOR}"
    VERSION   "${LibKML_VERSION}"
)

target_compile_options(kmlregionator
    PRIVATE -Wall
    PRIVATE $<$<NOT:$<BOOL:${MSVC}>>:-Wextra -Wno-unused-parameter -pedantic>
)

target_link_libraries (kmlregionator
    PUBLIC LibKML::kmlengine
    PUBLIC LibKML::kmlconvenience
)

install(TARGETS kmlregionator
    EXPORT LibKML
    LIBRARY
        COMPONENT Runtime
    PUBLIC_HEADER
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/kml/regionator/"
)
