#include "saveFile.h"

SaveFile::SaveFile(std::string fileName, int mode)
{
	this->fileName = fileName;
	file = new std::fstream;
	switch (mode) {
	case 0:
		file->open(fileName.c_str());
		return;
	case 1:
		file->open(fileName.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
		return;
	default:
		return;
	}
	if (!file->is_open())
		throw ExceptionFile("Can't open the file.\n");
}

void SaveFile::Write(std::string s)
{
	*file << s;
}

std::stringstream SaveFile::Read()
{
	std::stringstream loadStream;
	loadStream << file->rdbuf();
	return loadStream;
}

SaveFile::~SaveFile()
{
	if (file->is_open())
		file->close();
	if(file)
		delete file;
}
