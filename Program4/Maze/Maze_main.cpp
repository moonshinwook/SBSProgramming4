#include "pch.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	board.Init(25);

	while (true)
	{
		// 입력
		// 로직
		// 렌더링
		board.Render();
	}

}