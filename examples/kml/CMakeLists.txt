set (KML_EXAMPLES
    abstractview.kml
    allstyles.kml
    altitudemode.kml
    attrs.kml
    extendeddata.kml
    folder.kml
    inline-stylemap.kml
    kmlsamples.kml
    lines.kml
    model.kml
    networklinkcontrol.kml
    networklink.kml
    photooverlay.kml
    polygons2d.kml
    region.kml
    sky.kml
    snippets.kml
    styles.kml
    time.kml
    unknown-elements.kml
)

if(INSTALL_EXAMPLES)
    install(
        FILES ${KML_EXMPLES}
        DESTINATION ${KML_EXAMPLES_DIR}/kml
        COMPONENT Examples
    )
endif()
