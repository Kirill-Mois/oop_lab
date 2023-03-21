#pragma once

#include <string>
#include <sstream>
#include "../GameManager/gameManager.h"
#include "memento.h"
#include "saveFile.h"

class GameManager;

class Caretaker
{
private:
	SaveFile* saveFile;
	GameManager* gameManager;
public:
	Caretaker(GameManager* gameManager, std::string fileName, int mode);
	int Save();
	int Load();
	~Caretaker();
};
