#pragma once

#include "../item.h"

class ItemHealth : public Item {
public:
    void operator+(Player* player);
    int GetIndex();
    friend std::ostream& operator<<(std::ostream& out, ItemHealth& itemHealth);
};
