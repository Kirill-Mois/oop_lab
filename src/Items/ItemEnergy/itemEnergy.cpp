#include "itemEnergy.h"

void ItemEnergy::operator+(Player* player)
{
	player->TakeItemEnergy();
}

int ItemEnergy::GetIndex()
{
	return 1;
}

std::ostream& operator<<(std::ostream& out, ItemEnergy& itemEnergy) {
	out << "Player collects 1 energy\n";
	return out;
}
