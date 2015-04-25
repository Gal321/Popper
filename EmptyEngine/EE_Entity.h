#pragma once
/******************************************************************
*                                                                 *
* EE_Entity.h - Declares and defines the basic entity skeleton,   *
*               that should be used with Components.              *
*                                                                 *
******************************************************************/

#include "EE_Engine.h"
#include "EE_Base.h"
#include "EE_BaseComponent.h"
#include <string>
#include <list>
#include <memory>

namespace EE 
{
	class Entity
	{
	public:
		Entity(Engine *owner, std::string name = "N/A");
		virtual ~Entity();

		void AddComponent(std::shared_ptr<Components::BaseComponent> component);
		virtual void Update(int ticks);

		Engine *owner;

	protected:
		std::list<std::shared_ptr<Components::BaseComponent>> componentList; //TODO - allow Components to mess with this
		std::string name;
	};
}