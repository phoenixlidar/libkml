build_example(
  NAME csvregionator
  LINKS kmlregionator
)

build_example(
  NAME kmlregionator
  LINKS kmlregionator
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(
    FILES ${eg_files}
    DESTINATION ${KML_EXAMPLES_DIR}/regionator)
endif()
