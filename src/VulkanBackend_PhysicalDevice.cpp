#include "VulkanBackend.hpp"
#include "Console.hpp"
#include <iostream>
#include <vector>
bool QueueFamilyIndices::IsComplete()
{
	return graphicsFamily.has_value();
}
void VulkanBackend::PickPhysicalDevice()
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
	if (deviceCount == 0)
	{
		PRINT_ERROR("Failed to find GPUs with vk support!");
		throw std::runtime_error("failed to find GPUs with Vulkan support!");
	}
	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
	for (const auto& device : devices)
	{
		if (IsDeviceSuitable(device))
		{
			physicalDevice = device;
			PRINT_LOG("Physical device was picked.");
			break;
		}
	}
	if (physicalDevice == VK_NULL_HANDLE)
	{
		PRINT_ERROR("Failed to pick physical device.");
		throw std::runtime_error("failed to find a suitable GPU!");
	}

}
bool VulkanBackend::IsDeviceSuitable(VkPhysicalDevice device)
{
	QueueFamilyIndices indices = FindQueueFamilies(device);
	return indices.IsComplete();
}
QueueFamilyIndices VulkanBackend::FindQueueFamilies(VkPhysicalDevice device) {
	QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

	int i = 0;
	for (const auto& queueFamily : queueFamilies)
	{
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			indices.graphicsFamily = i;
		}

		if (indices.IsComplete())
		{
			break;
		}

		i++;
	}
	return indices;
}
