#include "EE_Exceptions.h"

const char* EE::GenericError::what()
{
	return this->toString().c_str();
}

const std::string EE::GenericError::toString()
{
	return "Generic Error";
}