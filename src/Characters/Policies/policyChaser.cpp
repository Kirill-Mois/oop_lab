#include "policyChaser.h"

int PolicyChaser::GetIndex()
{
	return 0;
}
void PolicyChaser::operator+(Player* player)
{
	player->TakeDamage(2);
}
