cmake_minimum_required(VERSION 3.16)
project(OpenTransform LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(OpenTransform INTERFACE)

target_include_directories(OpenTransform INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glm
)

find_package(glm QUIET)
target_link_libraries(OpenTransform INTERFACE glm)

add_executable(open3d_test tests/main.cpp)
target_link_libraries(open3d_test PRIVATE OpenTransform)