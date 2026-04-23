set (JAVA_EXAMPLES
    CreateFolder.java
    CreatePlacemark.java
    run.sh
    WalkFeatures.java
)

if(INSTALL_EXAMPLES)
    install(
        FILES ${JAVA_EXAMPLES}
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/kml/examples/java
        COMPONENT Examples
    )
endif()
