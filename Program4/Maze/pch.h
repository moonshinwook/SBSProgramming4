#pragma once

// iostream string, window
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Types.h"
using namespace std;


// operator 재정의 == !+ +
// ctrl + m+ o 모든 내용 접기 단축키

struct Pos
{
	bool operator==(Pos& other) {
		return y == other.y && x == other.x; // y를 먼저 쓴다!
	}

	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(Pos& other)
	{
		Pos temp;
		temp.x = x + other.x;
		temp.x = y + other.y;

		return temp;
	}

	Pos& operator+=(Pos& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}



	int32 x = 0;
	int32 y = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,
	
	DIR_COUNT = 4
};

