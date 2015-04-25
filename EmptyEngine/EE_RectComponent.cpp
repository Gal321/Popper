#include "EE_RectComponent.h"

EE::PIG::Rect::Rect(
	Uint8 red,
	Uint8 green,
	Uint8 blue,
	Uint8 alpha,
	Size size,
	Point position)
	: Graphics(size, position, alpha),
	color({ red, green, blue, alpha }),
	sdlSurface(nullptr)
{
}

void EE::PIG::Rect::setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	this->color.r = red;
	this->color.g = green;
	this->color.b = blue;
	this->color.a = alpha;
}

void EE::PIG::Rect::Initialize()
{
	SDL_SetRenderDrawBlendMode(this->owner->owner.GetRenderer(), SDL_BLENDMODE_BLEND);
	this->sdlSurface = SDL_GetWindowSurface(this->owner->owner.GetWindow());

	if (this->sdlSurface == nullptr)
	{
		printf("Basic rect could not be created! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}
}

void EE::PIG::Rect::Update(int ticks)
{
	// Its just a rect...
}

void EE::PIG::Rect::Render()
{
	SDL_Rect rect{ this->position.x, this->position.y, this->size.width, this->size.height };
	SDL_Color temp = { 0, 0, 0, 0 };

	// changing render color to ours, rendering and then restoring it
	SDL_GetRenderDrawColor(this->owner->owner.GetRenderer(), &temp.r, &temp.g, &temp.b, &temp.a);
	SDL_SetRenderDrawColor(this->owner->owner.GetRenderer(), this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(this->owner->owner.GetRenderer(), &rect);
	SDL_SetRenderDrawColor(this->owner->owner.GetRenderer(), temp.r, temp.g, temp.b, temp.a);
}

void EE::PIG::Rect::Uninitialize()
{
	if (this->sdlSurface)
	{
		SDL_FreeSurface(this->sdlSurface);
	}
}