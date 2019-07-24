#pragma once




class MouseEventMgr{
public:
	MouseEventMgr();
	~MouseEventMgr();
public:
	static MouseEventMgr& GetInst();
	void DoMouseEvent();
	void DoMouseEvent(MOUSEINPUT& mouse_input);
	int GetPointerAccelerationMultiplier();
	int GetPointAccelerationThreshold();
	int GetPointerSensitivity();
private:
	bool GetMouseInfo();
	

private:
	MOUSEINPUT m_mouse_input;
	INPUT m_mouse_event;
	int m_pointer_acceleration_multiplier;
	int m_pointer_acceleration_threshold;
	int m_pointer_sensitivity;
};