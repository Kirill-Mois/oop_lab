#include "itemPointFactory.h"

Item* ItemPointFactory::CreateItem() {
    return new ItemPoint;
}
