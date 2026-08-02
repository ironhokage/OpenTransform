cmake_minimum_required(VERSION 3.16)
project(OSTm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(OSTm INTERFACE
        include/baseTransform.h
        include/baseTransformStruct.h
        include/DAG.h
        include/Camera.h
)

target_include_directories(OSTm INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glm
)
find_package(glm QUIET)
target_link_libraries(OSTm INTERFACE glm)

add_executable(open3d_test tests/main.cpp)
target_link_libraries(open3d_test PRIVATE OSTm)