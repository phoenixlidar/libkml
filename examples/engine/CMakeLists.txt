build_example(
    NAME balloonwalker
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME clone
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME csv2kml
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME csvinfo
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME import
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME inlinestyles
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
   NAME kmlfile
   DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME kml2kmz
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME kmzchecklinks
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME oldschema
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME parsebig
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME printstyle
    DEPENDS kmlengine
    LINKS Boost::smart_ptr
)

build_example(
    NAME change
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME splitstyles
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME streamkml
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(FILES ${eg_files}  DESTINATION ${KML_EXAMPLES_DIR}/engine)
endif(INSTALL_EXAMPLES)
