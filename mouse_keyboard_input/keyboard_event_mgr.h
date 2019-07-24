#pragma once

class KeyboardEventMgr{
public:
	KeyboardEventMgr();
	~KeyboardEventMgr();
public:
	static KeyboardEventMgr& GetInst();
	void DoKeyboardEvent();
	void DoKeyboardEvent(KEYBDINPUT& keyboard_input);



private:
	KEYBDINPUT m_keyboard_input;
	INPUT m_keyboard_event;

};