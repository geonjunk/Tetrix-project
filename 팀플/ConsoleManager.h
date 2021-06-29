#pragma once
#include <Windows.h>
class CM
{
public:
	CM();
	~CM();
	static void gotoxy(const int& x, const int& y);
	static void SetColor(const int& color);
	static void SetCursorView(bool visible);
	static void CM::SetColor(int color, int bgcolor);
};

