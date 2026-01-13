#include "pch.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	// 실행하는 시간, 프레임 관리

	uint64 lastTick = 0;

	while (true)
	{
		uint64 currentTick = GetTickCount64();
		uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
		// 입력
		// 
		// 로직
		player.Update(deltaTick);
		// 렌더링
		board.Render();
	}

}