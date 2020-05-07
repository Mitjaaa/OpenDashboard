#include "windows_listener.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <tchar.h>
#include "ODashboardApp.h"

// defines whether the window is visible or not
// should be solved with makefile, not in this file
#define visible // (visible / invisible)

// variable to store the HANDLE to the hook. Don't declare it anywhere else then globally
// or you will get problems since every function uses this variable.
HHOOK _hook;

// This struct contains the data received by the hook callback. As you see in the callback function
// it contains the thing you will need: vkCode = virtual key code.
KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke);
std::ofstream OUTPUT_FILE;

// This is the callback function. Consider it the event that is raised when, in this case, 
// a key is pressed.
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		// the action is valid: HC_ACTION.
		if (wParam == WM_KEYDOWN)
		{
			// lParam is the pointer to the struct containing the data needed, so cast and assign it to kdbStruct.
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

			// save to file
			Save(kbdStruct.vkCode);
		}
	}

	// call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
	return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{

	// Set the hook and set it to use the callback function above
	// WH_KEYBOARD_LL means it will set a low level keyboard hook. More information about it at MSDN.
	// The last 2 parameters are NULL, 0 because the callback function is in the same thread and window as the
	// function that sets and releases the hook.
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
	{
		LPCWSTR a = L"Failed to install hook!";
		LPCWSTR b = L"Error";
		MessageBox(NULL, a, b, MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

int Save(int key_stroke)
{
	static char lastwindow[256] = "";

	if ((key_stroke == 1) || (key_stroke == 2))
		return 0;

	HWND foreground = GetForegroundWindow();
	DWORD threadID;
	HKL layout = NULL;
	if (foreground) {
		//get keyboard layout of the thread
		threadID = GetWindowThreadProcessId(foreground, NULL);
		layout = GetKeyboardLayout(threadID);
	}

	char key;
	bool escPressed = false;
	bool tabPressed = false;

	if ((GetKeyState(ODashboardApp::keycomb1) & 0x1000) != 0) {
		escPressed = !escPressed;
	}
	else if ((GetKeyState(ODashboardApp::keycomb2) & 0x1000) != 0) {
		tabPressed = !tabPressed;
	}

	key = MapVirtualKeyExA(key_stroke, MAPVK_VK_TO_CHAR, layout);

	if ((escPressed && key_stroke == ODashboardApp::keycomb2) || (tabPressed && key_stroke == ODashboardApp::keycomb1)) {
		ODashboardApp::getApp()->changeState();
	}

	return 0;
}

windows_listener::windows_listener()
{
	SetHook();

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {}
}

windows_listener::~windows_listener()
{
}
