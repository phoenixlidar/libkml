include(FetchContent)

FetchContent_Declare (boost
        GIT_REPOSITORY  https://github.com/boostorg/boost.git
        GIT_TAG         boost-1.86.0
	GIT_SUBMODULES	libs/assert
			libs/config
			libs/core
			libs/move
			libs/smart_ptr
			libs/static_assert
			libs/throw_exception
			libs/type_traits
			tools/cmake
			libs/headers
)

set (BOOST_INCLUDE_LIBRARIES "smart_ptr")

FetchContent_MakeAvailable(
    boost
)

boost_install(TARGETS
    boost_assert
    boost_config
    boost_core
    boost_move
    boost_static_assert
    boost_throw_exception
    boost_type_traits
    boost_smart_ptr
)
