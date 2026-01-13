#include "pch.h"
#include "Player.h"
#include "Board.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init(Board* board)
{
		_pos = board->GetStartPos();
		_board = board;

		// 도착지점에 _pos 도달할때까지 반복한다. 우수법 로직을 while문 안에 구현하기
		// if()		의사 코드를 생각을 해보세요.
		//while ()
		//{
		//
		//}
}

void Player::Update(uint64 deltaTick)
{
	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;


		// 플레이어가 행동하고 싶은 코드
		RandomMove();
	}



}

// 우수법 : 오른쪽 벽을 짚고 길을 쭉 이동하면 언젠가는 미로를 탈출한다.
// 어떻게 움직여야 탈출할 수 있나요? vector<_path>

void Player::RandomMove()
{
	// 플레이어가 상하좌우로 랜덤으로 움직인다.

	Pos moveDir[4] =
	{
		Pos{-1, 0}, // 위
		Pos{0, -1}, // 왼
		Pos{1, 0},  // 아래
		Pos{0, 1},  // 오
	};

	int randValue = rand() % 4;

	// TileType:EMPTY일때만 통과
	if(_board->GetTileType(_pos + moveDir[randValue]) == TileType::EMPTY)
	_pos += moveDir[randValue];
	


}
