#pragma once
/******************************************************************
*                                                                 *
* EE_Exceptions.h - Declare and define all basic exceptions.      *
*                                                                 *
******************************************************************/

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

	class NetworkError : public GenericError
	{
	public:
		NetworkError(int code = -1);
		virtual const std::string toString();
	private:
		int code;
	};
}