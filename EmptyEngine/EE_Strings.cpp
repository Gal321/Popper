#include <string>
#include <sstream>
#include "EE_Strings.h"

std::wstring EE::Utility::StringToWString(const std::string& s)
{
	std::wostringstream oss;
	oss << s.c_str();
	return oss.str();
}

std::string EE::Utility::WStringToString(const std::wstring& s)
{
	std::ostringstream oss;
	oss << s.c_str();
	return oss.str();
}

char16_t *EE::Utility::WStringToUnicode(const std::wstring& s)
{
	int len = s.length();
	char16_t *out = new char16_t[len + 1];
	for (int i = 0; i < len; i++)
		out[i] = s[i];
	out[len] = 0;
	return out;
}
