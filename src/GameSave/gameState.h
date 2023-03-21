#pragma once

#include <utility>
#include <sstream>
#include "Exceptions/exceptionLoad.h"

class GameState
{
public:
	int numOfItemPoint;
	int numOfItemHealth;
	int numOfItemEnergy;
	int pointsToWin;
	int playerPoints;
	int playerHealth;
	int playerEnergy;
	std::pair<int, int> playerPos;
	std::pair<int, int> chaserPos;
	std::pair<int, int> ambusherPos;
	std::pair<int, int> jumperPos;
	std::pair<int, int>* itemPointPos = nullptr;
	std::pair<int, int>* itemHealthPos = nullptr;
	std::pair<int, int>* itemEnergyPos = nullptr;

	friend std::ostream& operator<<(std::ostream& out, const GameState& gameState);
	friend std::stringstream& operator>>(std::stringstream& input, GameState& gameState);
};
