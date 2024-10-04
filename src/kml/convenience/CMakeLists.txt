file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlconvenience
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlconvenience
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
)

target_link_libraries (kmlconvenience
    PUBLIC kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
)
