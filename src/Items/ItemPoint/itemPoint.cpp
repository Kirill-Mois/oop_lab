#include "itemPoint.h"

void ItemPoint::operator+(Player* player)
{
	player->TakeItemPoint();
}

int ItemPoint::GetIndex()
{
	return 2;
}

std::ostream& operator<<(std::ostream& out, ItemPoint& itemPoint) {
	out << "Player collects 1 point\n";
	return out;
}
