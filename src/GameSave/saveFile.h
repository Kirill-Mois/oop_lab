#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Exceptions/exceptionFile.h"
#include "Exceptions/exceptionLoad.h"

class SaveFile
{
private:
	std::fstream* file;
	std::string fileName;
public:
	SaveFile(std::string fileName, int mode);
	void Write(std::string s);
	std::stringstream Read();
	~SaveFile();
};
