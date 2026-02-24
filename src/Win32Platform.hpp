#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
class Win32Platform
{
public:
	Win32Platform(const Win32Platform&) = delete;
	Win32Platform& operator=(const Win32Platform&) = delete;
	Win32Platform(Win32Platform&&) = delete;
	Win32Platform& operator=(Win32Platform&&) = delete;
	static Win32Platform& GetInstance();
	void InitWindow(HINSTANCE hPrevInstance, int nCmdShow);
	void PollEvents();
	HWND GetHWND();
	bool CheckClose();
	void CloseWindow();
private:
	static LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM);
	Win32Platform();
	~Win32Platform();
	HWND hWnd;
	MSG msg;
	bool windowClose;
};