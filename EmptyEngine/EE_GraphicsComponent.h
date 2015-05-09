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
	namespace Components
	{
		class Graphics : public BaseComponent
		{
		public:
			Graphics(Size size = Size::Get(),
				     Point position = Point::Get(),
					 Uint8 alpha = 0xFF,
					 bool isVisible = true);

			//handles alpha of texture (if there is one)
			void SetTextureAlpha(Uint8 newAlpha);
			Uint8 GetTextureAlpha();
			
			Size size;
			Point position;

			bool isVisible;

		protected:
			Uint8 textureAlpha;
			SDL_Texture *texture;
		};
	}
}