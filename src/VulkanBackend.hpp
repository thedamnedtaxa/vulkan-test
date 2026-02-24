#pragma once
#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#include <vulkan/vulkan.h>
VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
#ifndef NDEBUG
extern const char* VALIDATION_LAYERS[];
#endif 
extern const uint32_t VALIDATION_LAYER_COUNT;
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
	VkDebugUtilsMessengerEXT debugMessenger;
	void CreateInstance();
	bool CheckValidationLayerSupport();
	void SetupDebugMessenger();
	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
};