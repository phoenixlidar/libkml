set (JAVA_EXAMPLES
    CreateFolder.java
    CreatePlacemark.java
    run.sh
    WalkFeatures.java
)

if(INSTALL_EXAMPLES)
    install(
        FILES ${JAVA_EXAMPLES}
        DESTINATION ${KML_EXAMPLES_DIR}/java
        COMPONENT Examples
    )
endif()
