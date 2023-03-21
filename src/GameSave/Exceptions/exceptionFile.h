#pragma once

#include "exception.h"

class ExceptionFile : public Exception
{
public:
	ExceptionFile() = default;
	ExceptionFile(const std::string message);
	const char* what() const throw();
};
