#include "policyAmbusher.h"

int PolicyAmbusher::GetIndex()
{
	return 1;
}
void PolicyAmbusher::operator+(Player* player)
{
	player->TakeDamage(3);
}
