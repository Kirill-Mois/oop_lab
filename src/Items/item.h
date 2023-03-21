#pragma once

#include "../Characters/player.h"

class Player;

class Item {
public:
    virtual void operator+(Player* player) = 0;
    virtual int GetIndex() = 0;
};
