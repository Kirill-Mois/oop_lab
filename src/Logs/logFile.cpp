#include "logFile.h"

int LogFile::count = 0;

LogFile::LogFile()
{
	out = new std::ofstream;
	if (!count)
		out->open("./logs.txt");
	else
		out->open("./logs.txt", std::ios::app);
}

void LogFile::AddLog(std::string s)
{
	*out << "LOG[" << count++ << "]\t" << s << '\n';
}

LogFile::~LogFile()
{
	out->close();
	delete out;
}
