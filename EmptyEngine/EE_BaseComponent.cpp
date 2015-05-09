#include "EE_BaseComponent.h"

EE::Components::BaseComponent::BaseComponent()
	: owner(nullptr)
{

}

EE::Components::BaseComponent::~BaseComponent()
{
}

void EE::Components::BaseComponent::Bind(Entity * owner)
{
	this->owner = owner;
	this->Initialize();
}
