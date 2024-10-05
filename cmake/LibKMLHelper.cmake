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

function (install_example FILE DEST)
    install(
        FILES ${FILE}
        DESTINATION ${KML_EXAMPLES_DIR}/${DEST}
        COMPONENT Examples
    )
endfunction (install_example FILE DEST)

function (build_example)
    cmake_parse_arguments (EXAMPLE  "" "NAME;CATEGORY" "LINKS" ${ARGN})

    add_executable (LibKML_example_${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)

    target_compile_options (LibKML_example_${EXAMPLE_NAME}
        PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
    )

    if (EXAMPLE_LINKS)
        target_link_libraries(LibKML_example_${EXAMPLE_NAME}
            PRIVATE ${EXAMPLE_LINKS}
        )
    endif (EXAMPLE_LINKS)

    if(INSTALL_EXAMPLES)
        install_example (${EXAMPLE_NAME}.cc ${EXAMPLE_CATEGORY})
    endif(INSTALL_EXAMPLES)
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
