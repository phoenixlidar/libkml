foreach (EXAMPLE "csvregionator" "kmlregionator")
    build_example(
        NAME ${EXAMPLE}
        LINKS LibKML::kmlregionator
        CATEGORY regionator
    )
endforeach (EXAMPLE "csvregionator" "kmlregionator")
