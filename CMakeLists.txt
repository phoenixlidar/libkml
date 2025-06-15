cmake_minimum_required (VERSION 3.14)
project (LibKML
    VERSION 1.3.1
    LANGUAGES C CXX
)

set (CMAKE_CXX_STANDARD 11)

include (CheckSymbolExists)
include (CMakeDependentOption)
include (CMakePackageConfigHelpers)
include (GNUInstallDirs)
include (cmake/LibKMLHelper.cmake)

function (LKML_deprecated_option old_name new_name description default)
  if (DEFINED ${old_name})
    message (DEPRECATION
        "${old_name} is a deprecated option and will be ignored in the future.
        Use ${new_name} instead"
    )

    set (default ${${old_name}})
  endif()

  option (${new_name} ${description} ${default})
endfunction (LKML_deprecated_option old_name new_name description default)

if (NOT DEFINED LibKML_BUILD_TESTING)
    if (NOT DEFINED BUILD_TESTING)
        set (BUILD_TESTING OFF)
        set (BUILD_TESTING_DEFAULT OFF)
    else (NOT DEFINED BUILD_TESTING)
        set (BUILD_TESTING_DEFAULT ${BUILD_TESTING})
    endif (NOT DEFINED BUILD_TESTING)
else (NOT DEFINED LibKML_BUILD_TESTING)
    set (BUILD_TESTING_DEFAULT ${LibKML_BUILD_TESTING})
endif (NOT DEFINED LibKML_BUILD_TESTING)

option (LibKML_BUILD_TESTING
    "Build testing."
    ${BUILD_TESTING_DEFAULT}
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
    message (STATUS "CMAKE_BUILD_TYPE is not set. setting it to 'Release'")
    set (CMAKE_BUILD_TYPE Release CACHE STRING "What type of lib we're building")
endif (NOT CMAKE_BUILD_TYPE)

set (KML_EXAMPLES_DIR "${CMAKE_INSTALL_DATAROOTDIR}/kml/examples")
set(LIBKML_DATA_DIR  ${LibKML_SOURCE_DIR}/testdata CACHE PATH "Directory containing test data")

#This are needed because clang on Mingw set's it
check_symbol_exists(_WIN32 stdlib.h IS_WIN)
#This is needed because clang env of MinGW isn't recognized as MINGW
check_symbol_exists(__MINGW32__ stdlib.h IS_MINGW)

find_package (Boost
    CONFIG
    NO_MODULE
    COMPONENTS headers
    REQUIRED
)

find_package (expat CONFIG REQUIRED)

find_package (minizip
  CONFIG
  REQUIRED
  NAMES minizip;minizip-ng
)

if (minizip_VERSION VERSION_LESS "4")
       set(ORIG_MINIZIP TRUE)
endif (minizip_VERSION VERSION_LESS "4")

if (NOT TARGET ZLIB::ZLIB)
  find_package (ZLIB REQUIRED)
endif (NOT TARGET ZLIB::ZLIB)

find_package (uriparser CONFIG REQUIRED)

if (LibKML_WITH_SWIG)
  find_package(SWIG REQUIRED)

  if (SWIG_EXECUTABLE)
    include (${SWIG_USE_FILE})
  endif (SWIG_EXECUTABLE)
endif (LibKML_WITH_SWIG)

if (WIN32)
    set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif (WIN32)

add_subdirectory (src)

if (LibKML_BUILD_TESTING)
    find_package (GTest REQUIRED)
    enable_testing()
    add_subdirectory (tests)
endif (LibKML_BUILD_TESTING)

if (LibKML_BUILD_EXAMPLES)
    find_package (CURL)
    add_subdirectory (examples)
endif (LibKML_BUILD_EXAMPLES)

if (NOT WIN32 OR MINGW)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/libkml.pc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/libkml.pc" @ONLY
  )

  install (FILES ${CMAKE_CURRENT_BINARY_DIR}/libkml.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
  )
endif (NOT WIN32 OR MINGW)

configure_package_config_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibKMLConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/LibKMLConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibKML
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
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
    FILE LibKML.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibKML
    NAMESPACE LibKML::
)
