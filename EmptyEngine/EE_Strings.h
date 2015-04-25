#pragma once
/******************************************************************
*                                                                 *
* EE_Strings.h - Functions to handle strings.                     *
*                                                                 *
******************************************************************/

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
	namespace Utility
	{
		// Convertes string to wide char string
		std::wstring StringToWString(const std::string& s);

		// Convertes wide char string to string
		std::string WStringToString(const std::wstring& s);

		// Convertes wide char string to unicode string
		char16_t *WStringToUnicode(const std::wstring& s);
	}
}
