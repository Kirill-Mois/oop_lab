#pragma once

#include "../player.h"

class Policy 
{
public:
    virtual int GetIndex() = 0;
    virtual void operator+(Player* player) = 0;
};
