set(VNDINCLUDES ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Vulkan REQUIRED)
target_include_directories(vulkan-test PRIVATE ${VNDINCLUDES})
target_link_libraries(vulkan-test PRIVATE Vulkan::Vulkan)