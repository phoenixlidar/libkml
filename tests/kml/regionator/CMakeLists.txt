set (TESTS
    feature_list_region_handler
    regionator
    regionator_qid
    regionator_util
)

foreach (TEST ${TESTS})
    build_test (
        GROUP regionator
        NAME ${TEST}
        LINKS Boost::smart_ptr GTest::gtest_main kmlregionator
    )
endforeach (TEST ${TESTS})
