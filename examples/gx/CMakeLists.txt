foreach (EXAMPLE "gpxfly" "featuretour")
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML::kmlconvenience
        CATEGORY gx
    )
endforeach (EXAMPLE "gpxfly" "featuretour")
