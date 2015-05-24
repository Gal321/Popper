#include "EE_Entity.h"

EE::Entity::Entity(Engine *owner,
	               std::string name):
	owner(owner)
{
}

EE::Entity::~Entity()
{
}

void EE::Entity::AddComponent(Components::Base * component)
{
	this->componentList.emplace_back(component);
}

void EE::Entity::Update(int ticks)
{
	for (auto & component : this->componentList)
	{
		component->Update(ticks);
	}
}

void EE::Entity::Render()
{
	while (!renderBuffer.empty)
	{
		Components::Graphic * component = renderBuffer.front;
		renderBuffer.pop();
		component->Render();
	}
}