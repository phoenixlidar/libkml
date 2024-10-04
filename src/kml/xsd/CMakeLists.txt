file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlxsd
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlxsd
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_include_directories(kmlxsd
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

target_link_libraries (kmlxsd
    PUBLIC kmlbase
)

install(TARGETS kmlxsd
    EXPORT LibKMLTargets
)

