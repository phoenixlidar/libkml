build_example(
    NAME gpxfly
    LINKS Boost::smart_ptr kmlconvenience
)

build_example(
    NAME featuretour
    LINKS Boost::smart_ptr kmlconvenience
)


if(INSTALL_EXAMPLES)
file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
install(
  FILES ${eg_files}
  DESTINATION ${KML_EXAMPLES_DIR}/gx)
endif()
