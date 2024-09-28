file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlconvenience
    ${SRCS}
    ${INCS}
)

target_compile_options(kmlconvenience
    PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic -fno-rtti
)

target_link_libraries (kmlconvenience
    PRIVATE Boost::smart_ptr
    INTERFACE kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
)
