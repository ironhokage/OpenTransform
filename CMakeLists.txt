cmake_minimum_required(VERSION 3.16)
project(OpenTransform LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for Clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Header‑only library target
add_library(OpenTransform INTERFACE)

# Where to find your own headers
target_include_directories(OpenTransform INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}                # project root
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glm # for <glm/glm.hpp>
)

# Link GLM – it’s header‑only, so INTERFACE is enough
find_package(glm QUIET)
if(NOT glm_FOUND)
    # If not installed, use the bundled copy
    add_library(glm INTERFACE)
    target_include_directories(glm INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glm
    )
endif()
target_link_libraries(OpenTransform INTERFACE glm)

# Dummy executable to trigger compilation (needed for compile_commands.json)
add_executable(open3d_test tests/main.cpp)
target_link_libraries(open3d_test PRIVATE OpenTransform)