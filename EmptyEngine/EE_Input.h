#pragma once
/******************************************************************
*                                                                 *
* Input.h - Declare and define the keyborad and mouse inputs      *
*                                                                 *
******************************************************************/

#include "EE_Base.h"

namespace EE
{
	class Input
	{
	public:
		typedef enum MouseKeys
		{
			LButton,
			MButton,
			RButton
		} MouseKeys;

		Input();
		// For keyboard
		bool IsKeyDown(const EE::Byte key) const;
		void KeyDown(EE::Byte key);
		void KeyUp(EE::Byte key);
		EE::Byte GetLastKey() const;
		void SetLastChar(wchar_t key);
		wchar_t GetLastChar(bool toReset = false);

		// For mouse
		EE::Point GetMousePos() const;
		void SetMousePos(Point pos);
		void MouseKeyDown(MouseKeys key);
		void MouseKeyUp(MouseKeys key);
		bool IsMouseKeyDown(const MouseKeys key) const;
	private:
		// For keyboard data
		bool keyPressed[256];
		EE::Byte lastKey;
		wchar_t lastCharRecv;

		// For mouse data
		Point mousePos;
		bool mousePress[3];
	};
}
