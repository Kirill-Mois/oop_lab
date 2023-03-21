#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "../Field/field.h"

class UserInterface
{
private:
	Field* field;
public:
	UserInterface();
	std::string ScanCommand();
	void PrintMenu();
	void PrintGame(Player* player, int pointsToWin);
	void PrintHelp();
	void PrintRules();
	void PrintItems();
	void PrintEnemies();
	void PrintControls();
	void PrintPause();
	void PrintWin();
	void PrintLose();
};
