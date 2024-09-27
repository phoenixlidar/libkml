build_example(
    NAME gpxfly
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)

build_example(
    NAME featuretour
    DEPENDS kmlconvenience
    LINKS Boost::smart_ptr
)


if(INSTALL_EXAMPLES)
file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
install(
  FILES ${eg_files}
  DESTINATION ${KML_EXAMPLES_DIR}/gx)
endif()
