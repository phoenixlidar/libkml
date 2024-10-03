build_example(
  NAME csvregionator
  LINKS Boost::smart_ptr kmlregionator
)

build_example(
  NAME kmlregionator
  LINKS Boost::smart_ptr kmlregionator
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(
    FILES ${eg_files}
    DESTINATION ${KML_EXAMPLES_DIR}/regionator)
endif()
