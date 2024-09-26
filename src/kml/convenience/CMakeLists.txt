file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlconvenience
    ${SRCS}
    ${INCS}
)

target_link_libraries (kmlconvenience
    PRIVATE Boost::smart_ptr
)

install(TARGETS kmlconvenience
    EXPORT LibKMLTargets
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
)
