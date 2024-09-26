include(FetchContent)

FetchContent_Declare (zlib
    GIT_REPOSITORY  https://github.com/madler/zlib.git
    GIT_TAG         v1.3.1
)

FetchContent_MakeAvailable (zlib)
add_library(ZLIB::ZLIB ALIAS zlib)
