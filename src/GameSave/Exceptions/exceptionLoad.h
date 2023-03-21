#pragma once

#include "exception.h"

class ExceptionLoad : public Exception
{
public:
	ExceptionLoad() = default;
	ExceptionLoad(const std::string message);
	const char* what() const throw();
};
