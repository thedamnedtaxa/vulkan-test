#include "VulkanBackend.hpp"
VulkanBackend::VulkanBackend() : instance(nullptr),debugMessenger(nullptr)
{

}
VulkanBackend::~VulkanBackend()
{

}
void VulkanBackend::Init()
{
	CreateInstance();
	SetupDebugMessenger();
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
