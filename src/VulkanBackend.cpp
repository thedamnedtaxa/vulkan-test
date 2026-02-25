#include "VulkanBackend.hpp"
VulkanBackend::VulkanBackend() : instance(nullptr),debugMessenger(nullptr),
physicalDevice(VK_NULL_HANDLE)
{

}
VulkanBackend::~VulkanBackend()
{

}
void VulkanBackend::Init()
{
	CreateInstance();
	SetupDebugMessenger();
	PickPhysicalDevice();
}
void VulkanBackend::RenderFrame()
{

}
void VulkanBackend::Shutdown()
{
#ifndef NDEBUG
	if (debugMessenger)
	{
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}
#endif 
	if(instance) vkDestroyInstance(instance, nullptr);
}
