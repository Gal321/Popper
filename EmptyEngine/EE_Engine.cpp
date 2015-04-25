#include <SDL_syswm.h>
#include <SDL_ttf.h>
#include "EE_Engine.h"

EE::Engine::Engine(std::wstring title) :
currentState(NOT_RUNNING),
window(nullptr),
renderer(nullptr),
isHotkeyPressed(false)
{
}

EE::Engine::~Engine()
{
	if (!this->window)
		SDL_DestroyWindow(this->window);

	SDL_Quit();
}

void EE::Engine::Update(int Ticks)
{
	SDL_Event event;

	UNREFERENCED_PARAMETER(Ticks);

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			this->SetState(QUIT);
			break;

		case SDL_KEYDOWN:
			this->input.KeyDown(static_cast<EE::Byte>(event.key.keysym.sym));
			break;

		case SDL_KEYUP:
			this->input.KeyUp(static_cast<EE::Byte>(event.key.keysym.sym));
			break;

		case SDL_SYSWMEVENT:
			switch (event.syswm.msg->subsystem)
			{
			case SDL_SYSWM_WINDOWS:
				if (event.syswm.msg->msg.win.msg == 0x312 /* WM_HOTKEY */)
				{
					this->isHotkeyPressed = true;
				}
				break;

			default:
				break;
			}
			break;
		}
	}
}

void EE::Engine::Initialize()
{
	this->SetState(INITIALIZING);

	SDL_SysWMinfo info = { 0 };

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		DEBUG_PRINT("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}

	if (TTF_Init() == -1)
	{
		DEBUG_PRINT("SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}

	//Create window
	this->window = SDL_CreateWindow(this->windowTitle.c_str(),
									SDL_WINDOWPOS_CENTERED,
									150,
									DEFAULT_WIDTH,
									DEFAULT_HEIGHT,
									SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS);
	if (this->window == NULL)
	{
		DEBUG_PRINT("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}

	//Get window surface
	this->renderer = SDL_CreateRenderer(this->window,
										-1,
										SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->renderer == NULL)
	{
		DEBUG_PRINT("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}

	//Enable the custom processing of SDL window manager events
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);

	//Sets the hotkey to show Popper
	if (SDL_GetWindowWMInfo(this->window, &info) == SDL_FALSE)
	{
		DEBUG_PRINT("Couldn't get the system info! SDL_Error: %s\n", SDL_GetError());
		throw EE::SDLError();
	}
	if (RegisterHotKey(info.info.win.window, 1, MOD_CONTROL | MOD_ALT, 'O') == FALSE)
	{
		DEBUG_PRINT("Couldn't set the wanted hotkey! WIN32_Error: %s\n", GetLastError());
		throw EE::SDLError();
	}

	this->SetState(RUNNING);
}

void EE::Engine::Uninitialize()
{
	this->SetState(UNINITIALIZING);

	SDL_DestroyRenderer(this->renderer);

	this->SetState(NOT_RUNNING);
}

void EE::Engine::Render()
{
	SDL_RenderClear(this->renderer);

	SDL_RenderPresent(this->renderer);
}

bool EE::Engine::CheckHotkey()
{
	bool temp = this->isHotkeyPressed;
	this->isHotkeyPressed = false;
	return temp;
}

void EE::Engine::ShowWindow()
{
	SDL_ShowWindow(this->window);
}

void EE::Engine::HideWindow()
{
	// TODO - CLEAR THE DATA

	SDL_HideWindow(this->window);
}