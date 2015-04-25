#include "EE_Exceptions.h"
#include <sstream>
#include <SDL.h>

const char* EE::GenericError::what()
{
	return this->toString().c_str();
}

const std::string EE::GenericError::toString()
{
	return "Generic Error";
}

EE::SDLError::SDLError()
{
	this->sdlErrorString = SDL_GetError();
}

const std::string EE::SDLError::toString()
{
	std::ostringstream errorMsg;
	errorMsg << "SDL Error (" << sdlErrorString << ")";
	return errorMsg.str();
}
