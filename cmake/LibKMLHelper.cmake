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
        PRIVATE -Wall
        PRIVATE $<$<NOT:$<BOOL:${MSVC}>>:-Wextra -Wno-unused-parameter -pedantic>
    )

    target_include_directories (${PRETTY_TEST_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/tests
    )

    gtest_add_tests (
		TARGET ${PRETTY_TEST_NAME}
        TEST_PREFIX "LibKML_test_${TEST_GROUP}_"
		TEST_LIST   ${PRETTY_TEST_NAME}_TESTS
    )

    if (WIN32 OR CYGWIN)
		LKML_findTestEnv (${PRETTY_TEST_NAME} TEST_ENV)

		foreach (test IN LISTS ${PRETTY_TEST_NAME}_TESTS)
			set_tests_properties (${test} PROPERTIES
				ENVIRONMENT "${TEST_ENV}"
			)
		endforeach (test IN LISTS ${PRETTY_TEST_NAME}_TESTS)
	endif (WIN32 OR CYGWIN)
endfunction (build_test)

function (install_example FILE DEST)
    install(
        FILES ${FILE}
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/kml/examples/${DEST}
        COMPONENT Examples
    )
endfunction (install_example FILE DEST)

function (build_example)
    cmake_parse_arguments (EXAMPLE  "" "NAME;CATEGORY" "LINKS" ${ARGN})

    add_executable (LibKML_example_${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)

    target_compile_options(LibKML_example_${EXAMPLE_NAME}
        PRIVATE -Wall
        PRIVATE $<$<NOT:$<BOOL:${MSVC}>>:-Wextra -Wno-unused-parameter -pedantic>
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

function (LKML_findTestEnv testName resultVar)
	LKML_findTestLibs (${testName} ${resultVar})

	if (CYGWIN)
		set (separator ":")
	else()
		set (separator "\\\\\;")
	endif()

	string (JOIN ${separator} tempEnv ${${resultVar}})
	string (PREPEND tempEnv "PATH=")

	if (CYGWIN)
		string (APPEND tempEnv ${separator}$ENV{PATH})
	endif (CYGWIN)

	set (${resultVar} ${tempEnv} PARENT_SCOPE)
endfunction()

function (LKML_findTestLibs testName resultVar)
	unset (linkLibs)

	if (NOT TARGET ${testName})
		set (interface TRUE)
	else()
		get_property (interface
			TARGET ${testName}
			PROPERTY IMPORTED
		)
	endif()

	if (${interface})
		get_property (location
			TARGET ${testName}
			PROPERTY LOCATION
		)

		if (location)
			string (REGEX MATCH "^.*/" libPath ${location})
			list (FIND ${resultVar} "${libPath}" index)

			if (${index} STREQUAL "-1")
				list (APPEND resultVar "${libPath}")
			endif()
		endif (location)
	else()
		get_property (linkLibs
			TARGET ${testName}
			PROPERTY LINK_LIBRARIES
		)

		foreach (lib IN ITEMS ${linkLibs})
			LKML_findTestLibs (${lib} ${resultVar})

			if (NOT TARGET ${lib})
				set (interface2 TRUE)
			else()
				get_property (type
					TARGET ${lib}
					PROPERTY TYPE
				)

				if (${type} STREQUAL "INTERFACE_LIBRARY")
					set (interface2 TRUE)
				else()
					get_property (interface2
						TARGET ${lib}
						PROPERTY IMPORTED
					)
				endif()
			endif()

			if (NOT ${interface2})
				list (FIND ${resultVar} "$<TARGET_FILE_DIR:${lib}>" index)
				if (${index} STREQUAL "-1")
					list (APPEND ${resultVar} "$<TARGET_FILE_DIR:${lib}>")
				endif()
			endif()
		endforeach()
	endif()

	set (${resultVar} ${${resultVar}} PARENT_SCOPE)
endfunction()
