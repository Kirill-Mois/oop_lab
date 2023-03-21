#pragma once

#include <iostream>
#include <fstream>
#include <string>

class LogFile
{
private:
	std::ofstream* out;
	static int count;
public:
	LogFile();
	void AddLog(std::string s);
	~LogFile();
};
