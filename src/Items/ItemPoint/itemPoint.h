#pragma once

#include "../item.h"

class ItemPoint : public Item {
public:
    void operator+(Player* player);
    int GetIndex();
    friend std::ostream& operator<<(std::ostream& out, ItemPoint& itemPoint);
};
