set (XSD_EXAMPLES
    xsdchildren
    xsdelements
    xsdenums
    xsdfind
    xsdtypes
)

foreach (EXAMPLE ${XSD_EXAMPLES})
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML::kmlxsd
        CATEGORY xsd
    )
endforeach (EXAMPLE "csvregionator;kmlregionator")

build_example(
    NAME xsdcoverage
    LINKS LibKML::kmlengine LibKML::kmlxsd
    CATEGORY xsd
)

if(INSTALL_EXAMPLES)
    install(
        FILES kml-aliases.txt
        DESTINATION ${KML_EXAMPLES_DIR}/xsd
        COMPONENT Examples
    )
endif()
