include(FetchContent)

FetchContent_Declare (expat
    GIT_REPOSITORY  https://github.com/libexpat/libexpat.git
    GIT_TAG         R_2_6_3
    SOURCE_SUBDIR   expat
)

FetchContent_MakeAvailable (expat)
add_library(expat::expat ALIAS expat)
