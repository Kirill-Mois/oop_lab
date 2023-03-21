#pragma once

#include "../itemFactory.h"
#include "itemEnergy.h"

class ItemEnergyFactory : public ItemFactory {
public:
    Item* CreateItem();
};
