#include "EE_Exceptions.h"
#include "EE_Entity.h"
#include "EE_Engine.h"
#include "EE_RectComponent.h"

EE::Components::Rect::Rect(
						Uint8 red,
						Uint8 green,
						Uint8 blue,
						Uint8 alpha,
						Size size,
						Point position):
	Graphic(size, position, alpha),
	color({ red, green, blue, alpha }),
	sdlSurface(nullptr)
{
}

EE::Components::Rect::~Rect()
{
	if (this->sdlSurface)
	{
		SDL_FreeSurface(this->sdlSurface);
	}
}

void EE::Components::Rect::setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	this->color.r = red;
	this->color.g = green;
	this->color.b = blue;
	this->color.a = alpha;
}

void EE::Components::Rect::Initialize()
{
	SDL_SetRenderDrawBlendMode(this->owner->owner->GetRenderer(), SDL_BLENDMODE_BLEND);
	this->sdlSurface = SDL_GetWindowSurface(this->owner->owner->GetWindow());

	if (this->sdlSurface == nullptr)
	{
		printf("Basic rect could not be created! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}
}

void EE::Components::Rect::Update(int ticks)
{
	(ticks);
	// Its just a rect...
}

void EE::Components::Rect::Render()
{
	SDL_Rect rect{ this->position.x, this->position.y, this->size.width, this->size.height };
	SDL_Color temp = { 0, 0, 0, 0 };

	// changing render color to ours, rendering and then restoring it
	SDL_GetRenderDrawColor(this->owner->owner->GetRenderer(), &temp.r, &temp.g, &temp.b, &temp.a);
	SDL_SetRenderDrawColor(this->owner->owner->GetRenderer(), this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(this->owner->owner->GetRenderer(), &rect);
	SDL_SetRenderDrawColor(this->owner->owner->GetRenderer(), temp.r, temp.g, temp.b, temp.a);
}