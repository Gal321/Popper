#pragma once
/******************************************************************
*                                                                 *
* EE_Entity.h - Declares and defines the basic entity skeleton,   *
*               that should be used with Components.              *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include "EE_BaseComponent.h"
#include "EE_GraphicComponent.h"
#include <string>
#include <list>
#include <memory>
#include <queue>

namespace EE 
{
	class Engine;

	class Entity
	{
	public:
		Entity(Engine *owner, std::string name = "N/A");
		virtual ~Entity();

		virtual void Update(int ticks);
		void Render();
		Engine *owner;

	protected:
		void AddComponent(Components::Base * component);
		std::list<std::shared_ptr<Components::Base>> componentList;
		std::queue<Components::Graphic *> renderBuffer;
		std::string name;

	};
}