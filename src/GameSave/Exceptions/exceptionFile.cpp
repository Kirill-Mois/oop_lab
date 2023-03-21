#include "exceptionFile.h"

ExceptionFile::ExceptionFile(const std::string message)
{
	this->message = message;
}

const char* ExceptionFile::what() const throw()
{
	std::string answer = "File error; " + message;
	return answer.c_str();
}
