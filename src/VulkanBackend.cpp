#include "VulkanBackend.hpp"
VulkanBackend::VulkanBackend() : instance(nullptr)
{

}
VulkanBackend::~VulkanBackend()
{

}
void VulkanBackend::Init()
{
	CreateInstance(); 
}
void VulkanBackend::RenderFrame()
{

}
void VulkanBackend::Shutdown()
{
	if(instance) vkDestroyInstance(instance, nullptr);
}
