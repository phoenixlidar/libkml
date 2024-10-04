set (TESTS
    xsd_complex_type
    xsd_file
    xsd_element
    xsd_handler
    xsd_primitive_type
    xsd_simple_type
    xsd_schema
    xsd_util
    xst_parser
)

foreach (TEST ${TESTS})
    build_test (
        GROUP xsd
        NAME ${TEST}
        LINKS Boost::smart_ptr GTest::gtest_main kmlxsd
    )
endforeach (TEST ${TESTS})
