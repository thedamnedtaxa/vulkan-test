cmake_minimum_required(VERSION 3.30)
project(vulkan-test VERSION 1.0)
set(CMAKE_C_STANDARD_99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vulkan-test WIN32)
set_target_properties(vulkan-test PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
add_subdirectory(vendor)
add_subdirectory(src)