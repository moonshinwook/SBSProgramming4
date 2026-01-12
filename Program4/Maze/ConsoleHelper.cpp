#include "pch.h"
#include "ConsoleHelper.h"

void ConsoleHelper::SetCursorPos(int32 x, int32 y)
{
	// :: 전역으로 존재하는 것, 개인적으로 만든 것이 아님을 정의
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x),static_cast<SHORT>(y) };
	SetConsoleCursorPosition(output, pos);
}

void ConsoleHelper::SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<int16>(color));
}

void ConsoleHelper::ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo;
	::GetConsoleCursorInfo(output, &cursorinfo);
	cursorinfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorinfo);
}





