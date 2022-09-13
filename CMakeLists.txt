cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME metacpp)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
include_directories(vendor)

# set(LIBCLANG_LIB "")

if(WIN32)
    file(GLOB_RECURSE LIBCLANG_LIB "vendor/libclang.lib")
elseif(APPLE)
    file(GLOB_RECURSE LIBCLANG_LIB "vendor/libclang.dylib")
elseif(UNIX)
    file(GLOB_RECURSE LIBCLANG_LIB "vendor/libclang.so")
else()
    set(LIBCLANG_LIB "not found")
endif()

message("LIBCLANG_LIB : ${LIBCLANG_LIB}")

add_executable(${PROJECT_NAME} src/main.cpp src/meta/meta.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBCLANG_LIB})
