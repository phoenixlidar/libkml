include(FetchContent)

FetchContent_Declare (boost_assert
    GIT_REPOSITORY https://github.com/boostorg/assert.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_config
    GIT_REPOSITORY https://github.com/boostorg/config.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_core
    GIT_REPOSITORY https://github.com/boostorg/core.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_move
    GIT_REPOSITORY https://github.com/boostorg/move.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_static_assert
    GIT_REPOSITORY https://github.com/boostorg/static_assert.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_throw_exception
    GIT_REPOSITORY https://github.com/boostorg/throw_exception.git
    GIT_TAG        boost-1.86.0
)


FetchContent_Declare (boost_type_traits
    GIT_REPOSITORY https://github.com/boostorg/type_traits.git
    GIT_TAG        boost-1.86.0
)

FetchContent_Declare (boost_smart_ptr
    GIT_REPOSITORY https://github.com/boostorg/smart_ptr.git
    GIT_TAG        boost-1.86.0
)

FetchContent_MakeAvailable(
    boost_assert
    boost_config
    boost_core
    boost_move
    boost_static_assert
    boost_throw_exception
    boost_type_traits
    boost_smart_ptr
)
