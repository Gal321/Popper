#pragma once
/******************************************************************
*                                                                 *
* EE_Engine.h - Declare and define all of the core Engine         *
*                  features.                                      *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include "EE_Input.h"
#include "EE_Entity.h"
#include "EE_Exceptions.h"
#include <SDL.h>
#include <list>
#include <memory>


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
		// All engine states, current state saved @ Engine::currentState
		enum EngineState
		{
			NOT_RUNNING,
			INITIALIZING,
			RUNNING,
			QUIT,
			UNINITIALIZING,
		};

		Engine(std::wstring title);
		virtual ~Engine();

		// Creates the appication window and initializes device-independent resources.
		void Initialize();

		// Destroy the device-dependent resources.
		void Uninitialize();

		// Update the Game in a tick.
		void Update(int Ticks);

		// Render a frame.
		void Render();

		// Add an entity
		void AddEntity(Entity * entity);

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

		// Access to SDL renderer object
		inline SDL_Renderer *GetRenderer()
		{
			return this->renderer;
		}

		// Access to SDL window object
		inline SDL_Window *GetWindow()
		{
			return this->window;
		}

		inline void SetState(EngineState nextState)
		{
			this->currentState = nextState;
		}

		inline const EngineState GetState()
		{
			return this->currentState;
		}

	private:
		Input input; // The object that handle all of the user input via keyboard and mouse
		std::string windowTitle;
		SDL_Window *window; // The window we'll be rendering to
		SDL_Renderer *renderer;
		bool isHotkeyPressed;
		EngineState currentState;
		std::list<std::shared_ptr<Entity>> entities;
	};

}