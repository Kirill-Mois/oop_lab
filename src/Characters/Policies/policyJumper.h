#pragma once

#include "policy.h"

class PolicyJumper : public Policy
{
public:
    int GetIndex();
    void operator+(Player* player);
};
