#pragma once
/******************************************************************
*                                                                 *
* EE_RectComponent.h - Declares and defines a rect component      *
*                                                                 *
******************************************************************/

#include "EE_GraphicComponent.h"

namespace EE
{
	namespace Components
	{
		class Rect : public Graphic
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
			virtual ~Rect();

			virtual void Update(int ticks);
			virtual void Render();

			void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
			SDL_Color color;

		protected:
			virtual void Initialize();
			SDL_Surface *sdlSurface;
		};
	}
}