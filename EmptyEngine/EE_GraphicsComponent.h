#pragma once
/******************************************************************
*                                                                 *
* EE_GraphicsComponent.h - Declares and defines the graphics      *
*               component class, used to handle rendering of      *
*   			graphical entities.                               *
*                                                                 *
******************************************************************/

#include <SDL.h>
#include "EE_Base.h"
#include "EE_BaseComponent.h"

namespace EE
{
	namespace PIG
	{
		class Graphics : public BaseComponent
		{
		public:
			Graphics(Size size = Size::Get(),
				     Point position = Point::Get(),
					 bool isVisible = true,
					 Uint8 alpha = 0xFF);
			virtual ~Graphics();

			virtual void Bind(Entity * owner);

			virtual void Initialize() = 0;
			virtual void Update(int ticks) = 0;
			virtual void Render() = 0;
			virtual void Uninitialize() = 0;

			//handles alpha of texture (if there is one)
			void SetTextureAlpha(Uint8 newAlpha);
			Uint8 GetTextureAlpha();
			
			bool isVisible;
			
			Size size;
			Point position;

		protected:
			Uint8 textureAlpha;
			SDL_Texture *texture;
		};
	}
}