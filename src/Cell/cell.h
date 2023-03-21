#pragma once

#include "../Items/item.h"
#include "../Characters/player.h"
#include "../Characters/Policies/policyChaser.h"
#include "../Characters/Policies/policyAmbusher.h"
#include "../Characters/Policies/policyJumper.h"

enum class CellType
{
    PATH,
    WALL,
    START,
    END
};

template <class T>
class Enemy;

class Cell
{
private:
    CellType cellType;
    bool isPlayerSet;
    bool isItemSet;
    bool isEnemySet;
    Player* player = nullptr;
    Item* item = nullptr;
    Enemy<PolicyChaser>* chaser = nullptr;
    Enemy<PolicyAmbusher>* ambusher = nullptr;
    Enemy<PolicyJumper>* jumper = nullptr;
public:
    Cell();
    CellType GetCellType();
    void SetCellType(CellType cellType);
    void PlacePlayer(Player* player);
    void RemovePlayer();
    bool IsPlayerSet();
    void SetItem(Item* item);
    void DeleteItem();
    bool IsItemSet();
    Item* GetItem();
    bool IsEnemySet();
    void PlaceChaser(Enemy<PolicyChaser>* enemy);
    void RemoveChaser();
    void PlaceAmbusher(Enemy<PolicyAmbusher>* enemy);
    void RemoveAmbusher();
    void PlaceJumper(Enemy<PolicyJumper>* enemy);
    void RemoveJumper();
    int GetEnemyIndex();
    ~Cell();
};
