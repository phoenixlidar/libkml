file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlregionator
    ${SRCS}
    ${INCS}
)

target_link_libraries (kmlregionator
    PRIVATE Boost::smart_ptr
    INTERFACE kmlengine
    INTERFACE kmlconvenience
)

install(TARGETS kmlregionator
    EXPORT LibKMLTargets
)

