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
        LINKS GTest::gtest_main kmlregionator
    )
endforeach (TEST ${TESTS})
