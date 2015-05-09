#pragma once
/******************************************************************
*                                                                 *
* EE_Entity.h - Declares and defines the basic entity skeleton,   *
*               that should be used with Components.              *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include "EE_BaseComponent.h"
#include <string>
#include <list>
#include <memory>

namespace EE 
{
	class Engine;

	class Entity
	{
	public:
		Entity(Engine *owner, std::string name = "N/A");
		virtual ~Entity();

		void AddComponent(Components::BaseComponent * component);
		virtual void Update(int ticks);
		void Render();
		Engine *owner;

		std::list<std::shared_ptr<Components::BaseComponent>> componentList;

	protected:
		std::string name;
	};
}