#pragma once

#include "ConsoleHelper.h"
#include "Player.h"

enum
{
	MAX_SIZE = 30
};


enum class TileType
{
	NONE=0,
	EMPTY,
	WALL,
	INVISIBLE,
};

class player;

struct Monster {
	Pos pos;
};

class Board
{
public:
	Board();
	~Board();
	
	void					Init(int32 size, Player* player);
	void					Render();

	int32					GetSize() { return _size; } // 필요해서 새로 만듦
	Pos						GetStartPos() { return Pos{ 1, 1 }; }
	Pos						GetEndPos()   { return Pos{ _size - 2, _size - 2 }; }

	void					GenerateMap();
	TileType				GetTileType(Pos pos);
	ConsoleColor			GetColorByTileType(Pos pos);
	int32				    _level;
private:
	Player*					_player;
	TileType _tile[MAX_SIZE][MAX_SIZE];
	int32 _size;
	vector<Monster>			_monsters;
	int						_stage = 1; // 현재 스테이지
	
	void					BinaryTree();
	void					BadMap();
	void					Kruskal();
	void					Prim();
	void					UpdateVisibility();
	void					InitMonster(); // 몬스터 초기 배치
	void					NextStage();   // 스테이지 업
};

