#include "logPlayer.h"

LogPlayer::LogPlayer(Player* player)
{
	this->player = player;
	this->player->SetLogPlayer(this);
}

void LogPlayer::addLog(std::string s)
{
	LogFile logFile;
	logFile.AddLog(s);
}

void LogPlayer::GameStarts(int pointsToWin)
{
	std::string s = "Game starts\nHealth: " + std::to_string(player->GetHealth()) + "\nEnergy: " + std::to_string(player->GetEnergy()) + "\nPoints: " + std::to_string(player->GetPoints()) + "/" + std::to_string(pointsToWin) + "\n";
	addLog(s);
}

void LogPlayer::PlayerMoves()
{
	std::string s = "Player moves\nX position: " + std::to_string(player->GetX()) + "\tY position: " + std::to_string(player->GetY()) + "\n";
	addLog(s);
}

void LogPlayer::PlayerCollects(Item* item, int pointsToWin) {
	std::string s;
	switch (item->GetIndex())
	{
	case 0:
		s = "Player collects 1 health\nHealth: " + std::to_string(player->GetHealth()) + "\n";
		break;
	case 1:
		s = "Player collects 1 energy\nEnergy: " + std::to_string(player->GetEnergy()) + "\n";
		break;
	case 2:
		s = "Player collects 1 point\nPoints: " + std::to_string(player->GetPoints()) + "/" + std::to_string(pointsToWin) + "\n";
		break;
	default:
		break;
	}
	addLog(s);
}

void LogPlayer::PlayerJumps() {
	std::string s = "Player uses jump\nEnergy: " + std::to_string(player->GetEnergy()) + "\n";
	addLog(s);
}

void LogPlayer::PlayerTakesDamage() {
	std::string s = "Player takes damage\nHealth: " + std::to_string(player->GetHealth()) + "\n";
	addLog(s);
}

void LogPlayer::GameEnds()
{
	std::string s = "Game ends\n";
	addLog(s);
}
