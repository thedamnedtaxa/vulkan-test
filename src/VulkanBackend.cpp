#include "VulkanBackend.hpp"
VulkanBackend::VulkanBackend() : instance(nullptr),debugMessenger(nullptr),
physicalDevice(VK_NULL_HANDLE),device(nullptr),
graphicsQueue(nullptr),presentQueue(nullptr),
surface(nullptr)
{

}
VulkanBackend::~VulkanBackend()
{

}
void VulkanBackend::Init()
{
	CreateInstance();
	SetupDebugMessenger();
	CreateSurface();
	PickPhysicalDevice();
	CreateLogicalDevice();
}
void VulkanBackend::RenderFrame()
{

}
void VulkanBackend::Shutdown()
{
	if (device) vkDestroyDevice(device, nullptr);
#ifndef NDEBUG
	if (debugMessenger)
	{
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}
#endif 
	if(surface) vkDestroySurfaceKHR(instance, surface, nullptr);
	if(instance) vkDestroyInstance(instance, nullptr);
}
