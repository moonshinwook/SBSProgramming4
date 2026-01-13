#pragma once

#include "ConsoleHelper.h"
#include "Player.h"

enum
{
	MAX_SIZE = 100
};


enum class TileType
{
	NON=0,
	EMPTY,
	WALL,
};

class player;

class Board
{
public:
	Board();
	~Board();
	
	void					Init(int32 size, Player* player);
	void					Render();

	Pos						GetStartPos() { return Pos{ 1, 1 }; }
	Pos						GetEndPos()   { return Pos{ _size - 2, _size - 2 }; }

	void					GenerateMap();
	TileType				GetTileType(Pos pos);
	ConsoleColor			GetColorByTileType(Pos pos);
private:
	Player*					_player;
	TileType _tile[MAX_SIZE][MAX_SIZE];
	int32 _size;
	
	void					BinaryTree();
};

