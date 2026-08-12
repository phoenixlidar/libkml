add_library(helloutil STATIC print.cc)
target_link_libraries(helloutil LibKML2::kmldom ${MINIZIP_LIBRARY})

set (DOM_EXAMPLES
    createkml
    helloattrs
    helloenum
    hellofolder
    hellogeometry
    hellohref
    helloregion
    helloworld
    parsekml
    parsens
)

set (ENGINE_EXAMPLES
    checklinks
    countkml
    hellokmz
    prettykml
    printgeometry
)

foreach (EXAMPLE ${DOM_EXAMPLES})
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML2::kmldom
        CATEGORY helloworld
    )
endforeach (EXAMPLE ${DOM_EXAMPLES})

foreach (EXAMPLE ${ENGINE_EXAMPLES})
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML2::kmlengine
        CATEGORY helloworld
    )
endforeach (EXAMPLE ${ENGINE_EXAMPLES})

build_example(
    NAME circlegen
    LINKS kmldom kmlconvenience
    CATEGORY helloworld
)

build_example(
    NAME hellofeatures
    LINKS helloutil LibKML2::kmldom
    CATEGORY helloworld
)

build_example(
    NAME sharedstyles
    LINKS LibKML2::kmlconvenience
    CATEGORY helloworld
)

build_example(
    NAME simplifylines
    LINKS LibKML2::kmlconvenience
    CATEGORY helloworld
)

build_example(
    NAME sortplacemarks
    LINKS LibKML2::kmlconvenience
    CATEGORY helloworld
)


if(INSTALL_EXAMPLES)
    install(
        FILES print.cc print.h
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/kml/examples/hellonet
        COMPONENT Examples
    )
endif()
