file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlregionator
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlregionator
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_include_directories(kmlregionator
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

target_link_libraries (kmlregionator
    PUBLIC kmlengine
    PUBLIC kmlconvenience
)

install(TARGETS kmlregionator
    EXPORT LibKMLTargets
)

