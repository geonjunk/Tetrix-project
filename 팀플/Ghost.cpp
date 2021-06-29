#include "Ghost.h"
Ghost::Ghost()
{
}
Ghost::Ghost(bool is)
	:Tetrix(is)
{
}
Ghost::~Ghost()
{
}

void Ghost::game() { // 변화

	int is_gameover = 0;
	char keytemp;
	CM::SetCursorView(false);
	init();
	//Graphics::show_logo();
	is_gameover = 0;
	if (isStory)
		level = 4;
	else {
		level = Graphics::input_data();
	}
	PlaySound(TEXT("유령블록.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	show_total_block();
	now_block = Block(stage_data[level]);
	change(now_block);
	next_block = Block(stage_data[level]);
	change(next_block);
	show_next_block(next_block);
	block_start(now_block);
	show_gamestat();
	show_bottom_block(now_block); // 수정 부분
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
					erase_bottom_block(temp);
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_LEFT:      //왼쪽으로 이동
					if (now_block.getX() > 1)
					{
						erase_cur_block(now_block);
						now_block.setX(now_block.getX() - 1);
						if (strike_check(now_block))
							now_block.setX(now_block.getX() + 1);
						erase_bottom_block(temp);
						show_bottom_block(now_block);
						show_cur_block(now_block);
					}
					break;
				case KEY_RIGHT:      //오른쪽으로 이동

					if (now_block.getX() < 14)
					{
						erase_cur_block(now_block);
						now_block.setX(now_block.getX() + 1);
						if (strike_check(now_block))
							now_block.setX(now_block.getX() - 1);
						erase_bottom_block(temp);
						show_bottom_block(now_block);
						show_cur_block(now_block);
					}
					break;
				case KEY_DOWN:      //아래로 이동
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block);
					show_cur_block(now_block);
					break;
				}
			}
			if (keytemp == 32)   //스페이스바를 눌렀을때
			{
				while (is_gameover == 0)
				{
					is_gameover = move_block(now_block, next_block);
				}
				show_bottom_block(now_block);
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
			}
		}
		if (i%stage_data[level].getSpeed() == 0)
		{
			is_gameover = move_block(now_block, next_block);
			show_bottom_block(now_block);
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
			show_total_block();
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

void Ghost::show_cur_block(Block& b) { // 변화
	switch (b.getShape())
	{
	case 0:
		CM::SetColor(RED);
		break;
	case 1:
		CM::SetColor(BLUE);
		break;
	case 2:
		CM::SetColor(SKY_BLUE);
		break;
	case 3:
		CM::SetColor(WHITE);
		break;
	case 4:
		CM::SetColor(YELLOW);
		break;
	case 5:
		CM::SetColor(VOILET);
		break;
	case 6:
		CM::SetColor(GREEN);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + b.getY()) < 0)
				continue;

			if (block[b.getShape()][b.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
			{
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "■";

			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);

}

void Ghost::erase_cur_block(Block& b) { // 변화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
			{
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "  ";

				//break;

			}
		}
	}
	CM::gotoxy(77, 23);
}

void Ghost::show_total_block() { // 변화
	CM::SetColor(DARK_GRAY);
	for (int i = 0; i<21; i++)
	{
		for (int j = 0; j<14; j++)
		{
			if (j == 0 || j == 13 || i == 20)      //레벨에 따라 외벽 색이 변함
			{
				CM::SetColor((level % 6) + 1);

			}
			else {
				CM::SetColor(DARK_GRAY);
			}
			CM::gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j] == 1)
			{
				cout << "■";
			}
			else if (total_block[i][j] == 2)
			{
				cout << "□";
			}
			else
			{
				cout << "  ";
			}

		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);

}

bool Ghost::strike_check(Block& b) // 변화
{
	int block_dat;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (((b.getX() + j) == 0) || ((b.getX() + j) == 13))
				block_dat = 1;
			else if ((b.getY() + i) == 21)
				block_dat = 1;
			else if (b.getY() + i >= 0 && b.getX() + j > 0 && b.getY() + i < 21 && b.getX() + j < 13)
			{
				if (total_block[b.getY() + i][b.getX() + j] == 2)
				{
					block_dat = 1;
				}
				else
					block_dat = total_block[b.getY() + i][b.getX() + j];
			}
			else
				block_dat = 0;
			if ((block_dat == 1) && ((block[b.getShape()][b.getAngle()][i][j] == 1) || (block[b.getShape()][b.getAngle()][i][j] == 2)))                                                                     //좌측벽의 좌표를 빼기위함
			{
				return true;
			}
		}
	}
	return false;
}

void Ghost::merge_block(Block& b)// 변화
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			total_block[b.getY() + i][b.getX() + j] |= block[b.getShape()][b.getAngle()][i][j];
			if (b.getGhost() == 1)
			{
				if (block[b.getShape()][b.getAngle()][i][j] == 2)
				{
					total_block[b.getY() + i][b.getX() + j] = 2;
				}
			}
		}
	}
	check_full_line();
	show_total_block();

}

