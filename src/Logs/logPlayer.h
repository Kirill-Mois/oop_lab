#pragma once

#include <iostream>
#include "logFile.h"
#include "../Characters/player.h"
#include "../Items/item.h"

class Player;
class Item;

class LogPlayer
{
private:
	Player* player;
	void addLog(std::string s);
public:
	LogPlayer(Player* player);
	void GameStarts(int pointsToWin);
	void PlayerMoves();
	void PlayerCollects(Item* item, int pointsToWin);
	void PlayerJumps();
	void PlayerTakesDamage();
	void GameEnds();
};
