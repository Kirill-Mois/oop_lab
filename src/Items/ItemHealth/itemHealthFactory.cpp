#include "itemHealthFactory.h"

Item* ItemHealthFactory::CreateItem() {
    return new ItemHealth;
}
