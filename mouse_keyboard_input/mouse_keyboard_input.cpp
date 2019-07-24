// mouse_keyboard_input.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "mouse_event_mgr.h"
#include "keyboard_event_mgr.h"

int main(int argc, _TCHAR* argv[])
{
	//MOUSEINPUT mouse_input;
	//mouse_input.dx = 100;
	//mouse_input.dy = 100;
	//mouse_input.dwFlags = MOUSEEVENTF_MOVE;
	//MouseEventMgr::GetInst().DoMouseEvent(mouse_input);
	MouseEventMgr::GetInst().DoMouseEvent();
	printf_s("Pointer Acceleration Mutiplier: %d \nPointer Acceleration Threshold: %d \nPointer Sensitivity: %d\n", \
		MouseEventMgr::GetInst().GetPointerAccelerationMultiplier(),\
		MouseEventMgr::GetInst().GetPointAccelerationThreshold(),\
		MouseEventMgr::GetInst().GetPointerSensitivity()\
		);

	KeyboardEventMgr::GetInst().DoKeyboardEvent();
	system("pause");
	return 0;
}

