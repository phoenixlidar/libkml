macro(build_target)
  cmake_parse_arguments(LIB  "" "NAME" "SRCS;INCS;LINKS;DEPENDS" ${ARGN} )
  add_library(${LIB_NAME} ${LIB_SRCS})

  set(INTERFACE_LINKS)
  set(PUBLIC_LINKS)
  foreach(LIB_DEPEND ${LIB_DEPENDS})
    if(${LIB_DEPEND} MATCHES "^kml")
      list(APPEND INTERFACE_LINKS ${LIB_DEPEND})
    endif()
    add_dependencies(${LIB_NAME} ${LIB_DEPEND})
  endforeach()
  
  foreach(LIB_LINK ${LIB_LINKS})
    if(NOT ${LIB_LINK} MATCHES "^kml")
      list(APPEND PUBLIC_LINKS ${LIB_LINK})
    endif()
  endforeach()
  target_link_libraries(${LIB_NAME} ${PUBLIC_LINKS})
  if(INTERFACE_LINKS)
    if(MINGW OR APPLE)
      target_link_libraries(${LIB_NAME} ${INTERFACE_LINKS})
    else()
      target_link_libraries(${LIB_NAME} LINK_INTERFACE_LIBRARIES ${INTERFACE_LINKS})
    endif()
  endif()
  set_target_properties(${LIB_NAME} PROPERTIES
      VERSION   "${LibKML_VERSION_MAJOR}.${LibKML_VERSION_MINOR}.${LibKML_VERSION_PATCH}"
      SOVERSION "${LibKML_VERSION_MAJOR}")
  string(LENGTH ${LIB_NAME} ${LIB_NAME}_LEN)
  MATH(EXPR ${LIB_NAME}_END "${${LIB_NAME}_LEN} - 3")
  string(SUBSTRING ${LIB_NAME} 3 ${${LIB_NAME}_END} ${LIB_NAME}_INCLUDE_DIR)
  install(
    FILES ${LIB_INCS}
    DESTINATION ${INCLUDE_INSTALL_DIR}/${${LIB_NAME}_INCLUDE_DIR})

  install_target(${LIB_NAME})

endmacro(build_target)

macro(install_target _target)
  install(TARGETS ${_target}
    EXPORT LibKMLTargets
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR})
  
  list(LENGTH LIBKML_TARGETS LIBKML_TARGETS_LENGTH)
  if(LIBKML_TARGETS_LENGTH LESS 1)
    set(LIBKML_TARGETS "${_target}" PARENT_SCOPE)
  else()
    set(LIBKML_TARGETS "${LIBKML_TARGETS};${_target}" PARENT_SCOPE)
    endif()
endmacro(install_target)

function (build_test)
    cmake_parse_arguments (TEST  "" "GROUP;NAME" "LINKS" ${ARGN})
    set (PRETTY_TEST_NAME LibKML_test_${TEST_GROUP}_${TEST_NAME})
    add_executable (${PRETTY_TEST_NAME} ${TEST_NAME}_test.cc)

    target_link_libraries (${PRETTY_TEST_NAME}
        PRIVATE ${TEST_LINKS}
    )

    target_compile_definitions (${PRETTY_TEST_NAME}
        PRIVATE DATADIR=\"${LIBKML_DATA_DIR}\"
    )

    target_compile_options (${PRETTY_TEST_NAME}
        PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
    )

    target_include_directories (${PRETTY_TEST_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/tests
    )

    gtest_discover_tests (${PRETTY_TEST_NAME}
        TEST_PREFIX "LibKML_test_${TEST_GROUP}_"
    )
endfunction (build_test)

function (build_example)
    cmake_parse_arguments (EXAMPLE  "" "NAME" "LINKS" ${ARGN})

    add_executable (LibKML_example_${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)

    target_compile_options (example_${EXAMPLE_NAME}
        PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
    )

    if (EXAMPLE_LINKS)
        target_link_libraries(LibKML_example_${EXAMPLE_NAME}
            PRIVATE ${EXAMPLE_LINKS}
        )
    endif (EXAMPLE_LINKS)
endfunction (build_example)


macro(include_project_vars _project _lib)
  set(${_project}_INCLUDE_DIR "${INSTALL_DIR}/include")
  if(WIN32)
    set(_suffix ${CMAKE_LINK_LIBRARY_SUFFIX})
  else(UNIX)
    if(BUILD_SHARED_LIBS)
      set(_suffix ${CMAKE_SHARED_LIBRARY_SUFFIX})
    else()
      set(_suffix ".a")
    endif()
  endif(WIN32)
  set(${_project}_LIBRARY "${INSTALL_DIR}/lib/${_lib}${_suffix}")
  include_directories(${${_project}_INCLUDE_DIR})
endmacro()
