#include "Win32Platform.hpp"
#include "Input.hpp"
#include <inttypes.h>
Win32Platform::Win32Platform() : hWnd(nullptr),msg(nullptr),windowClose(false)
{

}
Win32Platform::~Win32Platform()
{
	if (hWnd)
	{
		DestroyWindow(hWnd);
	}
}
Win32Platform& Win32Platform::GetInstance()
{
	static Win32Platform instance;
	return instance;
}
void Win32Platform::InitWindow(HINSTANCE hInstance,int nCmdShow)
{
	constexpr uint32_t SCR_WIDTH = 800;
	constexpr uint32_t SCR_HEIGHT = 600;
	constexpr const char* SCR_TITLE =  "Vulkan Renderer";
	constexpr const char* CLASS_NAME = "VULKAN_TEST";
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = CLASS_NAME;
	RegisterClassEx(&wc);
	hWnd = CreateWindowEx(
		0,								
		CLASS_NAME,						
		SCR_TITLE,                     
		WS_OVERLAPPEDWINDOW,                  
		CW_USEDEFAULT, CW_USEDEFAULT,   
		SCR_WIDTH, SCR_HEIGHT,          
		NULL,                          
		NULL,                         
		hInstance,                    
		NULL                        
	);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}
void Win32Platform::PollEvents()
{
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
void Win32Platform::CloseWindow()
{
	windowClose = true;
}
bool Win32Platform::CheckClose()
{
	return windowClose;
}
HWND Win32Platform::GetHWND()
{
	return this->hWnd;
}
LRESULT CALLBACK Win32Platform::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		Win32Platform::GetInstance().CloseWindow();
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		Input::Update();
		return 0;
	case WM_KEYUP:
		Input::Update();
		return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}