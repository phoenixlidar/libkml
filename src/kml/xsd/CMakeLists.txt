set (XSD_SOURCES
    xsd_complex_type.cc
    xsd_element.cc
    xsd_file.cc
    xsd_handler.cc
    xsd_primitive_type.cc
    xsd_util.cc
    xst_parser.cc
)

set (XSD_HEADERS
    xsd_complex_type.h
    xsd_element.h
    xsd_file.h
    xsd_handler.h
    xsd_primitive_type.h
    xsd_schema.h
    xsd_simple_type.h
    xsd_type.h
    xsd_util.h
    xst_parser.h
)

add_library(kmlxsd
    ${XSD_SOURCES}
    ${XSD_HEADERS}
)

add_library (LibKML::kmlxsd ALIAS kmlxsd)

set_target_properties (kmlxsd PROPERTIES
    PUBLIC_HEADER "${XSD_HEADERS}"
    SOVERSION "${LibKML_VERSION_MAJOR}"
    VERSION   "${LibKML_VERSION}"
)
target_compile_options(kmlxsd
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmlxsd
    PUBLIC LibKML::kmlbase
)

install(TARGETS kmlxsd
    EXPORT LibKMLTargets
)

