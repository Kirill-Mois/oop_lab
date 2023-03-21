#include "field.h"

Field::Field()
{
    this->height = 22;
    this->width = 19;
    if (!field)
    {
        field = new Cell * [height];
        for (int i = 0; i < height; i++)
        {
            field[i] = new Cell[width];
        }

        int myField[22][19] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                               {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                               {1,0,1,0,0,1,1,1,0,1,0,1,1,1,0,0,1,0,1},
                               {1,0,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1},
                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
                               {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
                               {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1},
                               {1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
                               {1,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1},
                               {1,2,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,3,1},
                               {1,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1},
                               {1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
                               {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
                               {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                               {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
                               {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
                               {1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
                               {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
                               {1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                               {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
        start = std::make_pair(1, 10);
        end = std::make_pair(17, 10);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (myField[i][j] == 0)
                    field[i][j].SetCellType(CellType::PATH);
                if (myField[i][j] == 1)
                    field[i][j].SetCellType(CellType::WALL);
                if (myField[i][j] == 2)
                    field[i][j].SetCellType(CellType::START);
                if (myField[i][j] == 3)
                    field[i][j].SetCellType(CellType::END);
            }
        }
    }
}

Field::Field(const Field& other)
{
    this->width = other.width;
    this->height = other.height;
    this->field = new Cell * [height];
    for (int i = 0; i < height; i++)
    {
        this->field[i] = new Cell[width];
        for (int j = 0; j < width; j++)
        {
            this->field[i][j] = other.field[i][j];
        }
    }
}

Field::Field(Field&& other)
{
    this->width = other.width;
    this->height = other.height;
    this->field = other.field;
    other.field = nullptr;
}

Field& Field::operator=(const Field& other)
{
    if (&other == this)
        return *this;
    cleanCells();
    this->width = other.width;
    this->height = other.height;
    this->field = new Cell * [height];
    for (int i = 0; i < height; i++)
    {
        this->field[i] = new Cell[width];
        for (int j = 0; j < width; j++)
        {
            this->field[i][j] = other.field[i][j];
        }
    }
    return *this;
}

Field& Field::operator=(Field&& other)
{
    cleanCells();
    this->width = other.width;
    this->height = other.height;
    this->field = other.field;
    return *this;
}

void Field::cleanCells()
{
    if (field)
    {
        for (int i = 0; i < height; i++)
        {
            delete[] field[i];
        }
        delete[] field;
        field = nullptr;
    }
}

Field* Field::GetInstance()
{
    if (instance == nullptr)
        instance = new Field;
    return instance;
}

int Field::GetHeight()
{
    return height;
}

int Field::GetWidth()
{
    return width;
}

Cell** Field::GetField()
{
    return field;
}

std::pair<int, int> Field::GetStart()
{
    return start;
}

std::pair<int, int> Field::GetEnd()
{
    return end;
}

bool Field::IsWall(int x, int y)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return true;
    return field[y][x].GetCellType() == CellType::WALL;
}

bool Field::IsStartOrEnd(int x, int y)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return false;
    return (field[y][x].GetCellType() == CellType::START || field[y][x].GetCellType() == CellType::END);
}

bool Field::IsPlayerSet(int x, int y)
{
    return field[y][x].IsPlayerSet();
}

bool Field::IsItemSet(int x, int y)
{
    return field[y][x].IsItemSet();
}

Item* Field::GetItem(int x, int y)
{
    return field[y][x].GetItem();
}

bool Field::IsEnemySet(int x, int y)
{
    return field[y][x].IsEnemySet();
}

void Field::SetPlayer(Player* player)
{
    this->player = player;
}
Player* Field::GetPlayer()
{
    return player;
}

void Field::DeleteField()
{
    cleanCells();
    delete instance;
    instance = nullptr;
}

Field* Field::instance = nullptr;
