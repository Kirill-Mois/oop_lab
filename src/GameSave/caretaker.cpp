#include "caretaker.h"

Caretaker::Caretaker(GameManager* gameManager, std::string fileName, int mode)
{
	this->gameManager = gameManager;
	saveFile = new SaveFile(fileName, mode);
}

int Caretaker::Save()
{
	try
	{
		Memento* snapShot = gameManager->SaveGame();
		std::ostringstream tmp;
		tmp << snapShot->GetState();
		saveFile->Write(tmp.str());
		if (snapShot)
			delete snapShot;
		return 0;
	}
	catch (const ExceptionFile& e)
	{
		std::cerr << e.what();
		return 1;
	}
}

int Caretaker::Load()
{
	try
	{
		std::stringstream save = saveFile->Read();
		GameState state;
		save >> state;
		Memento* snapShot = new Memento(state);
		gameManager->LoadGame(snapShot);
		if (snapShot)
			delete snapShot;
		return 0;
	}
	catch (const ExceptionFile& e)
	{
		std::cerr << e.what();
		return 1;
	}
	catch (const ExceptionLoad& e)
	{
		std::cerr << e.what();
		return 1;
	}
}

Caretaker::~Caretaker()
{
	if (saveFile)
		delete saveFile;
}
