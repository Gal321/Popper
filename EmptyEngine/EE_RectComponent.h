#pragma once
/******************************************************************
*                                                                 *
* EE_RectComponent.h - Declares and defines a rect component      *
*                                                                 *
******************************************************************/

#include "EE_GraphicsComponent.h"

namespace EE
{
	namespace PIG
	{
		class Rect : public Graphics
		{
		public:
			Rect(
				Uint8 red = 0x0,
				Uint8 green = 0x0,
				Uint8 blue = 0x0,
				Uint8 alpha = 0xFF,
				Size size = Size::Get(),
				Point position = Point::Get()
				);
			// using parent destructor

			virtual void Initialize();
			virtual void Update(int ticks);
			virtual void Render();
			virtual void Uninitialize();

			void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
			SDL_Color color;

		protected:
			SDL_Surface *sdlSurface;
		};
	}
}