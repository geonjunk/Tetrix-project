#include "ConsoleManager.h"

CM::CM()
{
}

CM::~CM()
{
}
void CM::gotoxy(const int& x, const int& y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
}

void CM::SetColor(const int& color) {
	HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);

}

void CM::SetCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void CM::SetColor(int color, int bgcolor) {
	color &= 0xf;
	bgcolor &= 0xf;
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}