#pragma once

#include <stdlib.h>
#include <time.h>
#include <utility>
#include <iostream>
#include "../Field/field.h"
#include "../Items/ItemHealth/itemHealth.h"
#include "../Items/ItemHealth/itemHealthFactory.h"
#include "../Items/ItemEnergy/itemEnergy.h"
#include "../Items/ItemEnergy/itemEnergyFactory.h"
#include "../Items/ItemPoint/itemPoint.h"
#include "../Items/ItemPoint/itemPointFactory.h"
#include "../UserInterface/userInterface.h"
#include "../Characters/enemy.h"
#include "../GameSave/caretaker.h"
#include "../GameSave/memento.h"
#include "../GameSave/Exceptions/exceptionLoad.h"

class Caretaker;

class GameManager
{
private:
	Field* field;
	Player* player;
	UserInterface* userInterface;
	Enemy<PolicyChaser>* chaser;
	Enemy<PolicyAmbusher>* ambusher;
	Enemy<PolicyJumper>* jumper;
	int numOfItemPoint;
	int numOfItemHealth;
	int numOfItemEnergy;
	int pointsToWin;
	std::pair<int, int> randomCell();
	void setGameObjects();
	void openNew();
	void parseMove();
	void openLoad();
	void openSave();
	void openHelp(int back);
	void openRules(int back);
	void openItems(int back);
	void openEnemies(int back);
	void openControls(int back);
	void openWin();
	void openLose(int count);
	void openPause();
	void nextMove(int dx, int dy);
public:
	GameManager();
	void OpenMenu();
	Memento* SaveGame();
	void LoadGame(Memento* snapShot);
	~GameManager();
};
