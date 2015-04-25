#pragma once
/******************************************************************
*                                                                 *
* EE_GraphicEntities.h - The graphic entities that will be draw   *
*                        to the screen                            *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include <memory>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

namespace EE {
	class Engine;

	class GraphicEntity // Abstract graphic object, used as base to all graphic objects 
	{
	public:
		GraphicEntity(
			std::shared_ptr<EE::Engine> container,
			Size size,
			Point pos = Point::Get(),
			Uint8 alpha = 0xFF
			);
		virtual ~GraphicEntity();
		virtual const void DrawObject() = 0;
		inline SDL_Texture *GetTexture() { return this->texture; }
		virtual bool Initialize() = 0;
		virtual void Uninitialize() = 0;
		virtual void Step() = 0;
		inline Uint8 GetAlpha() { return this->alpha; }
		virtual void SetAlpha(Uint8 alpha);

		bool toRender;
		Point pos;
		Size size;

	protected:
		SDL_Renderer *GetRenderer();
		SDL_Window *GetWindow();

		std::shared_ptr<EE::Engine> container;
		Uint8 alpha;
		int fadeTime; // in milisecs
		SDL_Texture *texture;
	};

	class Sprite : public GraphicEntity // aka Image
	{
	public:
		Sprite(
			std::shared_ptr<EE::Engine> container,
			std::wstring filePath = std::wstring(),
			Size size = Size::Get(),
			Point pos = Point::Get(),
			Uint8 alpha = 0xFF
			);
		virtual bool Initialize();
		virtual void Uninitialize();
		virtual const void DrawObject();
		virtual void SetAlpha(Uint8 alpha);
		virtual void Step();

	protected:
		std::wstring filePath;
	};

	class Rect : public GraphicEntity // Rectangle
	{
	public:
		Rect(
			std::shared_ptr<EE::Engine> container,
			Uint8 red = 0x0,
			Uint8 green = 0x0,
			Uint8 blue = 0x0,
			Uint8 alpha = 0xFF,
			Size size = Size::Get(),
			Point pos = Point::Get()
			);
		virtual bool Initialize();
		virtual void Uninitialize();
		virtual const void DrawObject();
		virtual void Step();

		SDL_Color color;
	protected:
		SDL_Surface *sdlSurface;
	};

	class Text : public GraphicEntity // Simple text
	{
	public:
		Text(
			std::shared_ptr<EE::Engine> container,
			Uint8 red = 0x0,
			Uint8 green = 0x0,
			Uint8 blue = 0x0,
			Uint8 alpha = 0xFF,
			std::wstring text = std::wstring(),
			unsigned int fontSize = 22,
			std::string fontName = DEFAULT_FONT,
			Point pos = Point::Get()
			);
		virtual bool Initialize();
		virtual void Uninitialize();
		virtual const void DrawObject();
		void SetText(std::wstring text);
		const std::wstring GetText();
		virtual void Step();

		SDL_Color color;
	protected:
		std::wstring text;
		TTF_Font *font;
		std::string fontName;
		unsigned int fontSize;
	};
}