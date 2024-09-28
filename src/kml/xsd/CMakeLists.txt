file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlxsd
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlxsd
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic -fno-rtti
)

target_link_libraries (kmlxsd
    PRIVATE Boost::smart_ptr
    INTERFACE kmlbase
)

install(TARGETS kmlxsd
    EXPORT LibKMLTargets
)

