file(GLOB_RECURSE SRCs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
target_sources(vulkan-test PRIVATE ${SRCs})
target_include_directories(vulkan-test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})