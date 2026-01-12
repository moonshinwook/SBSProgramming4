#pragma once

// 이동할 수 있는가? 벽인가? 

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

class Board
{
public:
	Board();
	~Board();
	
	void Init(int32 size);
	void Render();

	Pos  GetStartPos() { return Pos{ 1, 1 }; }
	Pos  GetEndPos()   { return Pos{ _size - 2, _size - 2 }; }


private:
	TileType _tile[MAX_SIZE][MAX_SIZE];
	int32 _size;
};

