add_library(curlfetch STATIC curlfetch.cc)
target_link_libraries(curlfetch
    PRIVATE CURL::libcurl
    PRIVATE Boost::smart_ptr
)

build_example(
    NAME csvurl2gmap
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME getgmapkml
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME getgsheetcsv
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME getgsheetkml
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME gsheet2gmap
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME kmlwalk
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME kmzfetch
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME listfeed
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME listgdocs
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME listgmaps
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME listgphotos
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME resolvestyle
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME searchgmap
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME uploadgmap
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME uploadgmapcsv
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME uploadgmapkml
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME uploadgsheet
    DEPENDS curlfetch kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME xsdprint
    DEPENDS curlfetch kmlconvenience kmlxsd
    LINKS Boost::smart_ptr
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
