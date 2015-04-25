#include <SDL_image.h>
#include "EE_GraphicEntities - DEP.h"
#include "EE_Strings.h"

EE::GraphicEntity::GraphicEntity(std::shared_ptr<EE::Engine> container,
								 EE::Size size,
								 EE::Point pos,
								 EE::Uint8 alpha):
	toRender(false),
	pos(pos),
	size(size),
	container(container),
	alpha(alpha),
	fadeTime(0),
	texture(nullptr)
{
	this->Initialize();
}

EE::GraphicEntity::~GraphicEntity()
{
	this->Uninitialize();
}


EE::Sprite::Sprite(std::shared_ptr<EE::Engine> container,
				   std::wstring filePath,
				   EE::Size size,
				   EE::Point pos,
				   EE::Uint8 alpha):
	filePath(filePath),
	EE::GraphicEntity(container, size, pos, alpha)
{
}

bool EE::Sprite::Initialize()
{
	SDL_Surface *bitmap = IMG_Load(EE::Utility::WStringToString(this->filePath).c_str());
	if (bitmap == nullptr)
	{
		printf("Bitmap could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	this->texture = SDL_CreateTextureFromSurface(this->GetRenderer(), bitmap);
	this->SetAlpha(this->alpha);

	SDL_FreeSurface(bitmap);

	return true;
}

void EE::Sprite::Uninitialize()
{
	if (this->texture)
		SDL_DestroyTexture(this->texture);
}

const void EE::Sprite::DrawObject()
{
	if (this->texture)
	{
		SDL_Rect rect{ this->pos.x, this->pos.y, this->size.width, this->size.height };
		SDL_RenderCopy(this->GetRenderer(), this->texture, NULL, &rect);
	}
}

void EE::Sprite::SetAlpha(Uint8 alpha)
{
	this->alpha = alpha;
	SDL_SetTextureAlphaMod(this->texture, alpha);
}


EE::Rect::Rect(std::shared_ptr<EE::Engine> container,
			   EE::Uint8 red,
			   EE::Uint8 green,
			   EE::Uint8 blue,
			   EE::Uint8 alpha,
			   EE::Size size,
			   EE::Point pos):
	color({ red, green, blue, alpha }),
	sdlSurface(nullptr),
	EE::GraphicEntity(container, size, pos, alpha)
{
}

bool EE::Rect::Initialize()
{
	SDL_SetRenderDrawBlendMode(this->GetRenderer(), SDL_BLENDMODE_BLEND);
	this->sdlSurface = SDL_GetWindowSurface(this->GetWindow());
	if (this->sdlSurface == nullptr)
	{
		printf("Basic rect could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void EE::Rect::Uninitialize()
{
	if (this->sdlSurface)
		SDL_FreeSurface(this->sdlSurface);
}

const void EE::Rect::DrawObject()
{
	SDL_Rect rect{ this->pos.x, this->pos.y, this->size.width, this->size.height };
	SDL_Color temp = { 0, 0, 0, 0 };

	SDL_GetRenderDrawColor(this->GetRenderer(), &temp.r, &temp.g, &temp.b, &temp.a);
	SDL_SetRenderDrawColor(this->GetRenderer(), this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(this->GetRenderer(), &rect);
	SDL_SetRenderDrawColor(this->GetRenderer(), temp.r, temp.g, temp.b, temp.a);
}


EE::Text::Text(std::shared_ptr<EE::Engine> container,
			   EE::Uint8 red,
			   EE::Uint8 green,
			   EE::Uint8 blue,
			   EE::Uint8 alpha,
			   std::wstring text,
			   unsigned int fontSize,
			   std::string fontName,
			   EE::Point pos):
	color({ red, green, blue, alpha }),
	text(text),
	fontSize(fontSize),
	fontName(fontName),
	font(nullptr),
	EE::GraphicEntity(container, EE::Size::Get(), pos, alpha)
{
}

bool EE::Text::Initialize()
{
	this->font = TTF_OpenFont(this->fontName.c_str(), this->fontSize);
	if (this->font == nullptr)
	{
		printf("Font file could not be loaded! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	this->SetText(this->text);

	return true;
}

void EE::Text::Uninitialize()
{
	TTF_CloseFont(this->font);
}

const void EE::Text::DrawObject()
{
	if (this->texture)
	{
		SDL_Rect rect{ this->pos.x, this->pos.y, this->size.width, this->size.height };
		SDL_RenderCopy(this->GetRenderer(), this->texture, NULL, &rect);
	}
}

void EE::Text::SetText(std::wstring text)
{
	SDL_Surface *surf = nullptr;
	char16_t *unicodeText = EE::Utility::WStringToUnicode(text.c_str());

	this->text = text;

	surf = TTF_RenderUNICODE_Blended(this->font, unicodeText, this->color);
	this->texture = SDL_CreateTextureFromSurface(this->GetRenderer(), surf);

	TTF_SizeUNICODE(this->font, unicodeText, &this->size.width, &this->size.height);

	SDL_FreeSurface(surf);
	delete[] unicodeText;
}

const std::wstring EE::Text::GetText()
{
	return this->text;
}