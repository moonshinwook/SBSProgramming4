#pragma once

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 10,
	};

public:
	Player();
	~Player();
	
	void			Init(Board* board);
	void			Update(uint64 deltaTick);

	Pos				GetPos() { return _pos; }
	void			SetPos(Pos pos) { _pos = pos; }
private:
	Pos				_pos;
	Board*			_board;
	uint64			_sumTick = 0;

	void			RandomMove();
};

