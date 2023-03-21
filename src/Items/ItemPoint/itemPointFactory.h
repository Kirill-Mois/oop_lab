#pragma once

#include "../itemFactory.h"
#include "itemPoint.h"

class ItemPointFactory : public ItemFactory {
public:
    Item* CreateItem();
};
