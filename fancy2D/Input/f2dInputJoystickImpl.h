////////////////////////////////////////////////////////////////////////////////
/// @file  f2dInputJoystickImpl.h
/// @brief fancy2D����ϵͳ �ֱ�ʵ��
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "fcyRefObj.h"
#include "fcyIO\fcyStream.h"

#include "../f2dInputSys.h"

#include "f2dInputSysAPI.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief ��Ϸ�ֱ�ʵ��
////////////////////////////////////////////////////////////////////////////////
class f2dInputJoystickImpl :
	public fcyRefObjImpl<f2dInputJoystick>
{
	friend class f2dInputSysImpl;
private:
	static const fuInt BufferSize;
	static const DIDATAFORMAT DIDF_Joystick;
	static const DIOBJECTDATAFORMAT DIODF_Joystick[44];
private:
	IDirectInputDevice8* m_pDev;
	f2dInputJoystickEventListener* m_pListener;

	// ��Χֵ
	int m_lXHalf;
	int m_lXHalfLen;
	int m_lYHalf;
	int m_lYHalfLen;
	int m_lZHalf;
	int m_lZHalfLen;
	int m_lRxHalf;
	int m_lRxHalfLen;
	int m_lRyHalf;
	int m_lRyHalfLen;
	int m_lRzHalf;
	int m_lRzHalfLen;

	// ״̬
	float m_lX;               // X��λ��
    float m_lY;               // Y��λ��
    float m_lZ;               // Z��λ��
    float m_lRx;              // X����ת
    float m_lRy;              // Y����ת
    float m_lRz;              // Z����ת
	bool m_ButtonDown[32];    // ��ť״̬
	int m_Slider[2];          // Slider
	fuInt m_POV[4];            // POV
private:
	void initStates();
public:
	f2dInputMouse* ToMouse();
	f2dInputKeyboard* ToKeyboard();
	f2dInputJoystick* ToJoystick();

	fResult UpdateState(); 

	f2dInputJoystickEventListener* GetListener();
	fResult SetListener(f2dInputJoystickEventListener* pListener);

	// ״̬��ѯ
	fFloat GetXPosition();
	fFloat GetYPosition();
	fFloat GetZPosition();
	fFloat GetXRotation();
	fFloat GetYRotation();
	fFloat GetZRotation();
	fBool IsButtonDown(fuInt Index);
	fInt GetSlider(fuInt Index);
	fuInt GetPOV(fuInt Index);

	fFloat GetDeadZone();
	fResult SetDeadZone(fFloat Percent);
	fFloat GetSaturation();
	fResult SetSaturation(fFloat Percent);
protected: // ��ֱֹ��new/delete
	f2dInputJoystickImpl(IDirectInput8* pDev, HWND Win, const GUID& pGUID, fBool bGlobalFocus);
	~f2dInputJoystickImpl();
};