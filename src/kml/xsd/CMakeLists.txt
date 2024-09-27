file(GLOB SRCS "*.cc" )
file(GLOB INCS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(kmlxsd
    ${SRCS}
    ${INCS}
)

target_link_libraries (kmlxsd
    PRIVATE Boost::smart_ptr
)

install(TARGETS kmlxsd
    EXPORT LibKMLTargets
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
)

