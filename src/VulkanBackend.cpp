#include "VulkanBackend.hpp"
VulkanBackend::VulkanBackend() : instance(nullptr),debugMessenger(nullptr),
physicalDevice(VK_NULL_HANDLE),device(nullptr),
graphicsQueue(nullptr),presentQueue(nullptr),
surface(nullptr),swapChain(nullptr)
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
	CreateSwapChain();
}
void VulkanBackend::RenderFrame()
{

}
void VulkanBackend::Shutdown()
{
	if (swapChain) vkDestroySwapchainKHR(device, swapChain, nullptr);
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
