include(FetchContent)

FetchContent_Declare (curl
    GIT_REPOSITORY  https://github.com/curl/curl.git
    GIT_TAG         curl-8_10_1
)

set (BUILD_CURL_EXE OFF CACHE BOOL "")

if (NOT INSTALL_EXAMPLES)
    set (CURL_DISABLE_INSTALL ON CACHE BOOL "")
endif (NOT INSTALL_EXAMPLES)

find_package (OpenSSL)

if (NOT OPENSSL_FOUND)
    set (CURL_USE_OPENSSL OFF CACHE BOOL "")
    unset (OPENSSL_LIBRARIES)
#Needed until https://github.com/curl/curl/issues/15077 is fixed
endif (NOT OPENSSL_FOUND)

FetchContent_MakeAvailable (curl)
set (CURL_FOUND TRUE)

