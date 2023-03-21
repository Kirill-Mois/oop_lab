#pragma once

#include "../itemFactory.h"
#include "itemHealth.h"

class ItemHealthFactory : public ItemFactory {
public:
    Item* CreateItem();
};
