#include "itemEnergyFactory.h"

Item* ItemEnergyFactory::CreateItem() {
    return new ItemEnergy;
}
