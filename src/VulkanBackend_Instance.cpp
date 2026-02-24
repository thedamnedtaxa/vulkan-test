#include "VulkanBackend.hpp"
#include "Console.hpp"
#include <inttypes.h>
#include <iostream>
#ifdef _WIN32
#ifndef NDEBUG
const char* INSTANCE_EXTENSIONS[] =
{
	VK_KHR_SURFACE_EXTENSION_NAME,
	VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
	VK_EXT_DEBUG_UTILS_EXTENSION_NAME
};
const char* VALIDATION_LAYERS[] =
{
	"VK_LAYER_KHRONOS_validation"
};
const uint32_t VALIDATION_LAYER_COUNT= static_cast<uint32_t>(sizeof(VALIDATION_LAYERS) / sizeof(const char*));
#else 
const char* INSTANCE_EXTENSIONS[] =
{
	VK_KHR_SURFACE_EXTENSION_NAME,
	VK_KHR_WIN32_SURFACE_EXTENSION_NAME
};
const char* VALIDATION_LAYER_COUNT = 0;
#endif 
const uint32_t INSTANCE_EXTENSION_COUNT =
static_cast<uint32_t>(sizeof(INSTANCE_EXTENSIONS) / sizeof(const char*));
#endif 
void VulkanBackend::CreateInstance()
{
	if (VALIDATION_LAYER_COUNT > 0 && !CheckValidationLayerSupport())
	{
		PRINT_ERROR("Validation layers requested, but not available!");
		throw std::runtime_error("validation layers requested, but not available!");
	}
	PRINT_LOG("Creating Vulkan instance.");
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "vulkan-test";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = INSTANCE_EXTENSION_COUNT;
	createInfo.ppEnabledExtensionNames = INSTANCE_EXTENSIONS;
	if (VALIDATION_LAYER_COUNT > 0)
	{
		createInfo.ppEnabledLayerNames = VALIDATION_LAYERS;
		createInfo.enabledLayerCount = VALIDATION_LAYER_COUNT;
	}
	else
	{
		createInfo.ppEnabledLayerNames = nullptr;
		createInfo.enabledLayerCount = VALIDATION_LAYER_COUNT;
	}
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
	{
		PRINT_ERROR("Failed to create Vulkan instance.");
		throw std::runtime_error("failed to create instance!");
	}
}