#pragma once

#include "policy.h"

class PolicyChaser : public Policy
{
public:
    int GetIndex();
    void operator+(Player* player);
};
