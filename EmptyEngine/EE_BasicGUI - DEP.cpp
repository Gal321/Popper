//#include "EE_GraphicEntities.h"
#include "EE_Engine.h"
//
//EE::GraphicEntity::GraphicEntity(EE::SIZE size, EE::POINT pos, EE::Uint8 alpha)
//{
//	this->size = size;
//	this->pos = pos;
//	this->layer = layer;
//	this->name = name;
//
//	hover = false;
//	active = false;
//	mouseUp = false;
//
//	listOfUIEnt.push_back(this);
//}
//
//EE::GraphicEntity::~GraphicEntity()
//{
//	for (auto it = listOfUIEnt.begin(); it != listOfUIEnt.end(); ++it)
//		if (this == (*it))
//		{
//			listOfUIEnt.erase(it);
//			break;
//		}
//}
//
//
//EE::Textbox::Textbox(string name, string buttonName, Type type, EE_SIZE size, EE_POINT pos, BYTE layer)
//	: EE::GraphicEntity(name, size, pos, layer)
//{
//	this->type = type;
//	this->buttonName = buttonName;
//	textData = L"";
//	lastCharTime = 0;
//
//	EEngine::GetIns()->input.GetLastChar(true);
//	/*ent_disable_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1::ColorF(0x5b9bd5), size, pos, layer);
//	ent_active_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1_COLOR(Coral), size, pos, layer);
//	ent_hover_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1_COLOR(LightGray), size, pos, layer);*/
//	ent_rect = new Rect(0xff, 0xff, 0xff, 0xff, size, pos, layer);
//	ent_text = new Text(0x5b, 0x9b, 0xd5, 0xff, textData, size.height - 20, DEFAULT_FONT, pos, layer + 1);
//}
//
//EE::Textbox::~Textbox()
//{
//	delete ent_rect;
//	delete ent_text;
//}
//
//void Textbox::Step(int ticks)
//{
//	mouseUp = false;
//	if (hover)
//	{
//		//SetCursor(LoadCursor(NULL, IDC_HAND));
//	}
//	if (active)
//	{
//		ent_rect->SetColor(0xff, 0xf0, 0x50);
//		if (EEngine::GetIns()->input.GetLastChar())
//		{
//			lastCharTime = ticks;
//			if (EEngine::GetIns()->input.GetLastChar() == '\b')
//			{
//				textData = textData.substr(0, textData.length()-1);
//				EEngine::GetIns()->input.GetLastChar(true);
//			}
//			else if (EEngine::GetIns()->input.GetLastChar() == '\r')
//			{
//				EEngine::GetIns()->input.GetLastChar(true);
//				if (buttonName != "N/A" && EE::GraphicEntity::GetEntByName(buttonName) != nullptr)
//				{
//					EE::GraphicEntity::GetEntByName(buttonName)->active = true;
//					EE::GraphicEntity::GetEntByName(buttonName)->mouseUp = true;
//					EE::GraphicEntity::GetEntByName(buttonName)->Step(ticks);
//				}
//			}
//			else
//			{
//				if (type != Textbox::Type::Num && type != Textbox::Type::NumPassword)
//					textData += EEngine::GetIns()->input.GetLastChar(true);
//				else
//				{
//					if (EEngine::GetIns()->input.GetLastChar() >= '0' && EEngine::GetIns()->input.GetLastChar() <= '9')
//					{
//						if (textData.length() < 10)
//							textData += EEngine::GetIns()->input.GetLastChar(true);
//					}
//					else
//					{
//						EEngine::GetIns()->input.GetLastChar(true);
//					}
//				}
//			}
//			if (type != Textbox::Type::Password && type != Textbox::Type::NumPassword)
//				ent_text->SetText(textData);
//			else
//			{
//				wstring temp = L"";
//				for (unsigned int i = 0; i < textData.length(); i++)
//					temp += L'•';
//				ent_text->SetText(temp);
//			}
//		}
//		return;
//	}
//	if (hover)
//	{
//		ent_rect->SetColor(0xd3, 0xd3, 0xd3);
//		return;
//	}
//	ent_rect->SetColor(0x5b, 0x9b, 0xd5);
//}
//
//wstring Textbox::GetData()
//{
//	return textData;
//}
//
//void Textbox::SetText(wstring text)
//{
//	textData = text;
//	ent_text->SetText(textData);
//}
//
//
////Button::Button(string name, wstring title, void (*ActiveFunc)(), float fontSize, D2D1_SIZE_U size, D2D1_POINT_2F pos, DWRITE_TEXT_ALIGNMENT textAli, BYTE layer)
////	:EE::GraphicEntity(name, size, pos, layer)
////{
////	lastClickTime = 0;
////
////	this->ActiveFunc = ActiveFunc;
////
////	EEngine::GetIns()->input.GetLastChar(true);
////	ent_normal = new Rect(D2D1::ColorF(0xa6b7cd), 1.0f, D2D1::ColorF(0x8a98ab), size, pos, layer);
////	ent_active = new Rect(D2D1_COLOR(Maroon), 1.0f, D2D1::ColorF(0x8a98ab), size, pos, layer);
////	ent_hover = new Rect(D2D1::ColorF(0x3a5273), 1.0f, D2D1::ColorF(0x8a98ab), size, pos, layer);
////	ent_text = new Text(title, D2D1::SizeU(size.width-10, size.height), D2D1::Point2F(pos.x+5, pos.y), layer + 1, D2D1_COLOR(White), fontSize, textAli);
////}
////
////Button::~Button()
////{
////	delete ent_normal;
////	delete ent_active;
////	delete ent_hover;
////	delete ent_text;
////}
////
////void Button::Step(int ticks)
////{
////	if (active)
////	{
////		SetCursor(LoadCursor(NULL, IDC_HAND));
////		ent_normal->toRender = false;
////		ent_active->toRender = true;
////		ent_hover->toRender = false;
////		if (mouseUp)
////		{
////			if (ActiveFunc != NULL)
////				ActiveFunc();
////			lastClickTime = ticks;
////			active = false;
////			mouseUp = false;
////		}
////		return;
////	}
////	if (hover)
////	{
////		SetCursor(LoadCursor(NULL, IDC_HAND));
////		ent_normal->toRender = false;
////		ent_active->toRender = false;
////		ent_hover->toRender = true;
////		return;
////	}
////	ent_normal->toRender = true;
////	ent_active->toRender = false;
////	ent_hover->toRender = false;
////}
////
////wstring Button::GetData()
////{
////	return active?L"1":L"0";
////}
////
////
////DropList::DropList(string name, float fontSize, D2D1_SIZE_U size, D2D1_POINT_2F pos, BYTE layer)
////	:EE::GraphicEntity(name, size, pos, layer)
////{
////	subClick = false;
////	optionNum = 0;
////	hoverOptionNum = 0;
////	lineSize = fontSize;
////
////	ent_disable_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1::ColorF(0x5b9bd5), size, pos, layer);
////	ent_active_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1_COLOR(Coral), size, pos, layer);
////	ent_hover_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1_COLOR(LightGray), size, pos, layer);
////	ent_dropdown_rect = new Rect(D2D1_COLOR(White), 1.0f, D2D1_COLOR(Gray), D2D1::SizeU(size.width, 0),D2D1::Point2F(pos.x, pos.y+size.height), layer+2);
////	ent_dropdown_rect->toRender = false;
////	ent_dropdown_hover = new Rect(D2D1::ColorF(0xd8d8d8), 0.0f, D2D1_COLOR(Black), D2D1::SizeU(size.width, static_cast<int>(lineSize*(7.0f/6.0f))), D2D1::Point2F(pos.x, pos.y+size.height), layer+3);
////	ent_dropdown_hover->toRender = false;
////	ent_text = new Text(L"", D2D1::SizeU(size.width-10, size.height), D2D1::Point2F(pos.x+5, pos.y), layer + 1, D2D1::ColorF(0x5b9bd5), fontSize, DWRITE_TEXT_ALIGNMENT_LEADING);
////	ent_dropdown_text = new Text(L"", D2D1::SizeU(size.width-10, 0), D2D1::Point2F(pos.x+5, pos.y+size.height), layer + 4, D2D1::ColorF(0x5b9bd5), fontSize, DWRITE_TEXT_ALIGNMENT_LEADING, DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
////	ent_dropdown_text->toRender = false;
////	ent_downarrow = new Bitmap(L"DropdownArrow", D2D1::SizeU(32, 32), D2D1::Point2F(pos.x+5, pos.y+((size.height-32)/2)), layer+1);
////}
////
////DropList::~DropList()
////{
////	delete ent_downarrow;
////	delete ent_disable_rect;
////	delete ent_active_rect;
////	delete ent_hover_rect;
////	delete ent_dropdown_rect;
////	delete ent_dropdown_hover;
////	delete ent_text;
////	delete ent_dropdown_text;
////}
////
////void DropList::Step(int ticks)
////{
////	ticks = ticks;
////	mouseUp = false;
////	if (active)
////	{
////		if (hover)
////			SetCursor(LoadCursor(NULL, IDC_HAND));
////		ent_disable_rect->toRender = false;
////		ent_active_rect->toRender = true;
////		ent_hover_rect->toRender = false;
////		ent_dropdown_text->toRender = true;
////		ent_dropdown_rect->toRender = true;
////		ent_dropdown_hover->toRender = true;
////		ent_dropdown_hover->SetPos(
////			D2D1::Point2F(
////				ent_dropdown_hover->GetPos().x,
////				pos.y+size.height+(hoverOptionNum*static_cast<int>(lineSize*(7.0f/6.0f)))
////				)
////			);
////		if (subClick)
////		{
////			optionNum = hoverOptionNum;
////			ent_text->SetText(options[optionNum]);
////			subClick = false;
////			active = false;
////		}
////		// TODO
////		return;
////	}
////	if (hover)
////	{
////		SetCursor(LoadCursor(NULL, IDC_HAND));
////		ent_disable_rect->toRender = false;
////		ent_active_rect->toRender = false;
////		ent_hover_rect->toRender = true;
////		ent_dropdown_text->toRender = false;
////		ent_dropdown_rect->toRender = false;
////		ent_dropdown_hover->toRender = false;
////		return;
////	}
////	ent_disable_rect->toRender = true;
////	ent_active_rect->toRender = false;
////	ent_hover_rect->toRender = false;
////	ent_dropdown_text->toRender = false;
////	ent_dropdown_rect->toRender = false;
////	ent_dropdown_hover->toRender = false;
////}
////
////wstring DropList::GetData()
////{
////	return options[optionNum];
////}
////
////void DropList::AddOption(wstring opt)
////{
////	wstring str;
////	options.push_back(opt);
////	if (ent_text->GetText() == L"")
////		ent_text->SetText(options[0]);
////	ent_dropdown_rect->SetSize(D2D1::SizeU(size.width, static_cast<int>(lineSize*(7.0f/6.0f))*options.size()+10));
////	ent_dropdown_text->SetSize(D2D1::SizeU(size.width-10, static_cast<int>(lineSize*(7.0f/6.0f))*options.size()+10));
////	str = ent_dropdown_text->GetText();
////	ent_dropdown_text->SetText(str+(str==L""?L"":L"\n")+opt);
////}