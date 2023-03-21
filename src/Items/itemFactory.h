#pragma once

#include "item.h"

class ItemFactory
{
public:
	virtual Item* CreateItem() = 0;
};
