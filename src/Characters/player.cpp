#include "player.h"

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
	health = 6;
	energy = 3;
	points = 0;
}

int Player::GetHealth()
{
	return health;
}

int Player::GetEnergy()
{
	return energy;
}

int Player::GetPoints()
{
	return points;
}

void Player::SetHealth(int health)
{
	this->health = health;
}

void Player::SetEnergy(int energy)
{
	this->energy = energy;
}

void Player::SetPoints(int points)
{
	this->points = points;
}

void Player::TakeItemHealth()
{
	this->health++;
}

void Player::TakeItemEnergy()
{
	this->energy++;
}

void Player::TakeItemPoint()
{
	this->points++;
}

void Player::TakeDamage(int x)
{
	this->health -= x;
}

void Player::UseJump() {
	this->energy--;
}

void Player::SetLogPlayer(LogPlayer* logPlayer)
{
	this->logPlayer = logPlayer;
}

LogPlayer* Player::GetLogPlayer()
{
	return logPlayer;
}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	out << "X position: " << player.GetX() << "\tY position: " << player.GetY() << "\nHealth: " << player.GetHealth() << "\nItemPoints: " << player.GetPoints() << "\nEnergy: " << player.GetEnergy() << "\n";
	return out;
}
