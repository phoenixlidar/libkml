set (BASE_SOURCES
    attributes.cc
    csv_splitter.cc
    date_time.cc
    expat_handler_ns.cc
    expat_parser.cc
    file.cc
    $<IF:$<PLATFORM_ID:Windows>,file_win32.cc,file_posix.cc>
    localec.cc
    math_util.cc
    mimetypes.cc
    referent.cc
    string_util.cc
    time_util.cc
    uri_parser.cc
    version.cc
    xml_namespaces.cc
    zip_file.cc
    $<IF:$<PLATFORM_ID:Windows>,contrib/strptime.c,>
    contrib/minizip/iomem_simple.c
    contrib/minizip/unzip.c
)

if(WIN32)
  if(MINGW)
      #use unicode functions from the windows api
      add_definitions(-DUNICODE -D_UNICODE)
      #supress long-long warning for mingw
      set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/time_util.cc COMPILE_FLAGS "-Wno-long-long")
  endif()
else()
  #supress long-long warning for linux
  set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/zip_file.cc COMPILE_FLAGS "-Wno-long-long")
endif()

set (BASE_HEADERS
    attributes.h
    csv_splitter.h
    date_time.h
    color32.h
    expat_handler.h
    expat_handler_ns.h
    expat_parser.h
    file.h
    math_util.h
    memory_file.h
    mimetypes.h
    net_cache.h
    referent.h
    string_util.h
    tempfile.h
    time_util.h
    util.h
    vec3.h
    version.h
    xml_element.h
    xml_file.h
    xml_namespaces.h
    xmlns.h
    zip_file.h
    contrib/minizip/iomem_simple.h
    contrib/minizip/unzip.h
)

add_library (kmlbase SHARED
    ${BASE_SOURCES}
    ${BASE_HEADERS}
)

add_library (LibKML::kmlbase ALIAS kmlbase)

set_target_properties (kmlbase PROPERTIES
    PUBLIC_HEADER "${BASE_HEADERS}"
    SOVERSION "${LibKML_VERSION_MAJOR}"
    VERSION   "${LibKML_VERSION}"
)

target_compile_definitions(kmlbase
    PRIVATE NOUNCRYPT
)

target_compile_options(kmlbase
    PRIVATE -Wall
    PRIVATE $<$<NOT:$<BOOL:${MSVC}>>:-Wextra -Wno-unused-parameter -pedantic>
)

target_include_directories(kmlbase
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/contrib
    PUBLIC $<BUILD_INTERFACE:${LibKML_SOURCE_DIR}/src>
)

target_link_libraries (kmlbase
    PUBLIC MINIZIP::minizip
    PUBLIC uriparser::uriparser
    PUBLIC ZLIB::ZLIB
    PUBLIC expat::expat
    PUBLIC Boost::headers
)

install(TARGETS kmlbase
    EXPORT LibKML
    LIBRARY
        COMPONENT Runtime
    INCLUDES
        COMPONENT Development
)
