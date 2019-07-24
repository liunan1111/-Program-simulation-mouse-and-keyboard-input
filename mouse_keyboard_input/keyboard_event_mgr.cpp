#include "stdafx.h"

#include "keyboard_event_mgr.h"


KeyboardEventMgr::KeyboardEventMgr()
{
	m_keyboard_event.type = INPUT_KEYBOARD;
}

KeyboardEventMgr::~KeyboardEventMgr()
{

}

KeyboardEventMgr& KeyboardEventMgr::GetInst()
{
	static KeyboardEventMgr keyboard_event_mgr;
	return keyboard_event_mgr;
}

void KeyboardEventMgr::DoKeyboardEvent()
{
	for (int i = 0; i< 10; i++)
	{
		/*VK_ */
		INPUT input[2];
		memset(input, 0, sizeof(input));
		input[0].type = input[1].type = INPUT_KEYBOARD;
		input[0].ki.wVk =input[1].ki.wVk= 0x41;
		input[1].ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(2, input, sizeof(INPUT));


		Sleep(1000);
	}

}

void KeyboardEventMgr::DoKeyboardEvent( KEYBDINPUT& keyboard_input )
{
	m_keyboard_event.ki = keyboard_input;
	SendInput(1, &m_keyboard_event, sizeof(INPUT));
}