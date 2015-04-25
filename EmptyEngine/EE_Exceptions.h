#pragma once
/******************************************************************
*                                                                 *
* EE_Exceptions.h - Declare and define all basic exceptions.      *
*                                                                 *
******************************************************************/

#include "EE_Base.h"
#include <exception>
#include <string>

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

namespace EE
{
	// Exceptions
	class GenericError : public std::exception
	{
	public:
		const char* what();
		virtual const std::string toString() = 0;
	};

	class SDLError : public GenericError
	{
	public:
		SDLError();
		virtual const std::string toString();
	private:
		std::string sdlErrorString;
	};

}