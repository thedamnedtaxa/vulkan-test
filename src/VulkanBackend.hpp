#pragma once
#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#include <vulkan/vulkan.h>
class VulkanBackend
{
public:
	VulkanBackend();
	~VulkanBackend();
	void Init();
	void RenderFrame();
	void Shutdown();
private:
	VkInstance instance;
	void CreateInstance();
};