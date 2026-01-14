#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Player.h"


Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPos(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			// TileType - WALL, EMPTY : 각각의 경우에는 색깔을 지정한 값을 출력하라.

			ConsoleColor color = GetColorByTileType(Pos{ y,x });
			ConsoleHelper::SetCursorColor(color);
			cout << "●";
		}
		cout << endl;
	}
}


// maze for programmers
// binary Tree
void Board::GenerateMap()
{
	BinaryTree();
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x >= _size || pos.x < 0)
		return TileType::NONE;
	if (pos.y >= _size || pos.y < 0)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetColorByTileType(Pos pos)
{
	// 플레이어의 좌표와 pos가 같다면 -> Player 클래스의 필요성. _pos
	if (_player->GetPos() == pos)
		return ConsoleColor::YELLOW;

	if (GetEndPos() == pos)
		return ConsoleColor::WHITE;

	TileType tiletype = GetTileType(pos);

	switch (tiletype)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN;
	case TileType::WALL:
		return ConsoleColor::RED;
	}
}

void Board::BinaryTree()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}

	}
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				continue;

			if (y == _size - 2 && x == _size - 2)
				continue;

			if (y == _size - 2)
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}
			if (x == _size - 2)
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			int randValue = rand() % 2;
			if (randValue == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}

		}

	}
}

// 미로 생성1) 테두리가 벽이고 안에는 전부 길인 맵.