#include "EE_BaseComponent.h"

EE::PIG::BaseComponent::BaseComponent()
	: owner(nullptr)
{

}

EE::PIG::BaseComponent::~BaseComponent()
{
}

void EE::PIG::BaseComponent::Bind(Entity * owner)
{
	this->owner = owner;
}
