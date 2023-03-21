#include "memento.h"

Memento::Memento(GameState state)
{
	this->state = state;
}

GameState Memento::GetState()
{
	return state;
}

Memento::~Memento()
{
	if (state.itemPointPos)
		delete[] state.itemPointPos;
	if (state.itemHealthPos)
		delete[] state.itemHealthPos;
	if (state.itemEnergyPos)
		delete[] state.itemEnergyPos;
}
