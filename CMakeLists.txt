cmake_minimum_required (VERSION 3.14)
project(LibKML
    VERSION 1.3.1
    LANGUAGES C CXX
)

function (LKML_deprecated_option old_name new_name description default)
  if (DEFINED ${old_name})
          message (DEPRECATION "${old_name} is a deprecated option and will be ignored in the future. Use ${new_name} instead")
          set (default ${${old_name}})
  endif()

  option (${new_name} ${description} ${default})
endfunction()

if (NOT DEFINED WITH_JAVA)
  set (WITH_JAVA    OFF)
endif (NOT DEFINED WITH_JAVA)

if (NOT DEFINED WITH_PYTHON)
  set (WITH_PYTHON  OFF)
endif (NOT DEFINED WITH_PYTHON)

if (NOT DEFINED BUILD_TESTING)
  set (BUILD_TESTING OFF)
endif (NOT DEFINED BUILD_TESTING)

option (LibKML_BUILD_TESTING
  "Build testing."
  ${BUILD_TESTING}
)

LKML_deprecated_option (BUILD_EXAMPLES
  LibKML_BUILD_EXAMPLES
  "Build examples."
  OFF
)

option (BUILD_SHARED_LIBS "Build shared libs." ON)

LKML_deprecated_option (WITH_SWIG
  LibKML_WITH_SWIG
  "Build java bindings"
  OFF
)

include (CMakeDependentOption)

LKML_deprecated_option (INSTALL_EXAMPLES
  LibKML_INSTALL_EXAMPLES
  "Install examples sources and executables"
  OFF
)

cmake_dependent_option (LibKML_WITH_PYTHON
  "Build python bindings"
  ${LibKML_WITH_PYTHON} ON
  LibKML_WITH_SWIG ON
)

cmake_dependent_option (LibKML_WITH_JAVA
  "Build java bindings"
  ${LibKML_WITH_JAVA} ON
  LibKML_WITH_SWIG ON
)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "CMAKE_BUILD_TYPE is not set. setting it to 'Release'")
  set(CMAKE_BUILD_TYPE Release)
endif()

include (GNUInstallDirs)
set (KML_EXAMPLES_DIR "${CMAKE_INSTALL_DATAROOTDIR}/kml/examples")

if(NOT DEFINED BIN_INSTALL_DIR)
  set(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")
endif(NOT DEFINED BIN_INSTALL_DIR)
if(NOT DEFINED DATA_INSTALL_DIR)
  set(DATA_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/share")
endif(NOT DEFINED DATA_INSTALL_DIR)
if(NOT DEFINED INCLUDE_INSTALL_DIR)
  set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include/kml")
endif(NOT DEFINED INCLUDE_INSTALL_DIR)
if(NOT DEFINED MAN_INSTALL_DIR)
  set(MAN_INSTALL_DIR "${DATA_INSTALL_DIR}/man")
endif(NOT DEFINED MAN_INSTALL_DIR)
if(NOT DEFINED RESOURCE_INSTALL_DIR)
  set(RESOURCE_INSTALL_DIR "${DATA_INSTALL_DIR}/libkml${LibKML_VERSION_MAJOR}/resource/")
endif(NOT DEFINED RESOURCE_INSTALL_DIR)
if(NOT DEFINED LOCALE_INSTALL_DIR)
  set(LOCALE_INSTALL_DIR "${DATA_INSTALL_DIR}/locale/")
endif(NOT DEFINED LOCALE_INSTALL_DIR)
if(NOT DEFINED PKGCONFIG_INSTALL_DIR)
  set(PKGCONFIG_INSTALL_DIR "${LIB_INSTALL_DIR}/pkgconfig")
endif(NOT DEFINED PKGCONFIG_INSTALL_DIR)

if(WIN32 AND NOT CYGWIN AND NOT MINGW)
  set(DEF_INSTALL_CMAKE_DIR cmake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/cmake/libkml)
endif()

set(CMAKE_INSTALL_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")
set(LIBKML_DATA_DIR  ${CMAKE_SOURCE_DIR}/testdata CACHE PATH "Directory containing test data")

#AM_CXXFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -fno-rtti
#AM_TEST_CXXFLAGS = -Wall -Wextra -Wno-unused-parameter -Werror -fno-rtti -DGTEST_HAS_RTTI=0
if(CMAKE_COMPILER_IS_GNUCXX)
  set(TEST_FLAGS "-Wall -Wextra -Wno-unused-parameter -fno-rtti -DGTEST_HAS_RTTI=0")
else()
  if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DUNICODE /D_UNICODE")
#    set(BUILD_SHARED_LIBS OFF)
  endif()
endif()

set(INSTALL_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "install directory ")
include(cmake/LibKMLHelper.cmake)

find_package(Boost
  CONFIG
  NO_MODULE
  COMPONENTS headers
)

#FIRST use config then module mode then download
find_package(expat CONFIG REQUIRED)
find_package(ZLIB)
find_package(minizip CONFIG)

if (NOT MINIZIP_FOUND)
    include (cmake/External_MiniZip.cmake)
endif (NOT MINIZIP_FOUND)

if(NOT ZLIB_FOUND)
    include(cmake/External_ZLIB.cmake)
endif(NOT ZLIB_FOUND)

find_package(uriparser CONFIG)

if (NOT URIPARSER_FOUND)
    include (cmake/External_UriParser.cmake)
endif (NOT URIPARSER_FOUND)

if (LibKML_WITH_SWIG)
  find_package(SWIG REQUIRED)

  if (SWIG_EXECUTABLE)
    include(${SWIG_USE_FILE})
  endif (SWIG_EXECUTABLE)
endif (LibKML_WITH_SWIG)

if (WIN32)
    set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif (WIN32)

add_subdirectory(src)

if(BUILD_TESTING)
    find_package (GTest)

    if (NOT GTEST_FOUND)
        include (cmake/External_GTest.cmake)
    endif (NOT GTEST_FOUND)

    enable_testing()
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    find_package(CURL)

    if(NOT CURL_FOUND)
        include(cmake/External_Curl.cmake)
    endif(NOT CURL_FOUND)
  add_subdirectory(examples)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "")
set(CONFIG_TYPE "NOCONFIG")
else()
  string(TOUPPER ${CMAKE_BUILD_TYPE} CONFIG_TYPE)
endif()

if(NOT WIN32 OR MINGW)
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/libkml.pc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/libkml.pc" @ONLY)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libkml.pc
    DESTINATION ${PKGCONFIG_INSTALL_DIR})
endif()
 
# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var ${p}_INSTALL_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

include (CMakePackageConfigHelpers)
configure_package_config_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibKMLConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/LibKMLConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibKML
)

write_basic_package_version_file (
    LibKMLConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

install (FILES
    "${CMAKE_CURRENT_BINARY_DIR}/LibKMLConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/LibKMLConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibKML
)

install (EXPORT LibKML
    DESTINATION ${CMAKE_INSTALL_DATADIR}/LibKML/cmake
    NAMESPACE LibKML
)
