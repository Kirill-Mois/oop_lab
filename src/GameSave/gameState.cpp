#include "gameState.h"

std::ostream& operator<< (std::ostream& out, const GameState& gameState)
{
	out << gameState.numOfItemPoint << "\n";
	out << gameState.numOfItemHealth << "\n";
	out << gameState.numOfItemEnergy << "\n";
	out << gameState.pointsToWin << "\n";
	out << gameState.playerPoints << "\n";
	out << gameState.playerHealth << "\n";
	out << gameState.playerEnergy << "\n";
	out << gameState.playerPos.first << " " << gameState.playerPos.second << "\n";
	out << gameState.chaserPos.first << " " << gameState.chaserPos.second << "\n";
	out << gameState.ambusherPos.first << " " << gameState.ambusherPos.second << "\n";
	out << gameState.jumperPos.first << " " << gameState.jumperPos.second << "\n";
	for (int i = 0; i < gameState.numOfItemPoint; i++)
		out << gameState.itemPointPos[i].first << " " << gameState.itemPointPos[i].second << "\n";
	for (int i = 0; i < gameState.numOfItemHealth; i++)
		out << gameState.itemHealthPos[i].first << " " << gameState.itemHealthPos[i].second << "\n";
	for (int i = 0; i < gameState.numOfItemEnergy; i++)
		out << gameState.itemEnergyPos[i].first << " " << gameState.itemEnergyPos[i].second << "\n";
	return out;
}

std::stringstream& operator>> (std::stringstream& input, GameState& gameState)
{
	input >> gameState.numOfItemPoint;
	if (gameState.numOfItemPoint < 0)
		throw ExceptionLoad("Load file is corrupted.\n");
	input >> gameState.numOfItemHealth;
	if (gameState.numOfItemHealth < 0)
		throw ExceptionLoad("Load file is corrupted.\n");
	input >> gameState.numOfItemEnergy;
	if (gameState.numOfItemEnergy < 0)
		throw ExceptionLoad("Load file is corrupted.\n");
	input >> gameState.pointsToWin;
	input >> gameState.playerPoints;
	input >> gameState.playerHealth;
	input >> gameState.playerEnergy;
	input >> gameState.playerPos.first >> gameState.playerPos.second;
	input >> gameState.chaserPos.first >> gameState.chaserPos.second;
	input >> gameState.ambusherPos.first >> gameState.ambusherPos.second;
	input >> gameState.jumperPos.first >> gameState.jumperPos.second;
	gameState.itemPointPos = new std::pair<int, int>[gameState.numOfItemPoint];
	for (int i = 0; i < gameState.numOfItemPoint; i++)
		input >> gameState.itemPointPos[i].first >> gameState.itemPointPos[i].second;
	gameState.itemHealthPos = new std::pair<int, int>[gameState.numOfItemHealth];
	for (int i = 0; i < gameState.numOfItemHealth; i++)
		input >> gameState.itemHealthPos[i].first >> gameState.itemHealthPos[i].second;
	gameState.itemEnergyPos = new std::pair<int, int>[gameState.numOfItemEnergy];
	for (int i = 0; i < gameState.numOfItemEnergy; i++)
		input >> gameState.itemEnergyPos[i].first >> gameState.itemEnergyPos[i].second;
	return input;
}
