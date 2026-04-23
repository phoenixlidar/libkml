set (EXAMPLES_ENGINE
    balloonwalker
    clone
    import
    inlinestyles
    kmlfile
    kml2kmz
    kmzchecklinks
    oldschema
    parsebig
    printstyle
)

set (EXAMPLES_CONVENIENCE
    csv2kml
    csvinfo
    change
    splitstyles
    streamkml
)

foreach (EXAMPLE ${EXAMPLES_ENGINE})
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML::kmlengine
        CATEGORY engine
    )
endforeach (EXAMPLE ${EXAMPLES_ENGINE})

foreach (EXAMPLE ${EXAMPLES_CONVENIENCE})
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML::kmlconvenience
        CATEGORY engine
    )
endforeach (EXAMPLE ${EXAMPLES_CONVENIENCE})
