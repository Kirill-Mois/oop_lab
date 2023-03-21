#include "policyJumper.h"

int PolicyJumper::GetIndex()
{
	return 2;
}
void PolicyJumper::operator+(Player* player)
{
	player->TakeDamage(1);
}
