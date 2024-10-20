include(FetchContent)

FetchContent_Declare (minizip
    GIT_REPOSITORY  https://github.com/zlib-ng/minizip-ng.git
    GIT_TAG         4.0.7
)

if (WIN32)
    set (MZ_LZMA FALSE)
    set (MZ_ZSTD FALSE)
endif (WIN32)

FetchContent_MakeAvailable (minizip)
