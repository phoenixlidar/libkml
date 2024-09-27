include(FetchContent)

FetchContent_Declare (minizip
    GIT_REPOSITORY  https://github.com/zlib-ng/minizip-ng.git
    GIT_TAG         4.0.7
)

find_package(minizip CONFIG)

if (NOT MINIZIP_FOUND)
    FetchContent_MakeAvailable (minizip)
endif (NOT MINIZIP_FOUND)
