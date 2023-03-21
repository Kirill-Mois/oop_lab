#pragma once

#include "policy.h"

class PolicyAmbusher : public Policy
{
public:
    int GetIndex();
    void operator+(Player* player);
};
