project(halapiclient)
cmake_minimum_required(VERSION 3.5)
set(TARGET "halapi")
set(CLIENT "HalApiClientTest")

### Compiler
### X86 Compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_SYSTEM_NAME amd64)

### thrift
include_directories(/usr/include/boost
                    /usr/local/include/boost)

set(SERVER_DIR  ${CMAKE_SOURCE_DIR}/../HalApiServer)
set(SHASTA_LIB_DIR  ${CMAKE_SOURCE_DIR}/../../shasta/libs)

include_directories(${SERVER_DIR}
                    ${SHASTA_LIB_DIR}/hal/api_lib/inc
                    ${SHASTA_LIB_DIR}/util-lib)

add_library(${TARGET} SHARED    ${SERVER_DIR}/HalApi_types.cpp
                                ${SERVER_DIR}/HalApi.cpp
                                ApiImplement.cpp)

add_executable (${CLIENT}       ${SERVER_DIR}/HalApi_types.cpp
                                ClientTest.cpp)

target_link_libraries (${CLIENT} halapi pthread thrift)


#debian
set(MAJAR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION_MAJOR "${MAJAR_VERSION}")
set(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
set(CPACK_PACKAGE_NAME "libhalclient-mlx")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "library hal client for sonic")
set(CPACK_PACKAGE_CONTACK "lu.mao@molex.com")
set(CPACK_DEBIAN_PACKAGE_NAME "libhalclient")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.31)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Molex <lu.mao@molex.com>")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA ${CMAKE_SOURCE_DIR}/doc/changelog)
include(CPack)

install(TARGETS ${TARGET}
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ WORLD_EXECUTE WORLD_WRITE WORLD_READ
        DESTINATION /usr/lib)
install(TARGETS ${CLIENT}
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ WORLD_EXECUTE WORLD_WRITE WORLD_READ
        DESTINATION /usr/local/bin)
install(DIRECTORY ${SHASTA_LIB_DIR}/hal/api_lib/inc/ DESTINATION /usr/include/halapi)