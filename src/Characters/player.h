#pragma once
#include "character.h"
#include "../Logs/logPlayer.h"

class LogPlayer;

class Player : public Character
{
private:
    int health;
    int energy;
    int points;
    LogPlayer* logPlayer = nullptr;
public:
    Player(int x, int y);
    int GetHealth();
    int GetEnergy();
    int GetPoints();
    void SetHealth(int health);
    void SetEnergy(int energy);
    void SetPoints(int points);
    void TakeItemHealth();
    void TakeItemEnergy();
    void TakeItemPoint();
    void TakeDamage(int x);
    void UseJump();
    void SetLogPlayer(LogPlayer* logPlayer);
    LogPlayer* GetLogPlayer();
    friend std::ostream& operator<<(std::ostream& out, Player& player);
};
