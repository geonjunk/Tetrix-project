#include "gameManager.h"

gameManager::gameManager()
	:clearStage(0), saveStage(0)
{
	t[0] = new Tetrix(true);
	t[1] = new Ghost(true);
	t[2] = new BlackOut(true);
	t[3] = new Rotate(true);
	t[4] = new Reverse(true);
	t[5] = new Boss(true);
}

gameManager::~gameManager()
{
	for (int i = 0; i < 5; i++) {
		delete t[i];
	}
}

void gameManager::gameStart()
{
	while (true) {
		if (!Graphics::show_logo(clearStage)) {
			system("cls");
			CM::SetColor(GRAY);
			story();
		}
		else {
			system("cls");
			CM::SetColor(GRAY);
			arcade();
		}
	}
}

void gameManager::story() {
	while (true) {
		switch (Graphics::show_story(clearStage)) {
		case 6:
			Story::ghost();
			tool(1);
			break;
		case 34:
			Story::blackout();
			tool(2);
			break;
		case 62:
			Story::rotate();
			tool(3);
			break;
		case 90:
			Story::reverse();
			tool(4);
			break;
		case 118:
			Story::boss();
			tool(5);
			break;
		case 0:
			gameStart();
			break;
		}
	}
}

void gameManager::arcade()
{
	switch (Graphics::show_arcade())
	{
	case 6:
		tetrix.game();
		break;
	case 78:
		Story::ending();
		gameStart();
		break;
	case 34:
		ghost.game();
		break;
	case 442:
		Story::ghost();
		break;
	case 62:
		blackout.game();
		break;
	case 806:
		Story::blackout();
		break;
	case 90:
		rotate.game();
		break;
	case 1170:
		Story::rotate();
		break;
	case 118:
		reverse.game();
		break;
	case 1534:
		Story::reverse();
		break;
	case 0:
		gameStart();
		break;
	}
}

void gameManager::tool(int num)
{
	t[num]->game();
	if (t[num]->getIsClear())
	{
		system("cls");
		CM::SetColor(GRAY);
		CM::gotoxy(0, 0);
		saveStage = num;
		if (saveStage >= clearStage)
			clearStage = num;
		if(num == 5){
			Story::ending();
			Story::title();
			Story::endinglogo();
			Story::endingcredit();
			gameStart();
		}
		Story::clear();
		int choice = Graphics::choice_continue();
		if (choice == 12) {
			switch (num + 1) {
			case 2:
				Story::blackout();
				break;
			case 3:
				Story::rotate();
				break;
			case 4:
				Story::reverse();
				break;
			case 5:
				Story::boss();
				break;
			}
			tool(num + 1);
		}
		else if (choice == 14)
			gameStart();
	}
}
