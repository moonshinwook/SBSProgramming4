#pragma once

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 50,
	};

public:
	Player();
	~Player();
	
	void			Init(Board* board);
	void			Update(uint64 deltaTick);

	Pos				GetPos() { return _pos; }
	void			SetPos(Pos pos) { _pos = pos; }
private:

	vector<Pos>		_path; // list나 다른 것을 사용 시에는 어떻게 될까? 복습차원에서 주말에 시도해보기.
	int32			_pathIndex = 0;
	Pos				_pos;
	Board*			_board;
	uint64			_sumTick = 0;
	int32			_dir = DIR_UP;
	void			RandomMove();
	bool			CanGo(Pos pos);

private:
	void			RightHand();
};


// RandomMove - 탈출 불가.
// RightHand  - 문제가 있다. 
// bool true false
// Pos[25][25] = false(true) << 가지마라.
// 그래프. 길이 2개보다 많다. 

