#include "EE_GraphicsComponent.h"

EE::Components::Graphics::Graphics(Size size,
								   Point position,
								   Uint8 alpha,
								   bool isVisible):
	BaseComponent(),
	size(size),
	position(position),
	textureAlpha(alpha),
	texture(nullptr),
	isVisible(isVisible)
{
}

void EE::Components::Graphics::SetTextureAlpha(Uint8 newAlpha)
{
	if (this->texture)
	{
		this->textureAlpha = newAlpha;
		SDL_SetTextureAlphaMod(this->texture, this->textureAlpha);
	}
}

Uint8 EE::Components::Graphics::GetTextureAlpha()
{
	return this->textureAlpha;
}