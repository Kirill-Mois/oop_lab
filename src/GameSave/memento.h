#pragma once

#include "gameState.h"

class Memento
{
private:
	GameState state;
public:
	Memento(GameState state);
	GameState GetState();
	~Memento();
};
