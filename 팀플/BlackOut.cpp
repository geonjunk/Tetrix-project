#include "BlackOut.h"

BlackOut::BlackOut()
{
}

BlackOut::BlackOut(bool is)
	:Tetrix(is)
{
}
BlackOut::~BlackOut()
{
}
void BlackOut::game() {

	int is_gameover = 0;
	CM::SetCursorView(false);
	init();
	//Graphics::show_logo();

	is_gameover = 0;
	if (isStory)
		level = 4;
	else {
		level = Graphics::input_data();
	}
	//show_total_block();
	PlaySound(TEXT("Blackout!.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	now_block = Block(stage_data[level]);
	next_block = Block(stage_data[level]);
	show_next_block(next_block);
	block_start(now_block);
	show_gamestat();
	for (int i = 1; 1; i++)
	{
		if (_kbhit())
		{
			keytemp = _getch();
			if (keytemp == EXT_KEY)
			{
				keytemp = _getch();
				switch (keytemp)
				{
				case KEY_UP:      //회전하기
					rotate_block(now_block);
					show_around(now_block);
					break;
				case KEY_LEFT:      //왼쪽으로 이동
					if (now_block.getX() > 1)
					{
						erase_cur_block(now_block);
						now_block.setX(now_block.getX() - 1);
						if (strike_check(now_block))
							now_block.setX(now_block.getX() + 1);
						show_around(now_block);
					}
					break;
				case KEY_RIGHT:      //오른쪽으로 이동

					if (now_block.getX() < 14)
					{
						erase_cur_block(now_block);
						now_block.setX(now_block.getX() + 1);
						if (strike_check(now_block))
							now_block.setX(now_block.getX() - 1);
						show_around(now_block);
					}
					break;
				case KEY_DOWN:      //아래로 이동
					is_gameover = move_block(now_block, next_block);
					show_around(now_block);
					break;
				}
			}
			if (keytemp == 32)   //스페이스바를 눌렀을때
			{
				while (is_gameover == 0)
				{
					is_gameover = move_block(now_block, next_block);
				}
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
			}
		}
		if (i%stage_data[level].getSpeed() == 0)
		{
			is_gameover = move_block(now_block, next_block);

			show_cur_block(now_block);
		}
		if (stage_data[level].getLine() <= lines)   //클리어 스테이지
		{
			PlaySound(NULL, 0, 0);
			if (isStory) {
				isClear = true;
				break;
			}
			level++;
			lines = 0;
			for (int k = 0; k < 20; k++)
			{
				for (int n = 0; n < 14; n++)
				{
					if ((n == 0) || (n == 13))
					{
						total_block[k][n] = 1;
					}
					else {
						total_block[k][n] = 0;
					}
				}
			}
			for (int n = 0; n < 14; n++)         //화면의 제일 밑의 줄은 1로 채운다. 
				total_block[20][n] = 1;
			show_around(now_block);
			show_next_block(next_block);
			show_gamestat();
		}
		if (is_gameover == 1)
		{
			PlaySound(NULL, 0, 0);
			isClear = false;
			merge_block(now_block);
			Graphics::show_gameover();
			CM::SetColor(GRAY);
			break;
		}
		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);

	}
	if (score > highScore)
		highScore = score;
	init();

	return;
}

void BlackOut::show_around(Block& b) {
	switch (keytemp) {
	case KEY_DOWN:
		for (int i = b.getX() - 4; i < b.getX() + 5; i++) {
			if (((i * 2) + ab_x) <= 31) {
				if (b.getY() - 3 + ab_y < 0) {}
				else {
					CM::gotoxy((i * 2) + ab_x, b.getY() - 3 + ab_y);
					cout << "  ";
				}
			}
		}
		break;
	case KEY_LEFT:
		for (int i = b.getY() - 3; i < b.getY() + 6; i++) {
			if ((((b.getX() + 5) * 2) + ab_x) <= 31) {
				if (i + ab_y < 0) {}
				else {
					CM::gotoxy(((b.getX() + 5) * 2) + ab_x, i + ab_y);
					cout << "  ";
				}
			}
		}
		break;
	case KEY_RIGHT:
		for (int i = b.getY() - 3; i < b.getY() + 6; i++) {
			if ((((b.getX() - 5) * 2) + ab_x) <= 31) {
				if (i + ab_y < 0) {}
				else {
					CM::gotoxy(((b.getX() - 5) * 2) + ab_x, i + ab_y);
					cout << "  ";
				}
			}
		}
		break;
	}
	CM::gotoxy(77, 23);
	show_cur_block(b);
	CM::SetColor(DARK_GRAY);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (j == 0 || j == 13 || i == 20)      //레벨에 따라 외벽 색이 변함
			{
				CM::SetColor((level % 6) + 1);

			}
			else {
				CM::SetColor(DARK_GRAY);
			}
			CM::gotoxy((j * 2) + ab_x, i + ab_y);
			if (j < b.getX() + 5 && j > b.getX() - 5 && i < b.getY() + 6 && i > b.getY() - 3) {
				if (total_block[i][j] == 1)
				{
					cout << "■";
				}
			}
		}
	}

	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}

void BlackOut::merge_block(Block& b)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			total_block[b.getY() + i][b.getX() + j] |= block[b.getShape()][b.getAngle()][i][j];
		}
	}
	check_full_line();

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			CM::gotoxy((j * 2) + ab_x, i + ab_y);
			cout << "  ";
		}
	}

}

int BlackOut::move_block(Block& now_block, Block& next_block)
{

	erase_cur_block(now_block);
	now_block.setY(now_block.getY() + 1);   //블럭을 한칸 아래로 내림
	if (!strike_check(now_block)){ //
		if (keytemp != 32) {
			keytemp = KEY_DOWN;
			show_around(now_block);
		}
	}
	if (strike_check(now_block))
	{
		if (now_block.getY() <= 0)   //게임오버
		{

			return 1;
		}
		now_block.setY(now_block.getY() - 1);
		merge_block(now_block);
		now_block = next_block;
		next_block = Block(stage_data[level]);

		block_start(now_block);
		show_next_block(next_block);
		return 2;
	}
	return 0;
}
