#pragma once
/******************************************************************
*                                                                 *
* EE_Entity.h - Declares and defines the base component class,    *
*               that extends entity functionality.                *
*                                                                 *
******************************************************************/

#include "EE_Base.h"

namespace EE 
{
	class Entity;

	namespace Components
	{
		class BaseComponent
		{
		public:
			BaseComponent();
			virtual ~BaseComponent();
			virtual void Update(int ticks) = 0;

		protected:
			virtual void Initialize() = 0;
		};
	}
}