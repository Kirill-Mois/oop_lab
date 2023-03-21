#include "itemHealth.h"

void ItemHealth::operator+(Player* player)
{
	player->TakeItemHealth();
}

int ItemHealth::GetIndex()
{
	return 0;
}

std::ostream& operator<<(std::ostream& out, ItemHealth& itemHealth) {
	out << "Player collects 1 health\n";
	return out;
}
