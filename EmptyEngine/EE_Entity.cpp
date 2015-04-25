#include "EE_Entity.h"

EE::Entity::Entity(Engine *owner,
	               std::string name):
	owner(owner)
{
}

EE::Entity::~Entity()
{
}

void EE::Entity::AddComponent(std::shared_ptr<Components::BaseComponent> component)
{
	// try to bind component to this entity
	// if bind failed exception should be raised by component,
	// which should be handled by  the caller of this fucntion
	component->Bind(this);

	this->componentList.push_back(component);
}

void EE::Entity::Update(int ticks)
{
	for (auto & component : this->componentList)
	{
		component->Update(ticks);
	}
}