#include "EE_GraphicsComponent.h"

EE::PIG::Graphics::Graphics(Size size,
								   Point position,
								   bool isVisible,
								   Uint8 alpha)
	: BaseComponent(),
	size(size),
	position(position),
	isVisible(isVisible),
	textureAlpha(alpha),
	texture(nullptr)
{
}

EE::PIG::Graphics::~Graphics()
{
	this->Uninitialize();
}

void EE::PIG::Graphics::Bind(Entity * owner)
{
	// binding to owner entity
	this->BaseComponent::Bind(owner);

	//running graphics initalization logic
	this->Initialize();
}

void EE::PIG::Graphics::SetTextureAlpha(Uint8 newAlpha)
{
	if (this->texture)
	{
		this->textureAlpha = newAlpha;
		SDL_SetTextureAlphaMod(this->texture, this->textureAlpha);
	}
}

Uint8 EE::PIG::Graphics::GetTextureAlpha()
{
	return this->textureAlpha;
}