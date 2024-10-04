set(TESTS
attributes
csv_splitter
date_time
expat_handler_ns
file
math_util
referent
string_util
tempfile
time_util
util
vec3
version
xml_element
xml_file
xml_namespaces
xmlns
uri_parser
expat_parser)

if(MINGW)
  add_definitions(-DXML_UNICODE)
endif()

foreach(TEST ${TESTS})
    build_test(
        GROUP base
        NAME ${TEST}
        LINKS Boost::smart_ptr GTest::gtest_main kmlbase
    )
endforeach()

#color32
#net_cache
#zip_file
