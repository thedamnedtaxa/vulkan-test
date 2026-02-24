#include "Win32Platform.hpp"
#include "Renderer.hpp"
Renderer::Renderer() : vk(nullptr)
{

}
Renderer::~Renderer()
{
	if (vk) vk->Shutdown();
}
void Renderer::Run()
{
	Init();
	MainLoop();
}
void Renderer::Init()
{
	vk = std::make_unique<VulkanBackend>();
	vk->Init();
}
void Renderer::MainLoop()
{
	Win32Platform& win32Instance = Win32Platform::GetInstance();
	while (!win32Instance.CheckClose())
	{
		win32Instance.PollEvents();
		vk->RenderFrame();
	}
}