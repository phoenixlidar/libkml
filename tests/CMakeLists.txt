include_directories(${CMAKE_SOURCE_DIR}/tests)
add_definitions("-DDATADIR=\"${LIBKML_DATA_DIR}\"")

add_subdirectory(kml)
if(WITH_SWIG)
  add_subdirectory(swig)
endif()
