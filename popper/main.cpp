#include "main.h"

int main(int argc, char* args[])
{
	App game;
	int GlobalClock = 0;

	if (game.GetEngine().Initialize())
	{
		while (game.GetEngine().EngineState != 1)
		{
			game.Update(GlobalClock);
			game.GetEngine().ERender();
		}
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

	engine.EUpdate(Ticks);
}

App::App():
	engine(L"Popper"),
	isPopperUp(false)
{
}

App::~App()
{
}
