add_library(curlfetch STATIC curlfetch.cc)

target_link_libraries(curlfetch
    PUBLIC CURL::libcurl
    PRIVATE kmlconvenience
    PRIVATE Boost::smart_ptr
)

build_example(
    NAME csvurl2gmap
    LINKS Boost::smart_ptr kmlconvenience curlfetch
)

build_example(
    NAME getgmapkml
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME getgsheetcsv
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME getgsheetkml
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME gsheet2gmap
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME kmlwalk
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME kmzfetch
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME listfeed
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME listgdocs
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME listgmaps
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME listgphotos
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME resolvestyle
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME searchgmap
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME uploadgmap
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME uploadgmapcsv
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME uploadgmapkml
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME uploadgsheet
    LINKS Boost::smart_ptr curlfetch kmlconvenience
)

build_example(
    NAME xsdprint
    LINKS Boost::smart_ptr curlfetch kmlxsd
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
