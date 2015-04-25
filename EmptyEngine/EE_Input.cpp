#include "EE_Input.h"
//#include "EE_BasicGUI.h"

EE::Input::Input():
	lastKey(0),
	lastCharRecv(0),
	mousePos({0, 0})
{
	int i = 0;

	for (i = 0; i < 256; i++)
		keyPressed[i] = false;
	for (i = 0; i < 3; i++)
		mousePress[i] = false;
}

bool EE::Input::IsKeyDown(const EE::Byte key) const
{
	return keyPressed[key];
}

void EE::Input::KeyDown(EE::Byte key)
{
	keyPressed[key] = true;
	lastKey = key;
}

void EE::Input::KeyUp(EE::Byte key)
{
	keyPressed[key] = false;
}

EE::Byte EE::Input::GetLastKey() const
{
	return lastKey;
}

void EE::Input::SetLastChar(wchar_t key)
{
	lastCharRecv = key;
}

wchar_t EE::Input::GetLastChar(bool toReset)
{
	if (toReset)
	{
		wchar_t temp = lastCharRecv;
		lastCharRecv = 0;
		return temp;
	}
	return lastCharRecv;
}

EE::Point EE::Input::GetMousePos() const
{
	return mousePos;
}

void EE::Input::SetMousePos(EE::Point pos)
{
	this->mousePos = pos;
}

void EE::Input::MouseKeyDown(EE::Input::MouseKeys key)
{
	(key);

	/*bool flag = false;
	MousePress[key] = true;
	if (key == EE::Input::LButton)
	{
		for (auto obj : Entity::listOfUIEnt)
		{
			if (obj->hover && !flag)
			{
				obj->active = true;
				LastCharRecv = 0;
				flag = true;
			}
			else if (typeid(*obj) == typeid(DropList) && obj->active && !flag)
			{
				DropList *temp = (DropList*)obj;
				if (MouseX >= temp->pos.x &&
					MouseX <= temp->size.width + temp->pos.x &&
					MouseY >= temp->pos.y+temp->size.height &&
					MouseY <= temp->pos.y+temp->size.height+static_cast<int>(temp->lineSize*(7.0f/6.0f))*temp->options.size())
				{
					temp->subClick = true;
					temp->active = true;
				}
				else
				{
					temp->subClick = false;
					temp->active = false;
				}
				return;
			}
			else obj->active = false;
		}
	}*/
}

void EE::Input::MouseKeyUp(EE::Input::MouseKeys key)
{
	(key);

	/*MousePress[key] = false;
	if (key == EE::Input::LButton)
	{
		for (auto obj : Entity::listOfUIEnt)
			if (obj->active)
				obj->mouseUp = true;
	}*/
}

bool EE::Input::IsMouseKeyDown(const EE::Input::MouseKeys key) const
{
	return mousePress[key];
}