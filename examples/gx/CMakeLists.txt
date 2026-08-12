foreach (EXAMPLE "gpxfly" "featuretour")
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML2::kmlconvenience
        CATEGORY gx
    )
endforeach (EXAMPLE "gpxfly" "featuretour")
