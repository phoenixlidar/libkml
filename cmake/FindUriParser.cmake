include(FetchContent)

FetchContent_Declare (uriparser
    GIT_REPOSITORY https://github.com/uriparser/uriparser.git
    GIT_TAG       uriparser-0.9.8
)

find_package(uriparser)

if (NOT URIPARSER_FOUND)
    set (URIPARSER_BUILD_TESTS OFF)
    set (URIPARSER_BUILD_DOCS OFF)
    FetchContent_MakeAvailable (uriparser)
    add_library (uriparser::uriparser ALIAS uriparser)
endif (NOT URIPARSER_FOUND)
