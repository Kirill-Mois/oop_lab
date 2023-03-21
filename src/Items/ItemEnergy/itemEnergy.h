#pragma once

#include "../item.h"

class ItemEnergy : public Item {
public:
    void operator+(Player* player);
    int GetIndex();
    friend std::ostream& operator<<(std::ostream& out, ItemEnergy& itemEnergy);
};
