add_library(helloutil STATIC print.cc)
target_link_libraries(helloutil Boost::smart_ptr kmldom ${MINIZIP_LIBRARY})

build_example(
    NAME createkml
    LINKS Boost::smart_ptr kmldom
)

build_example(
    NAME circlegen
    LINKS Boost::smart_ptr kmldom kmlconvenience
)

build_example(
    NAME checklinks
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME countkml
    LINKS Boost::smart_ptr kmlengine
)

build_example(
  NAME helloattrs
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME helloenum
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME hellofeatures
  LINKS Boost::smart_ptr helloutil kmldom
)

build_example(
  NAME hellofolder
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME hellogeometry
  LINKS Boost::smart_ptr kmldom
)

build_example(
    NAME hellohref
    LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME hellokmz
  LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME helloregion
    LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME helloworld
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME parsekml
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME parsens
  LINKS Boost::smart_ptr kmldom
)

build_example(
  NAME prettykml
  LINKS Boost::smart_ptr kmlengine
)

build_example(
  NAME printgeometry
  LINKS Boost::smart_ptr kmlengine
)

build_example(
  NAME sharedstyles
  LINKS Boost::smart_ptr kmlconvenience
)

build_example(
  NAME simplifylines
  LINKS Boost::smart_ptr kmlconvenience
)

build_example(
  NAME sortplacemarks
  LINKS Boost::smart_ptr kmlconvenience
)

if(INSTALL_EXAMPLES)
file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
install(FILES ${eg_files}  DESTINATION ${KML_EXAMPLES_DIR} COMPONENT Development)
install(FILES print.h
  DESTINATION ${KML_EXAMPLES_DIR}
  COMPONENT Development)
endif()
