build_example(
    NAME balloonwalker
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME clone
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME csv2kml
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME csvinfo
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME import
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME inlinestyles
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME kmlfile
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME kml2kmz
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME kmzchecklinks
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME oldschema
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME parsebig
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME printstyle
    LINKS Boost::smart_ptr kmlengine
)

build_example(
    NAME change
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME splitstyles
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME streamkml
    LINKS Boost::smart_ptr kmlconvenience
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(FILES ${eg_files}  DESTINATION ${KML_EXAMPLES_DIR}/engine)
endif(INSTALL_EXAMPLES)
