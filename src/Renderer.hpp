#pragma once 
#include "VulkanBackend.hpp"
#include <memory>
class Renderer
{
public:
	Renderer();
	~Renderer();
	void Run();
private:
	std::unique_ptr<VulkanBackend> vk;
	void Init();
	void MainLoop();
};