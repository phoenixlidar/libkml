foreach (EXAMPLE "csvregionator" "kmlregionator")
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML2::kmlregionator
        CATEGORY regionator
    )
endforeach (EXAMPLE "csvregionator" "kmlregionator")
