build_example(
  NAME csvregionator
  DEPENDS kmlbase kmldom kmlengine kmlconvenience kmlregionator
  LINKS Boost::smart_ptr
)

build_example(
  NAME kmlregionator
  DEPENDS kmlbase kmldom kmlengine kmlconvenience kmlregionator
  LINKS Boost::smart_ptr
)

if(INSTALL_EXAMPLES)
  file(GLOB eg_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
  install(
    FILES ${eg_files}
    DESTINATION ${KML_EXAMPLES_DIR}/regionator)
endif()
