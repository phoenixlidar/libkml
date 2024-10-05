set (PYTHON_EXAMPLES
    helloenum.py
    hellogeometry.py
    hellolocation.py
    helloplacemark.py
    hellopoint.py
    hellovector.py
    hellowalk.py
    parse_point_placemark.py
)

if(INSTALL_EXAMPLES)
    install(
        FILES ${PYTHON_EXAMPLES}
        DESTINATION ${KML_EXAMPLES_DIR}/python
        COMPONENT Examples
    )
endif()
