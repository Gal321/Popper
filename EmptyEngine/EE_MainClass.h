#pragma once
/******************************************************************
*                                                                 *
* EE_MainClass.h - Declare and define all of the core Engine      *
*                  features.                                      *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include "EE_Input.h"
#include "EE_GraphicEntities.h"

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

namespace EE {
	class Engine
	{
	public:
		Engine(std::wstring title);
		~Engine();

		// Creates the appication window and initializes device-independent resources.
		bool Initialize();

		// Destroy the device-dependent resources.
		void Uninitialize();

		// Update the Game in a tick.
		void EUpdate(int Ticks);

		// Rander a frame.
		bool ERender();

		// Get the rander target size.
		void GetSize();

		// Gets the latest error message
		std::string GetLastErrorMsg();

		// Check if the hotkey was pressed. THIS WILL TOGGLE THIS FLAG
		bool CheckHotkey();

		// Popup the window
		void ShowWindow();

		// Hide the window
		void HideWindow();

		// Get a const version of the input controller
		const Input &GetInput()
		{
			return this->input;
		}

		// Access to this object
		inline SDL_Renderer *GetRenderer()
		{
			return this->renderer;
		}
		inline SDL_Window *GetWindow()
		{
			return this->window;
		}

		unsigned char EngineState;
	private:
		Input input; // The object that handle all of the user input via keyboard and mouse
		std::string windowTitle;
		SDL_Window *window; // The window we'll be rendering to
		SDL_Renderer *renderer;
		bool isHotkeyPressed;
	};

}