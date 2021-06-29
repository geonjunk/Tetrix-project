#include "Rotate.h"

Rotate::Rotate()
{
}
Rotate::Rotate(bool is)
	:Tetrix(is)
{
}
Rotate::~Rotate()
{
}

void Rotate::game() {

		int is_gameover = 0;
		rotate = 0;
		char keytemp;
		CM::SetCursorView(false);
		init();
		//Graphics::show_logo();
		
			rotate = 0;
			is_gameover = 0;
			if (isStory)
				level = 4;
			else {
				level = Graphics::input_data();
			}
			PlaySound(TEXT("돌려돌려.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
			show_total_block();
			now_block = Block(stage_data[level]);
			next_block = Block(stage_data[level]);
			show_next_block(next_block);
			block_start(now_block);
			show_cur_block(now_block);
			show_bottom_block(now_block);
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
							erase_bottom_block(temp); //
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
								erase_bottom_block(temp); //
								show_bottom_block(now_block); //
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
								erase_bottom_block(temp); //
								show_bottom_block(now_block); //
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
				if (i % ((stage_data[level].getSpeed() * 3)) == 0) { // 수정 사안 시간마다 rotate함
					rotate = (rotate + 1) % 4;
					system("cls");
					show_total_block();
					show_next_block(next_block);
					show_gamestat();

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

void Rotate::Rotating(const int& rotate, int* x, int* y) {
	int temp;
	switch (rotate) {
	case 0:
		break;
	case 1:// 반시계 90
		temp = *x; // 실수
		*x = *y;
		*y = 13 - temp;
		break;
	case 2: // 반시계 180
		*x = 13 - *x;
		*y = 20 - *y;
		break;
	case 3:
		temp = *x;
		*x = 20 - *y;
		*y = temp;
		break;
	default:
		break;
	}
}

void Rotate::show_cur_block(Block& b) { // Rotate를 쓰기 위해 수정
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

			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				dis_x = i + b.getX(); // 수정 부분
				dis_y = j + b.getY();
				this->Rotating(rotate, &dis_x, &dis_y); // rotate에 따라서 표기할 위치선정
				CM::gotoxy((dis_x) * 2 + ab_x, dis_y + ab_y);
				cout << "■";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
	
}

void Rotate::erase_cur_block(Block& b) { // Rotate를 쓰기 위해 수정
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				dis_x = i + b.getX(); // 수정 부분
				dis_y = j + b.getY();
				this->Rotating(rotate, &dis_x, &dis_y); // rotate에 따라서 표기할 위치선정
				CM::gotoxy((dis_x) * 2 + ab_x, dis_y + ab_y);
				cout << "  ";
				//break;

			}
		}
	}
	
}

void Rotate::show_total_block() { // Rotate를 쓰기 위해 수정
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
			dis_x = j; // 수정 부분
			dis_y = i;
			this->Rotating(rotate, &dis_x, &dis_y);
			CM::gotoxy((dis_x) * 2 + ab_x, dis_y + ab_y);
			if (total_block[i][j] == 1)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}

		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}

