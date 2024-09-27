include(FetchContent)

FetchContent_Declare (gtest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         main
)

FetchContent_MakeAvailable (gtest)