int Ghost::move_block(Block& now_block, Block& next_block)// 변화
{
	erase_cur_block(now_block);
	now_block.setY(now_block.getY() + 1);   //블럭을 한칸 아래로 내림		
	if (strike_check(now_block))
	{
		if (now_block.getY() <= 0)   //게임오버
		{

			return 1;
		}
		now_block.setY(now_block.getY() - 1);
		merge_block(now_block);
		rechange(now_block);
		now_block = next_block;
		next_block = Block(stage_data[level]);
		change(next_block);
		block_start(now_block);
		show_next_block(next_block);
		return 2;
	}
	return 0;
}

void Ghost::check_full_line() // 변화
{
	int j;
	for (int i = 0; i<20; i++)
	{
		for (j = 1; j<13; j++)
		{
			if (total_block[i][j] == 0 || total_block[i][j] == 2)
				break;
		}
		if (j == 13)   //한줄이 다 채워졌음
		{
			if (stage_data[level].getLine() != lines)
				lines++;
			show_total_block();
			CM::SetColor(BLUE);
			CM::gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j<13; j++)
			{
				cout << "□";
				Sleep(10);
			}
			CM::gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j<13; j++)
			{
				cout << "  ";
				Sleep(10);
			}

			for (int k = i; k>0; k--)
			{
				for (j = 1; j<13; j++)
					total_block[k][j] = total_block[k - 1][j];
			}
			for (j = 1; j<13; j++)
				total_block[0][j] = 0;
			score += 100 + (level * 10) + (rand() % 10);
			show_gamestat();
		}
	}

}

void Ghost::show_next_block(Block& next_block) // 변화
{
	CM::SetColor((level + 1) % 6 + 1);
	for (int i = 1; i<7; i++)
	{
		CM::gotoxy(33, i);
		for (int j = 0; j<6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}

		}
	}
	switch (next_block.getShape())
	{
	case 0:
		CM::SetColor(RED);
		break;
	case 1:
		CM::SetColor(BLUE);
		break;
	case 2:
		CM::SetColor(SKY_BLUE);
		break;
	case 3:
		CM::SetColor(WHITE);
		break;
	case 4:
		CM::SetColor(YELLOW);
		break;
	case 5:
		CM::SetColor(VOILET);
		break;
	case 6:
		CM::SetColor(GREEN);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + 1) < 0)
				continue;

			if (block[next_block.getShape()][0][j][i] == 1 || block[next_block.getShape()][0][j][i] == 2)
			{
				CM::gotoxy((i + 15) * 2 + ab_x, j + 1 + ab_y);
				cout << "■";

			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);

}

void Ghost::change(Block& block1) // 변화
{
	if (block1.getGhost() == 1)
	{
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{

					if (this->block[block1.getShape()][k][i][j] == 1)
					{
						this->block[block1.getShape()][k][i][j] = 2;
					}
				}
			}
		}
	}
}

void Ghost::rechange(Block& block1) // 변화
{
	if (block1.getGhost() == 1)
	{
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{

					if (this->block[block1.getShape()][k][i][j] == 2)
					{
						this->block[block1.getShape()][k][i][j] = 1;
					}
				}
			}
		}
	}
}

void Ghost::show_bottom_block(Block& b) { // 수정 함수
	temp = b;
	while (!strike_check(temp)) { // 수정 부분
		temp.setY(temp.getY() + 1);
	}
	temp.setY(temp.getY() - 1); //
	switch (temp.getShape())
	{
	case 0:
		CM::SetColor(RED);
		break;
	case 1:
		CM::SetColor(BLUE);
		break;
	case 2:
		CM::SetColor(SKY_BLUE);
		break;
	case 3:
		CM::SetColor(WHITE);
		break;
	case 4:
		CM::SetColor(YELLOW);
		break;
	case 5:
		CM::SetColor(VOILET);
		break;
	case 6:
		CM::SetColor(GREEN);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + temp.getY()) < 0)
				continue;

			if (block[temp.getShape()][temp.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
			{
				CM::gotoxy((i + temp.getX()) * 2 + ab_x, j + temp.getY() + ab_y);
				cout << "□";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}

void Ghost::erase_bottom_block(Block& b) { // 수정 함수

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
			{
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "  ";
			}
			CM::gotoxy(77, 23); // 수정된 부분
		}

	}
}

void Ghost::rotate_block(Block& b)
{
	if (!strike_check(Block(b.getShape(), (b.getAngle() + 1) % 4, b.getX(), b.getY())))
	{
		if (b.getX() < 14) {
			erase_cur_block(b);
			b.setAngle((b.getAngle() + 1) % 4);
			show_cur_block(b);
		}
	}
	else {
		if (b.getShape() == 0 && b.getX() + 3 >= 13) {
			erase_cur_block(b);
			b.setX(b.getX() - 3);
			b.setAngle((b.getAngle() + 1) % 4);
			if (strike_check(b)) {
				b.setX(b.getX() + 3);
				b.setAngle((b.getAngle() + 3) % 4);

				show_cur_block(b);
				return;
			}

			show_cur_block(b);
		}
		else if (b.getX() + 3 >= 13) {
			erase_cur_block(b);
			b.setX(b.getX() - 1);
			b.setAngle((b.getAngle() + 1) % 4);
			if (strike_check(b)) {
				b.setX(b.getX() + 1);
				b.setAngle((b.getAngle() + 3) % 4);

				show_cur_block(b);
				return;
			}

			show_cur_block(b);
		}
	}
}