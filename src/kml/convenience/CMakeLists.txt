file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlconvenience
    ${SRCS}
    ${INCS}
)

target_link_libraries (kmlconvenience
    PRIVATE Boost::smart_ptr
    INTERFACE kmlengine
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
)
