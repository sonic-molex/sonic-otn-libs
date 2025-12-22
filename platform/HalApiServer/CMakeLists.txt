project(halapi)
cmake_minimum_required(VERSION 3.5)
set(SERVER "HalApiServer")
set(CLIENT "HalApiTest")

### Compiler
### X86 Compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

### thrift
include_directories(/usr/include/boost
                    /usr/local/include/boost)

set(SHASTA_LIB_DIR  ${CMAKE_SOURCE_DIR}/../../shasta/libs)
include_directories(${SHASTA_LIB_DIR}/hal/api_lib/inc
                    ${SHASTA_LIB_DIR}/util-lib)

LINK_DIRECTORIES($ENV{LINK_DIR})
add_executable (${SERVER}       HalApi_types.cpp
                                HalApi.cpp
                                ApiHelper.cpp
                                HalApi_server.cpp)

target_link_libraries (${SERVER} halapi oplkutil pthread thrift)

add_executable (${CLIENT}       HalApi_types.cpp
                                HalApi.cpp
                                HalApiTest.cpp)

target_link_libraries (${CLIENT} thrift)