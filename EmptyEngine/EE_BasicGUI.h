#pragma once
/******************************************************************
*                                                                 *
* EE_BasicGUI.h - Declare and define all of the entities for the  *
*                 UI.                                             *
*                                                                 *
******************************************************************/

#include "EE_GraphicEntities.h"

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

namespace EE {
	class Entity
	{
	public:
		Entity(
			std::string name = "N/A",
			Size size = Size::Get(),
			Point pos = Point::Get()
			);
		~Entity();
		virtual void Step(int ticks) = 0;
		virtual std::wstring GetData() = 0;

		std::string name;
		bool active;
		bool mouseUp;
		bool hover;
	protected:
		Size size;
		Point pos;
		friend class Input;
	};

	class Textbox : public Entity
	{
	public:
		typedef enum Type
		{
			All,
			Num,
			Password,
			NumPassword
		} Type;
		Textbox(
			std::string name = "N/A",
			std::string buttonName = "N/A",
			Type type = All,
			Size size = Size::Get(),
			Point pos = Point::Get()
			);
		~Textbox();
		virtual void Step(int ticks);
		virtual std::wstring GetData();
		void SetText(std::wstring text);
	private:
		Rect *ent_rect;
		Text *ent_text;
		Type type;
		std::wstring textData;
		int lastCharTime;
		std::string buttonName;
	};

	// TODO - DANGRE ZONE!
	/*class Button : public Entity
	{
	public:
	typedef struct FuncList
	{
	// ToDo
	} FuncList;
	Button(
	string name = "N/A",
	wstring title = L"",
	void (*ActiveFunc)() = NULL,
	float fontSize = 22.0f,
	EE_Size size = EE_Size::Get(),
	EE_Point pos = EE_Point::Get(),
	DWRITE_TEXT_ALIGNMENT textAli = DWRITE_TEXT_ALIGNMENT_CENTER,
	BYTE layer = DEFAULT_LAYER
	);
	~Button();
	virtual void Step(int ticks);
	virtual wstring GetData();
	private:
	Rect *ent_normal;
	Rect *ent_active;
	Rect *ent_hover;
	Text *ent_text;
	void (*ActiveFunc)();
	bool isToggle;
	int lastClickTime;
	};

	class DropList : public Entity
	{
	public:
	DropList(
	string name = "N/A",
	float fontSize = 22.0f,
	EE_Size size = EE_Size::Get(),
	EE_Point pos = EE_Point::Get(),
	BYTE layer = DEFAULT_LAYER
	);
	~DropList();
	virtual void Step(int ticks);
	virtual wstring GetData();
	void AddOption(wstring opt);
	private:
	Bitmap *ent_downarrow;
	Rect *ent_disable_rect;
	Rect *ent_active_rect;
	Rect *ent_hover_rect;
	Rect *ent_dropdown_rect;
	Rect *ent_dropdown_hover;
	Text *ent_text;
	Text *ent_dropdown_text;
	BYTE optionNum;
	BYTE hoverOptionNum;
	vector<wstring> options;
	float lineSize;
	bool subClick;
	friend class Input;
	};*/
}
