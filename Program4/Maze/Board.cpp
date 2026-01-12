#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size)
{
	_size = size;
}

void Board::Render()
{
	ConsoleHelper::SetCursorPos(0,0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			// 색깔?       c++ 색을 변경하는 방법(콘솔) -> 자주 사용
			// 플레이어
			// 최종 도착지점
			// 길은 동그라미, 벽은 네모 
			ConsoleHelper::SetCursorColor(ConsoleColor::BLUE);
			cout << "●";
		}
		cout << endl;
	}
}
