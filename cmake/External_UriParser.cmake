include(FetchContent)

FetchContent_Declare (uriparser
    GIT_REPOSITORY https://github.com/uriparser/uriparser.git
    GIT_TAG       uriparser-0.9.8
)

set (URIPARSER_BUILD_TESTS CACHE BOOL OFF)
set (URIPARSER_BUILD_DOCS CACHE BOOL OFF)
FetchContent_MakeAvailable (uriparser)
#Alias can be removed when https://github.com/uriparser/uriparser/pull/197 is merged
add_library (uriparser::uriparser ALIAS uriparser)
