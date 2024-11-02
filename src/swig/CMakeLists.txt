if (LibKML_WITH_PYTHON)
  find_package(Python3 COMPONENTS Development Interpreter REQUIRED)

  include_directories(${PYTHON_INCLUDE_PATH})

  if(WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions("-DMS_WIN64")
  endif()

  set (IFILES
    kmlbase.i
    kmldom.i
    kmlengine.i
  )

  foreach(INTERFACE_FILE ${IFILES})
    get_filename_component(MODULE_NAME ${INTERFACE_FILE} NAME_WE)

    set_source_files_properties(${INTERFACE_FILE} PROPERTIES
      CPLUSPLUS ON
      SWIG_MODULE_NAME ${MODULE_NAME}
    )

    swig_add_library(${MODULE_NAME}_swig
      TYPE MODULE
      LANGUAGE python
      SOURCES ${INTERFACE_FILE}
    )

    target_include_directories(${MODULE_NAME}_swig
      PRIVATE
        ${Python3_INCLUDE_DIRS}
      )

    set_target_property(${MODULE_NAME}_swig
      PROPERTY
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON
    )

    target_link_libraries(${MODULE_NAME}_swig
      PRIVATE
        LibKML::kmlbase
        LibKML::kmlengine
        LibKML::kmldom
    )
  endforeach(INTERFACE_FILE ${IFILES})

endif(LibKML_WITH_PYTHON)

if(LibKML_WITH_JAVA)
  find_package(Java REQUIRED)
  find_package(JNI REQUIRED)
  mark_as_advanced(JAVA_HOME)

  include_directories(${JAVA_INCLUDE_PATH}
    ${JNI_INCLUDE_DIRS})
  include_directories ( ${JAVA_INCLUDE_PATH} ${JNI_INCLUDE_DIRS} )

  # Make sure the nested directory structure exists
  set(JAVA_SOURCE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/com/googlecode/libkml)
  set(JAVA_BINARY_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/build)
  if(NOT EXISTS "${JAVA_SOURCE_DIRECTORY}")
    file(MAKE_DIRECTORY ${JAVA_SOURCE_DIRECTORY})
  endif()
  if(NOT EXISTS "${JAVA_BINARY_DIRECTORY}")
    file(MAKE_DIRECTORY ${JAVA_BINARY_DIRECTORY})
  endif()
  #  java_package_dir = com/googlecode/libkml
  file(GLOB IFILES "kml*.i")
  set(LIBKML_JAVA_PACKAGE "com.googlecode.libkml")
  set(CMAKE_SWIG_OUTDIR ${JAVA_SOURCE_DIRECTORY})
  set(CMAKE_SWIG_FLAGS -package "${LIBKML_JAVA_PACKAGE}" ${CMAKE_SWIG_GLOBAL_FLAGS})

  foreach(INTERFACE_FILE ${IFILES})
    get_filename_component(MODULE_NAME ${INTERFACE_FILE} NAME_WE)
    set_source_files_properties(${INTERFACE_FILE} PROPERTIES CPLUSPLUS ON)
    set_source_files_properties(${INTERFACE_FILE} PROPERTIES CMAKE_SWIG_FLAGS "-includeall  -DSWIGJAVA")
    set_source_files_properties( ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}JAVA_wrap.cxx COMPILE_FLAGS "-w")
    swig_add_module(${MODULE_NAME}_swig_java java ${INTERFACE_FILE})
    swig_link_libraries(${MODULE_NAME}_swig_java ${MODULE_NAME})
    install(TARGETS ${MODULE_NAME}_swig_java DESTINATION ${JNI_INSTALL_DIR})

  endforeach()

  add_custom_target(LibKML_jar ALL DEPENDS LibKML.jar)

  add_custom_command(
    OUTPUT LibKML.jar
    COMMENT "Creating jar file..."
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${JAVA_BINARY_DIRECTORY} ${JAVA_SOURCE_DIRECTORY}/*.java
    COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/LibKML.jar -C ${JAVA_BINARY_DIRECTORY} com
    DEPENDS LibKML_jar kmlbase_swig_java kmldom_swig_java kmlengine_swig_java)

   # Get the location of the extension directory
   string(REGEX REPLACE "include"  "jre/lib/ext" JAVA_EXTENSION_DIR ${JAVA_INCLUDE_PATH})

   install(FILES ${CMAKE_CURRENT_BINARY_DIR}/LibKML.jar
     DESTINATION ${JAVA_INSTALL_DIR})

endif(WITH_JAVA)
