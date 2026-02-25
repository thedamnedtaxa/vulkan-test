#include "VulkanBackend.hpp"
#include "Console.hpp"
#include <iostream>
#ifdef _WIN32
#include <Win32Platform.hpp>
#endif 
void VulkanBackend::CreateSurface()
{
	VkWin32SurfaceCreateInfoKHR createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	createInfo.hwnd = Win32Platform::GetInstance().GetHWND();
	createInfo.hinstance = GetModuleHandle(nullptr);
	if (vkCreateWin32SurfaceKHR(instance, &createInfo, nullptr, &surface) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create window surface!");
	}
	PRINT_LOG("Surface has been created;");
}
