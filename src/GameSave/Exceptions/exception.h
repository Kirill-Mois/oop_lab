#pragma once

#include <string>

class Exception
{
protected:
	std::string message = "\n";
public:
	Exception() = default;
	Exception(const std::string message);
	virtual const char* what() const throw() = 0;
};