void Rotate::check_full_line() // 돌았을 때 클리어시 표시 수정
{
	int j;
	for (int i = 0; i<20; i++)
	{
		for (j = 1; j<13; j++)
		{
			if (total_block[i][j] == 0)
				break;
		}
		if (j == 13)   //한줄이 다 채워졌음
		{
			if (stage_data[level].getLine() != lines)
				lines++;
			show_total_block();
			CM::SetColor(BLUE);
			switch (rotate) {
			case 0:
				CM::gotoxy(1 * 2 + ab_x, i + ab_y);
				for (j = 1; j < 13; j++)
				{
					cout << "□";
					Sleep(10);
				}
				CM::gotoxy(1 * 2 + ab_x, i + ab_y);
				for (j = 1; j < 13; j++)
				{
					cout << "  ";
					Sleep(10);
				}
				break;
			case 1:
				for (j = 1; j < 13; j++) {
					CM::gotoxy(i * 2 + ab_x, 13 - j + ab_y);
					cout << "□";
					Sleep(10);
				}
				for (j = 1; j < 13; j++) {
					CM::gotoxy(i * 2 + ab_x, 13 - j + ab_y);
					cout << "  ";
					Sleep(10);
				}
				break;
			case 2:
				for (j = 1; j < 13; j++) {
					CM::gotoxy((13 - j) * 2 + ab_x, (20 - i) + ab_y);
					cout << "□";
					Sleep(10);
				}
				for (j = 1; j < 13; j++) {
					CM::gotoxy((13 - j) * 2 + ab_x, (20 - i) + ab_y);
					cout << "  ";
					Sleep(10);
				}
				break;
			case 3:
				for (j = 1; j < 13; j++) {
					CM::gotoxy((20 - i) * 2 + ab_x, j + ab_y);
					cout << "□";
					Sleep(10);
				}
				for (j = 1; j < 13; j++) {
					CM::gotoxy((20 - i) * 2 + ab_x, j + ab_y);
					cout << "  ";
					Sleep(10);
				}
				break;
			default:
				break;
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

void Rotate::show_next_block(Block& next_block) // 옆으로 돌리면서 수정이 필요해짐
{
	CM::SetColor((level + 1) % 6 + 1);
	for (int i = 1; i < 7; i++)
	{
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(33, i);
		else
			CM::gotoxy(53, i);
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

			if (block[next_block.getShape()][0][j][i] == 1)
			{
				if (rotate == 0 || rotate == 2)
					CM::gotoxy((i + 15) * 2 + ab_x, j + 1 + ab_y);
				else
					CM::gotoxy((i + 25) * 2 + ab_x, j + 1 + ab_y);
				cout << "■";

			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
	
}

void Rotate::show_gamestat() // 옆으로 돌리면서 수정이 필요해짐
{
	static int printed_text = 0;
	CM::SetColor(GRAY);
	if (printed_text == 0)
	{
		if (!isStory) {
			if (rotate == 0 || rotate == 2)
				CM::gotoxy(35, 7);
			else
				CM::gotoxy(55, 7);
			cout << "STAGE";
			if (rotate == 0 || rotate == 2)
				CM::gotoxy(35, 15);
			else
				CM::gotoxy(55, 15);
			cout << "HighScore";
			if (rotate == 0 || rotate == 2)
				CM::gotoxy(35, 12);
			else
				CM::gotoxy(55, 12);
			cout << "LINES";
		}
		else {
			if (rotate == 0 || rotate == 2)
				CM::gotoxy(35, 12);
			else
				CM::gotoxy(55, 12);
			cout << "ENEMY HP";
		}
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(35, 9);
		else
			CM::gotoxy(55, 9);
		cout << "SCORE";
	}
	if (!isStory) {
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(41, 7);
		else
			CM::gotoxy(61, 7);
		cout << level + 1;
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(41, 16);
		else
			CM::gotoxy(61, 16);
		cout << setw(4) << highScore;
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(41, 13);
		else
			CM::gotoxy(61, 13);
		cout << setw(4) <<(stage_data[level].getLine() - lines);
	}
	else {
		CM::SetColor(RED);
		if (rotate == 0 || rotate == 2)
			CM::gotoxy(35, 14);
		else
			CM::gotoxy(55, 14);
		cout << setw(7) << "♥";
		CM::SetColor(GRAY);
		cout << " x " << (stage_data[level].getLine() - lines);
		CM::SetColor(15);
	}

	if (rotate == 0 || rotate == 2)
		CM::gotoxy(35, 10);
	else
		CM::gotoxy(55, 10);
	cout << setw(10) << score;
	
}

void Rotate::show_bottom_block(Block& b) {
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

			if (block[temp.getShape()][temp.getAngle()][j][i] == 1)
			{
				dis_x = i + temp.getX(); // 수정 부분
				dis_y = j + temp.getY();
				this->Rotating(rotate, &dis_x, &dis_y); // rotate에 따라서 표기할 위치선정
				CM::gotoxy((dis_x) * 2 + ab_x, dis_y + ab_y);
				cout << "□";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}

void Rotate::erase_bottom_block(Block& b) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				dis_x = i + temp.getX(); // 수정 부분
				dis_y = j + temp.getY();
				this->Rotating(rotate, &dis_x, &dis_y); // rotate에 따라서 표기할 위치선정
				CM::gotoxy((dis_x) * 2 + ab_x, dis_y + ab_y);
				cout << "  ";
			}
			CM::gotoxy(77, 23); // 수정된 부분
		}
	}
}
