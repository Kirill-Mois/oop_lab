#pragma once

#include <iostream>
#include "../Cell/cell.h"
#include "../Characters/player.h"

class Cell;

class Field
{
private:
    static Field* instance;
    int height;
    int width;
    Cell** field = nullptr;
    Player* player = nullptr;
    std::pair<int, int> start;
    std::pair<int, int> end;
    Field();
    Field(const Field& other);
    Field(Field&& other);

    Field& operator = (const Field& other);
    Field& operator = (Field&& other);

    void cleanCells();

public:
    static Field* GetInstance();
    int GetHeight();
    int GetWidth();
    Cell** GetField();
    std::pair<int, int> GetStart();
    std::pair<int, int> GetEnd();
    bool IsWall(int x, int y);
    bool IsStartOrEnd(int x, int y);
    bool IsPlayerSet(int x, int y);
    bool IsItemSet(int x, int y);
    Item* GetItem(int x, int y);
    bool IsEnemySet(int x, int y);
    void SetPlayer(Player* player);
    Player* GetPlayer();
    void DeleteField();
};
