#pragma once

class Character {
protected:
    int x, y;

public:
    int GetX();
    int GetY();
    void Move(int dx, int dy);
};
