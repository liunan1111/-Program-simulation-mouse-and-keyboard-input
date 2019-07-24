#include "stdafx.h"

#include "mouse_event_mgr.h"

MouseEventMgr::MouseEventMgr()
{
	m_mouse_event.type = INPUT_MOUSE;
	m_mouse_event.mi = m_mouse_input;
	m_pointer_acceleration_multiplier = -1;
	m_pointer_acceleration_threshold = -1;
	m_pointer_sensitivity = -1;
}

MouseEventMgr::~MouseEventMgr()
{

}

MouseEventMgr& MouseEventMgr::GetInst()
{
	static MouseEventMgr mouse_event_mgr;
	return mouse_event_mgr;
}


void MouseEventMgr::DoMouseEvent()
{

	m_mouse_input.dx = 50;
	m_mouse_input.dy = 50;
	m_mouse_input.dwFlags = MOUSEEVENTF_MOVE;
	m_mouse_event.mi = m_mouse_input;//deep copy ,do copy again when m_mouse_input change;
	
	POINT p;
	GetCursorPos(&p);
	printf_s("Begin X: %d | Y: %d\n",p.x, p.y);

	UINT ret = SendInput(1, &m_mouse_event, sizeof(m_mouse_event));
	if (0 == ret)
	{
		printf_s("%d",GetLastError);
	}
	GetCursorPos(&p);
	printf_s("After X: %d | Y: %d\n",p.x, p.y);

}

void MouseEventMgr::DoMouseEvent( MOUSEINPUT& mouse_input )
{
	m_mouse_event.mi = mouse_input;
	POINT p;
	GetCursorPos(&p);
	printf_s("Begin x: %d y: %d\n",p.x, p.y); 

	UINT ret = SendInput(1, &m_mouse_event, sizeof(m_mouse_event));
	if (0 == ret)
	{
		printf_s("%d",GetLastError);
	}

	GetCursorPos(&p);
	printf_s("After x: %d y: %d\n",p.x, p.y);
}

bool MouseEventMgr::GetMouseInfo()
{

	int mouse[3]; // 0-Threshold X, 1-Threshold Y and 2-Speed.
	
	if (SystemParametersInfo(SPI_GETMOUSE, 0, &mouse, 0))
	{
		m_pointer_acceleration_multiplier = mouse[2];
		m_pointer_acceleration_threshold = (mouse[0]+mouse[1])/2;

		if (m_pointer_acceleration_multiplier != -1 && m_pointer_acceleration_threshold != -1)
		{
			return true;
		}
	}
	return false;

}

int MouseEventMgr::GetPointerAccelerationMultiplier()
{
	if (m_pointer_acceleration_multiplier != -1)
	{
		return m_pointer_acceleration_multiplier;
	}
	else
	{
		GetMouseInfo();
		return m_pointer_acceleration_multiplier;
	}
}

int MouseEventMgr::GetPointAccelerationThreshold()
{
	if (m_pointer_acceleration_threshold != -1)
	{
		return m_pointer_acceleration_threshold;
	}
	else
	{
		GetMouseInfo();
		return m_pointer_acceleration_threshold;
	}
}

int MouseEventMgr::GetPointerSensitivity()
{
	int value = -1;
	int sensitivity;
	if (SystemParametersInfo(SPI_GETMOUSESPEED, 0, &sensitivity, 0))
	{
		value = sensitivity;
	}
	return value;
}