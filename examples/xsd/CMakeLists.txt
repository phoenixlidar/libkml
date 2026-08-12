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
        LINKS LibKML2::kmlxsd
        CATEGORY xsd
    )
endforeach (EXAMPLE "csvregionator;kmlregionator")

build_example(
    NAME xsdcoverage
    LINKS LibKML2::kmlengine LibKML2::kmlxsd
    CATEGORY xsd
)

if(INSTALL_EXAMPLES)
    install(
        FILES kml-aliases.txt
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/kml/examples/xsd
        COMPONENT Examples
    )
endif()
