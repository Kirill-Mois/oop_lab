#include "cell.h"

Cell::Cell()
{
    cellType = CellType::PATH;
    isPlayerSet = false;
    isItemSet = false;
    isEnemySet = false;
}

CellType Cell::GetCellType()
{
    return cellType;
}

void Cell::SetCellType(CellType cellType)
{
    this->cellType = cellType;
}

void Cell::PlacePlayer(Player* player)
{
    isPlayerSet = true;
    this->player = player;
}

void Cell::RemovePlayer()
{
    isPlayerSet = false;
    this->player = nullptr;
}

bool Cell::IsPlayerSet()
{
    return isPlayerSet;
}

void Cell::SetItem(Item* item) {
    isItemSet = true;
    this->item = item;
}

void Cell::DeleteItem()
{
    isItemSet = false;
    if (item)
    {
        delete item;
        item = nullptr;
    }
}

bool Cell::IsItemSet()
{
    return isItemSet;
}

Item* Cell::GetItem()
{
    return item;
}

bool Cell::IsEnemySet()
{
    return isEnemySet;
}

void Cell::PlaceChaser(Enemy<PolicyChaser>* enemy)
{
    isEnemySet = true;
    this->chaser = enemy;
}

void Cell::RemoveChaser()
{
    isEnemySet = false;
    this->chaser = nullptr;
}

void Cell::PlaceAmbusher(Enemy<PolicyAmbusher>* enemy)
{
    isEnemySet = true;
    this->ambusher = enemy;
}

void Cell::RemoveAmbusher()
{
    isEnemySet = false;
    this->ambusher = nullptr;
}

void Cell::PlaceJumper(Enemy<PolicyJumper>* enemy)
{
    isEnemySet = true;
    this->jumper = enemy;
}

void Cell::RemoveJumper()
{
    isEnemySet = false;
    this->jumper = nullptr;
}

int Cell::GetEnemyIndex()
{
    if (chaser)
        return 0;
    if (ambusher)
        return 1;
    return 2;
}

Cell::~Cell()
{
    DeleteItem();
}
