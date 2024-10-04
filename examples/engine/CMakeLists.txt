build_example(
    NAME balloonwalker
    LINKS kmlengine
)

build_example(
    NAME clone
    LINKS kmlengine
)

build_example(
    NAME csv2kml
    LINKS kmlconvenience
)

build_example(
    NAME csvinfo
    LINKS kmlconvenience
)

build_example(
    NAME import
    LINKS kmlengine
)

build_example(
    NAME inlinestyles
    LINKS kmlengine
)

build_example(
    NAME kmlfile
    LINKS kmlengine
)

build_example(
    NAME kml2kmz
    LINKS kmlengine
)

build_example(
    NAME kmzchecklinks
    LINKS kmlengine
)

build_example(
    NAME oldschema
    LINKS kmlengine
)

build_example(
    NAME parsebig
    LINKS kmlengine
)

build_example(
    NAME printstyle
    LINKS kmlengine
)

build_example(
    NAME change
    LINKS kmlconvenience
)

build_example(
    NAME splitstyles
    LINKS kmlconvenience
)

build_example(
    NAME streamkml
    LINKS kmlconvenience
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(FILES ${eg_files}  DESTINATION ${KML_EXAMPLES_DIR}/engine)
endif(INSTALL_EXAMPLES)
