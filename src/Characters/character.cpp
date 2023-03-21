#include "character.h"

int Character::GetX()
{
    return x;
}

int Character::GetY()
{
    return y;
}

void Character::Move(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}
