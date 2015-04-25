#pragma once
/******************************************************************
*                                                                 *
* main.h - Declare and define all of the core app features        *
*                                                                 *
******************************************************************/

#include "Base.h"

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

class App
{
public:
	App();
	~App();

	// Update the App in a tick.
	void Update(int Ticks);

	inline EE::Engine &GetEngine() { return this->engine; }

private:
	EE::Engine engine;

	bool isPopperUp;
};
