file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlconvenience
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlconvenience
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_include_directories(kmlconvenience
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

target_link_libraries (kmlconvenience
    PUBLIC kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
)
