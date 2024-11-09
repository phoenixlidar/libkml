if(INSTALL_EXAMPLES)
    install (
        FILES domviewer.py
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/kml/examples/domviewer
        COMPONENT Examples
    )
endif()
