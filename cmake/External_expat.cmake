include(FetchContent)

FetchContent_Declare (expat
    GIT_REPOSITORY  https://github.com/libexpat/libexpat.git
    GIT_TAG         R_2_6_3
    SOURCE_SUBDIR   expat
)

FetchContent_MakeAvailable (expat)
#Alias can be removed when https://github.com/libexpat/libexpat/pull/903 is merged
add_library(expat::expat ALIAS expat)
