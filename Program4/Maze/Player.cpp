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
	_board = board;
	RightHand();

}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size()) // 정해진 수를 넘어가지 못하도록 방지하는 코드
		return;

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		// 경로를 읽어와서 하나씩 움직여라.
		_pos = _path[_pathIndex];
		// 플레이어가 행동하고 싶은 코드
		_pathIndex++;
		// RandomMove();
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
	if (CanGo(_pos + moveDir[randValue]))
		_pos += moveDir[randValue];
	


}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::RightHand()
{
	_pos = _board->GetStartPos();


	Pos pos = _pos;
	Pos dest = _board->GetEndPos();

	_path.clear(); // 내용물 초기화
	_path.push_back(pos); // [시작 위치][다음 위치][][][도착지]

	Pos front[4] =
	{
		Pos{-1, 0}, // 위
		Pos{0, -1}, // 왼
		Pos{1, 0},  // 아래
		Pos{0, 1},  // 오
	};

	int count = 0;
	int maxcount = 1000;

	while (pos != dest)
	{
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		if (count >= maxcount)
			return;
		

		// 1. 오른쪽 방향으로 갈 수 있습니까? 
		if (CanGo(pos + front[newDir]))
		{
			_dir = newDir;
			pos += front[_dir];
			_path.push_back(pos);
			count++;
		}
		// 2. 정면 방향을 갈 수 있습니까?
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 3. 왼쪽으로 회전하세요.
		else
		{
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
	stack<Pos> s;
	// 1. vector<Pos> path. index
	// path[i] == path[i+1] << 되돌아가는 경우이기 때문에 path 지워주자.
	// stack		[0][1][2][3][4][]

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	if (s.empty() == false)
		s.push(_path.back());

	vector<Pos> path; // 새로 만든 path

	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}
	reverse(path.begin(), path.end());
	_path = path;

	
}



// 길찾기
// 문제해결 - 기존 해결 방식보다 뛰어난 문제 해결 방식을 찾는다. 
// 우수법   - 순환하는 미로구조가 아니다. 
// 알고리즘 이론 
// 자료구조
// 그래프 -> 순회방식. 길찾기.