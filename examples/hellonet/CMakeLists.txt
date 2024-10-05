add_library(curlfetch STATIC curlfetch.cc)

target_link_libraries(curlfetch
    PUBLIC CURL::libcurl
    PRIVATE LibKML::kmlconvenience
)

set (EXAMPLES
    csvurl2gmap
    getgmapkml
    getgsheetcsv
    getgsheetkml
    gsheet2gmap
    kmlwalk
    kmzfetch
    listfeed
    listgdocs
    listgmaps
    listgphotos
    resolvestyle
    searchgmap
    uploadgmap
    uploadgmapcsv
    uploadgmapkml
    uploadgsheet
)

foreach (EXAMPLE ${EXAMPLES})
    build_example(
        NAME ${EXAMPLE}
        LINKS curlfetch LibKML::kmlconvenience
        CATEGORY hellonet
    )
endforeach (EXAMPLE ${EXAMPLES})

build_example(
    NAME xsdprint
    LINKS curlfetch LibKML::kmlxsd
    CATEGORY hellonet
)

if(INSTALL_EXAMPLES)
    install(
        FILES README curlfetch.cc curlfetch.h prompt.h
        DESTINATION ${KML_EXAMPLES_DIR}/hellonet
        COMPONENT Examples
    )
endif()
