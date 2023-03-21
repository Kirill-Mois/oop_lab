#include "exceptionLoad.h"

ExceptionLoad::ExceptionLoad(const std::string message)
{
	this->message = message;
}

const char* ExceptionLoad::what() const throw()
{
	std::string answer = "Load error; " + message;
	return answer.c_str();
}
