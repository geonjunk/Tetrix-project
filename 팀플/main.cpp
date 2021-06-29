#include<iostream>
#include"gameManager.h"

int main() {
	system("mode con:cols=151 lines=27");
	CM::SetCursorView(false);
	Story::caution();
	Story::pro();
	gameManager g;
	g.gameStart();
	return 0;
}