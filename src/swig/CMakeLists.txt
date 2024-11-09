set (IFILES
  kmlbase.i
  kmldom.i
  kmlengine.i
)

if (LibKML_WITH_PYTHON)
  find_package(Python3 COMPONENTS Development Interpreter REQUIRED)

  if (NOT DEFINED PYTHON_INSTALL_DIR)
    execute_process (COMMAND
      ${Python3_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(True))"
      OUTPUT_VARIABLE PYTHON_INSTALL_DIR
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )
  endif (NOT DEFINED PYTHON_INSTALL_DIR)

  if(WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions("-DMS_WIN64")
  endif()

  foreach(INTERFACE_FILE ${IFILES})
    get_filename_component(MODULE_NAME ${INTERFACE_FILE} NAME_WE)

    set_source_files_properties(${INTERFACE_FILE} PROPERTIES
      CPLUSPLUS ON
      SWIG_MODULE_NAME ${MODULE_NAME}
    )

    swig_add_library(${MODULE_NAME}_swig_python
      TYPE MODULE
      LANGUAGE python
      SOURCES ${INTERFACE_FILE}
    )

    target_include_directories(${MODULE_NAME}_swig_python
      PRIVATE
        ${Python3_INCLUDE_DIRS}
      )

    set_target_properties (${MODULE_NAME}_swig_python
      PROPERTIES
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON
    )

    target_link_libraries(${MODULE_NAME}_swig_python
      PRIVATE
        LibKML::${MODULE_NAME}
    )

    install(TARGETS ${MODULE_NAME}_swig_python
      LIBRARY
        DESTINATION ${PYTHON_INSTALL_DIR}
    )

    install (FILES
      ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}.py
      DESTINATION ${PYTHON_INSTALL_DIR}
    )
  endforeach(INTERFACE_FILE ${IFILES})

endif(LibKML_WITH_PYTHON)

if(LibKML_WITH_JAVA)
  find_package(Java REQUIRED)
  find_package(JNI REQUIRED)
  include (UseJava)

  foreach(INTERFACE_FILE ${IFILES})
    get_filename_component(MODULE_NAME ${INTERFACE_FILE} NAME_WE)

    set_source_files_properties(${INTERFACE_FILE} PROPERTIES
      CPLUSPLUS ON
      SWIG_MODULE_NAME ${MODULE_NAME}
    )

    swig_add_library(${MODULE_NAME}_swig_java
      TYPE MODULE
      LANGUAGE java
      SOURCES ${INTERFACE_FILE}
    )

    set_target_properties(${MODULE_NAME}_swig_java
      PROPERTIES
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON
        POSITION_INDEPENDENT_CODE ON
    )

    target_include_directories(${MODULE_NAME}_swig_java
      PRIVATE ${JNI_INCLUDE_DIRS}
    )

    target_link_libraries(${MODULE_NAME}_swig_java
      PRIVATE LibKML::${MODULE_NAME}
    )

    get_target_property (${MODULE_NAME}_files
      ${MODULE_NAME}_swig_java
      SWIG_SUPPORT_FILES
    )

    list (APPEND java_sources ${${MODULE_NAME}_files})
  endforeach()

  add_jar (LibKML
    SOURCES ${java_sources}
  )

  install_jar(LibKML
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/java"
    COMPONENT Development
  )
endif(LibKML_WITH_JAVA)
