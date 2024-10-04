set(REGIONATOR_SOURCES
    feature_list_region_handler.cc
    regionator.cc
    regionator_util.cc
)

set (REGIONATOR_PUBLIC_HEADERS
    region_handler.h
    regionator.h
    regionator_qid.h
)

set (REGIONATOR_PRIVATE_HEADERS
    feature_list_regionator.h
    feature_list_region_handler.h
    regionator_util.h
)

add_library(kmlregionator
    ${REGIONATOR_SOURCES}
    ${REGIONATOR_PRIVATE_HEADERS}
    ${REGIONATOR_PUBLIC_HEADERS}
)

add_library (LibKML::kmlregionator ALIAS kmlregionator)

set_target_properties (kmlregionator PROPERTIES
    PRIVATE_HEADER "${REGIONATOR_PRIVATER_HEADERS}"
    PUBLIC_HEADER "${REGIONATOR_PUBLIC_HEADERS}"
)

target_compile_options(kmlregionator
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmlregionator
    PUBLIC LibKML::kmlengine
    PUBLIC LibKML::kmlconvenience
)

install(TARGETS kmlregionator
    EXPORT LibKMLTargets
)

