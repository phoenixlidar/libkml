add_library(helloutil STATIC print.cc)
target_link_libraries(helloutil kmldom ${MINIZIP_LIBRARY})

build_example(
    NAME createkml
    LINKS kmldom
)

build_example(
    NAME circlegen
    LINKS kmldom kmlconvenience
)

build_example(
    NAME checklinks
    LINKS kmlengine
)

build_example(
    NAME countkml
    LINKS kmlengine
)

build_example(
  NAME helloattrs
  LINKS kmldom
)

build_example(
  NAME helloenum
  LINKS kmldom
)

build_example(
  NAME hellofeatures
  LINKS helloutil kmldom
)

build_example(
  NAME hellofolder
  LINKS kmldom
)

build_example(
  NAME hellogeometry
  LINKS kmldom
)

build_example(
    NAME hellohref
    LINKS kmldom
)

build_example(
  NAME hellokmz
  LINKS kmlengine
)

build_example(
    NAME helloregion
    LINKS kmldom
)

build_example(
  NAME helloworld
  LINKS kmldom
)

build_example(
  NAME parsekml
  LINKS kmldom
)

build_example(
  NAME parsens
  LINKS kmldom
)

build_example(
  NAME prettykml
  LINKS kmlengine
)

build_example(
  NAME printgeometry
  LINKS kmlengine
)

build_example(
  NAME sharedstyles
  LINKS kmlconvenience
)

build_example(
  NAME simplifylines
  LINKS kmlconvenience
)

build_example(
  NAME sortplacemarks
  LINKS kmlconvenience
)

if(INSTALL_EXAMPLES)
file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
install(FILES ${eg_files}  DESTINATION ${KML_EXAMPLES_DIR} COMPONENT Development)
install(FILES print.h
  DESTINATION ${KML_EXAMPLES_DIR}
  COMPONENT Development)
endif()
