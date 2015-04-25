#include "main.h"

int main(int argc, char* args[])
{
	(argc);
	(args);

	App game;
	int GlobalClock = 0;

	game.GetEngine().Initialize();
	while (game.GetEngine().GetState() != EE::Engine::QUIT)
	{
		game.Update(GlobalClock);
		game.GetEngine().Render();
	}

	return 0;
}

void App::Update(int Ticks)
{
	if (this->engine.CheckHotkey())
	{
		if (!this->isPopperUp)
		{
			this->engine.ShowWindow();
			this->isPopperUp = true;
		}
	}

	if (this->engine.GetInput().IsKeyDown(SDLK_ESCAPE))
	{
		this->engine.HideWindow();
		this->isPopperUp = false;
	}

	engine.Update(Ticks);
}

App::App():
	engine(L"Popper"),
	isPopperUp(false)
{
}

App::~App()
{
}
