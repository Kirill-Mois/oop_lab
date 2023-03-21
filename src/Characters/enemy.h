#pragma once

#include "character.h"
#include "player.h"
#include "../Field/field.h"

class Field;

template <class T>
class Enemy : public Character
{
private:
	T* policy;

	void moveChaser()
	{
		Field* field = field->GetInstance();
		Player* player = field->GetPlayer();
		int width = field->GetWidth();
		int height = field->GetHeight();
		int** pathfinder = new int* [height];
		for (int i = 0; i < height; i++)
		{
			pathfinder[i] = new int[width];
			for(int j = 0; j < width; j++)
			{
				if (field->IsWall(j, i))
					pathfinder[i][j] = -2;
				else
					pathfinder[i][j] = -1;
			}
		}
		pathfinder[y][x] = 0;
		pathfinder[player->GetY()][player->GetX()] = -3;
		int wave = 0;
		bool foundEnd = false;
		bool foundEmpty = false;
		while (!foundEnd)
		{
			foundEmpty = false;
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (pathfinder[i][j] == wave)
					{
						if (i < height - 1)
						{
							if (pathfinder[i + 1][j] == -3)
							{
								pathfinder[i + 1][j] = wave + 1;
								foundEnd = true;
								break;
							}
							else if (pathfinder[i + 1][j] == -1)
							{
								pathfinder[i + 1][j] = wave + 1;
								foundEmpty = true;
							}
						}

						if (i > 0)
						{
							if (pathfinder[i - 1][j] == -3)
							{
								pathfinder[i - 1][j] = wave + 1;
								foundEnd = true;
								break;
							}
							else if (pathfinder[i - 1][j] == -1)
							{
								pathfinder[i - 1][j] = wave + 1;
								foundEmpty = true;
							}
						}

						if (j < width - 1)
						{
							if (pathfinder[i][j + 1] == -3)
							{
								pathfinder[i][j + 1] = wave + 1;
								foundEnd = true;
								break;
							}
							else if (pathfinder[i][j + 1] == -1)
							{
								pathfinder[i][j + 1] = wave + 1;
								foundEmpty = true;
							}
						}

						if (j > 0)
						{
							if (pathfinder[i][j - 1] == -3)
							{
								pathfinder[i][j - 1] = wave + 1;
								foundEnd = true;
								break;
							}
							else if (pathfinder[i][j - 1] == -1)
							{
								pathfinder[i][j - 1] = wave + 1;
								foundEmpty = true;
							}
						}
					}
				}
			}
			if (!foundEnd && !foundEmpty)
				break;
			wave++;
		}
		int curX = player->GetX();
		int curY = player->GetY();
		bool isMoved = false;
		int destinationX = 0;
		int destinationY = 0;
		while (curX != x || curY != y)
		{
			isMoved = false;
			for (int dy = -1; dy <= 1 && !isMoved; dy++) {
				for (int dx = -1; dx <= 1 && !isMoved; dx++) {
					if (abs(dy) + abs(dx) != 1 || curX + dx > width || curY + dy > height || curX + dx < 0 || curY + dy < 0)
						continue;
					if (pathfinder[curY + dy][curX + dx] < 0)
						continue;
					if (pathfinder[curY + dy][curX + dx] == pathfinder[curY][curX] - 1)
					{
						curX += dx;
						curY += dy;
						destinationX = -1 * dx;
						destinationY = -1 * dy;
						isMoved = true;
						break;
					}
				}
			}
		}
		if(!field->IsEnemySet(x + destinationX, y + destinationY) && !(field->IsStartOrEnd(player->GetX(), player->GetY()) && player->GetX() == x + destinationX && player->GetY() == y + destinationY))
			Move(destinationX, destinationY);

		for (int i = 0; i < height; i++) {
			delete[] pathfinder[i];
		}
		delete[] pathfinder;
	}

	void moveAmbusher()
	{
		Field* field = field->GetInstance();
		Player* player = field->GetPlayer();
		if (player->GetX() >= x - 1 && player->GetX() <= x + 1 && player->GetY() >= y - 1 && player->GetY() <= y + 1)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(player->GetX() - x, player->GetY() - y);
			return;
		}
		int marginX;
		int marginY;
		if (player->GetX() < field->GetWidth() / 2)
			marginX = 0;
		else
			marginX = 1;

		if (player->GetY() < field->GetHeight() / 2)
			marginY = 0;
		else
			marginY = 1;

		int newX = rand() % (field->GetWidth() / 2) + marginX * field->GetWidth() / 2;
		int newY = rand() % (field->GetHeight() / 2) + marginY * field->GetHeight() / 2;
		while (field->IsWall(newX, newY) || field->IsEnemySet(newX, newY) || field->IsPlayerSet(newX, newY))
		{
			newX = rand() % (field->GetWidth() / 2) + marginX * field->GetWidth() / 2;
			newY = rand() % (field->GetHeight() / 2) + marginY * field->GetHeight() / 2;
		}
		Move(newX - x, newY - y);
	}

	void moveJumper()
	{
		Field* field = field->GetInstance();
		Player* player = field->GetPlayer();
		if (player->GetX() == x + 1 && player->GetY() == y + 2)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(1, 2);
			return;
		}
		if (player->GetX() == x + 2 && player->GetY() == y + 1)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(2, 1);
			return;
		}
		if (player->GetX() == x - 1 && player->GetY() == y + 2)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(-1, 2);
			return;
		}
		if (player->GetX() == x - 2 && player->GetY() == y + 1)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(-2, 1);
			return;
		}
		if (player->GetX() == x + 2 && player->GetY() == y - 1)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(2, -1);
			return;
		}
		if (player->GetX() == x + 1 && player->GetY() == y - 2)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(1, -2);
			return;
		}
		if (player->GetX() == x - 1 && player->GetY() == y - 2)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(-1, -2);
			return;
		}
		if (player->GetX() == x - 2 && player->GetY() == y - 1)
		{
			if (!(field->IsStartOrEnd(player->GetX(), player->GetY())))
				Move(-2, -1);
			return;
		}

		if (player->GetY() >= y && player->GetX() >= x)
		{
			if (!field->IsWall(x + 1, y + 2))
			{
				if (!field->IsEnemySet(x + 1, y + 2))
				{
					Move(1, 2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y + 1))
			{
				if (!field->IsEnemySet(x + 2, y + 1))
				{
					Move(2, 1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y + 2))
			{
				if (!field->IsEnemySet(x - 1, y + 2))
				{
					Move(-1, 2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y - 1))
			{
				if (!field->IsEnemySet(x + 2, y - 1))
				{
					Move(2, -1);
					return;
				}
			}
			if (!field->IsWall(x - 2, y + 1))
			{
				if (!field->IsEnemySet(x - 2, y + 1))
				{
					Move(-2, 1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y - 2))
			{
				if (!field->IsEnemySet(x + 1, y - 2))
				{
					Move(1, -2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y - 1))
			{
				if (!field->IsEnemySet(x - 2, y - 1))
				{
					Move(-2, -1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y - 2))
			{
				if (!field->IsEnemySet(x - 1, y - 2))
				{
					Move(-1, -2);
					return;
				}
			}
		}
		else if (player->GetY() >= y && player->GetX() < x)
		{
			if (!field->IsWall(x - 1, y + 2))
			{
				if (!field->IsEnemySet(x - 1, y + 2))
				{
					Move(-1, 2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y + 1))
			{
				if (!field->IsEnemySet(x - 2, y + 1))
				{
					Move(-2, 1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y + 2))
			{
				if (!field->IsEnemySet(x + 1, y + 2))
				{
					Move(1, 2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y - 1))
			{
				if (!field->IsEnemySet(x - 2, y - 1))
				{
					Move(-2, -1);
					return;
				}
			}
			if (!field->IsWall(x + 2, y + 1))
			{
				if (!field->IsEnemySet(x + 2, y + 1))
				{
					Move(2, 1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y - 2))
			{
				if (!field->IsEnemySet(x - 1, y - 2))
				{
					Move(-1, -2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y - 1))
			{
				if (!field->IsEnemySet(x + 2, y - 1))
				{
					Move(2, -1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y - 2))
			{
				if (!field->IsEnemySet(x + 1, y - 2))
				{
					Move(1, -2);
					return;
				}
			}
		}
		else if (player->GetY() < y && player->GetX() >= x)
		{
			if (!field->IsWall(x + 1, y - 2))
			{
				if (!field->IsEnemySet(x + 1, y - 2))
				{
					Move(1, -2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y - 1))
			{
				if (!field->IsEnemySet(x + 2, y - 1))
				{
					Move(2, -1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y - 2))
			{
				if (!field->IsEnemySet(x - 1, y - 2))
				{
					Move(-1, -2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y + 1))
			{
				if (!field->IsEnemySet(x + 2, y + 1))
				{
					Move(2, 1);
					return;
				}
			}
			if (!field->IsWall(x - 2, y - 1))
			{
				if (!field->IsEnemySet(x - 2, y - 1))
				{
					Move(-2, -1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y + 2))
			{
				if (!field->IsEnemySet(x + 1, y + 2))
				{
					Move(1, 2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y + 1))
			{
				if (!field->IsEnemySet(x - 2, y + 1))
				{
					Move(-2, 1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y + 2))
			{
				if (!field->IsEnemySet(x - 1, y + 2))
				{
					Move(-1, 2);
					return;
				}
			}
		}
		else if (player->GetY() < y && player->GetX() < x)
		{
			if (!field->IsWall(x - 1, y - 2))
			{
				if (!field->IsEnemySet(x - 1, y - 2))
				{
					Move(-1, -2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y - 1))
			{
				if (!field->IsEnemySet(x - 2, y - 1))
				{
					Move(-2, -1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y - 2))
			{
				if (!field->IsEnemySet(x + 1, y - 2))
				{
					Move(1, -2);
					return;
				}
			}
			if (!field->IsWall(x - 2, y + 1))
			{
				if (!field->IsEnemySet(x - 2, y + 1))
				{
					Move(-2, 1);
					return;
				}
			}
			if (!field->IsWall(x + 2, y - 1))
			{
				if (!field->IsEnemySet(x + 2, y - 1))
				{
					Move(2, -1);
					return;
				}
			}
			if (!field->IsWall(x - 1, y + 2))
			{
				if (!field->IsEnemySet(x - 1, y + 2))
				{
					Move(-1, 2);
					return;
				}
			}
			if (!field->IsWall(x + 2, y + 1))
			{
				if (!field->IsEnemySet(x + 2, y + 1))
				{
					Move(2, 1);
					return;
				}
			}
			if (!field->IsWall(x + 1, y + 2))
			{
				if (!field->IsEnemySet(x + 1, y + 2))
				{
					Move(1, 2);
					return;
				}
			}
		}
	}

public:
	Enemy(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->policy = new T;
	}

	T* GetPolicy()
	{
		return policy;
	}

	void MakeMove()
	{
		switch (policy->GetIndex())
		{
		case 0:
			moveChaser();
			break;
		case 1:
			moveAmbusher();
			break;
		case 2:
			moveJumper();
			break;
		default:
			break;
		}
	}
	
	~Enemy()
	{
		if (policy)
			delete policy;
	}
};