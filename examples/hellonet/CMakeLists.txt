add_library(curlfetch STATIC curlfetch.cc)

target_link_libraries(curlfetch
    PUBLIC CURL::libcurl
    PRIVATE kmlconvenience
)

build_example(
    NAME csvurl2gmap
    LINKS kmlconvenience curlfetch
)

build_example(
    NAME getgmapkml
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME getgsheetcsv
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME getgsheetkml
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME gsheet2gmap
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME kmlwalk
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME kmzfetch
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME listfeed
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME listgdocs
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME listgmaps
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME listgphotos
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME resolvestyle
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME searchgmap
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME uploadgmap
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME uploadgmapcsv
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME uploadgmapkml
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME uploadgsheet
    LINKS curlfetch kmlconvenience
)

build_example(
    NAME xsdprint
    LINKS curlfetch kmlxsd
)

if(INSTALL_EXAMPLES)
file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
install(
  FILES ${eg_files}
  DESTINATION ${KML_EXAMPLES_DIR}/hellonet)

install(
  FILES README curlfetch.h prompt.h
  DESTINATION ${KML_EXAMPLES_DIR}/hellonet)
endif()
