#include "Tetrix.h"

Tetrix::Tetrix()
	:highScore(0), isStory(false)
{
	stage_data[0] = STAGE(40, 20, 1);
	stage_data[1] = STAGE(38, 20, 1);
	stage_data[2] = STAGE(35, 20, 1);
	stage_data[3] = STAGE(30, 20, 1);
	stage_data[4] = STAGE(25, 20, 1);
	stage_data[5] = STAGE(20, 14, 1);
	stage_data[6] = STAGE(15, 14, 1);
	stage_data[7] = STAGE(10, 13, 1);
	stage_data[8] = STAGE(6, 12, 1);
	stage_data[9] = STAGE(4, 11, 99999);
}
Tetrix::Tetrix(bool is)
	:highScore(0), isStory(is)
{
	stage_data[0] = STAGE(40, 20, 20);
	stage_data[1] = STAGE(38, 20, 3);
	stage_data[2] = STAGE(35, 20, 20);
	stage_data[3] = STAGE(30, 20, 20);
	stage_data[4] = STAGE(25, 20, 5);
	stage_data[5] = STAGE(20, 14, 20);
	stage_data[6] = STAGE(15, 14, 20);
	stage_data[7] = STAGE(10, 13, 20);
	stage_data[8] = STAGE(6, 12, 20);
	stage_data[9] = STAGE(4, 11, 99999);
}

Tetrix::~Tetrix()
{
}

void Tetrix::game() {
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
	PlaySound(TEXT("�⺻��Ʈ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	show_total_block();
	now_block = Block(stage_data[level]);
	next_block = Block(stage_data[level]);
	show_next_block(next_block);
	block_start(now_block);
	show_gamestat();
	show_bottom_block(now_block); // ���� �κ�
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
				case KEY_UP:      //ȸ���ϱ�
					erase_bottom_block(temp);
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_LEFT:      //�������� �̵�
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
				case KEY_RIGHT:      //���������� �̵�

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
				case KEY_DOWN:      //�Ʒ��� �̵�
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block);
					show_cur_block(now_block);
					break;
				}
			}
			if (keytemp == 32)   //�����̽��ٸ� ��������
			{
				while (is_gameover == 0)
				{
					is_gameover = move_block(now_block, next_block);
				}
				show_bottom_block(now_block);
				show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
			}
		}
		if (i%stage_data[level].getSpeed() == 0)
		{
			is_gameover = move_block(now_block, next_block);
			show_bottom_block(now_block);
			show_cur_block(now_block);
		}
		if (stage_data[level].getLine() <= lines)   //Ŭ���� ��������
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
			for (int n = 0; n < 14; n++)         //ȭ���� ���� ���� ���� 1�� ä���. 
				total_block[20][n] = 1;

			show_total_block();
			show_next_block(next_block);
			show_gamestat();
		}
		if (is_gameover == 1)
		{
			PlaySound(NULL, 0, 0);
			if (score > highScore)
		    highScore = score;
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
	
	init();

	return;
}


void Tetrix::init() {
	srand((unsigned)time(NULL));

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				total_block[i][j] = 1;
			}
			else {
				total_block[i][j] = 0;
			}
		}
	}

	for (int j = 0; j < 14; j++)         //ȭ���� ���� ���� ���� 1�� ä���. 
		total_block[20][j] = 1;

	//�������� �ʱ�ȭ
	level = 0;
	score = 0;
	lines = 0;
	ab_x = 5;
	ab_y = 1;


}


void Tetrix::show_cur_block(Block& b) {
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
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "��";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);

}


void Tetrix::erase_cur_block(Block& b) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "  ";
				//break;

			}
		}
	}
}


void Tetrix::show_total_block() {
	CM::SetColor(DARK_GRAY);
	for (int i = 0; i<21; i++)
	{
		for (int j = 0; j<14; j++)
		{
			if (j == 0 || j == 13 || i == 20)      //������ ���� �ܺ� ���� ����
			{
				CM::SetColor((level % 6) + 1);

			}
			else {
				CM::SetColor(DARK_GRAY);
			}
			CM::gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j] == 1)
			{
				cout << "��";
			}
			else {
				cout << "  ";
			}

		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);

}


bool Tetrix::strike_check(Block& b)
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
				block_dat = total_block[b.getY() + i][b.getX() + j];
			else
				block_dat = 0;
			if ((block_dat == 1) && (block[b.getShape()][b.getAngle()][i][j] == 1))                                                                     //�������� ��ǥ�� ��������
			{
				return true;
			}
		}
	}
	return false;
}


void Tetrix::merge_block(Block& b)
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			total_block[b.getY() + i][b.getX() + j] |= block[b.getShape()][b.getAngle()][i][j];
		}
	}
	check_full_line();
	show_total_block();

}


void Tetrix::block_start(Block& b)
{
	b.setX(5);
	b.setY(-3);
	b.setAngle(0);
}


int Tetrix::move_block(Block& now_block, Block& next_block)
{
	erase_cur_block(now_block);
	now_block.setY(now_block.getY() + 1);   //���� ��ĭ �Ʒ��� ����		
	if (strike_check(now_block))
	{
		if (now_block.getY() <= 0)   //���ӿ���
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


void Tetrix::rotate_block(Block& b)
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


void Tetrix::check_full_line()
{
	int j;
	for (int i = 0; i<20; i++)
	{
		for (j = 1; j<13; j++)
		{
			if (total_block[i][j] == 0)
				break;
		}
		if (j == 13)   //������ �� ä������
		{
			if (stage_data[level].getLine() != lines)
				lines++;
			show_total_block();
			CM::SetColor(BLUE);
			CM::gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j<13; j++)
			{
				cout << "��";
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


void Tetrix::show_next_block(Block& next_block)
{
	CM::SetColor((level + 1) % 6 + 1);
	for (int i = 1; i<7; i++)
	{
		CM::gotoxy(33, i);
		for (int j = 0; j<6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "��";
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
				CM::gotoxy((i + 15) * 2 + ab_x, j + 1 + ab_y);
				cout << "��";

			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}


void Tetrix::show_gamestat()
{
	static int printed_text = 0;
	CM::SetColor(GRAY);
	if (printed_text == 0)
	{
		CM::gotoxy(35, 9);
		cout << "SCORE";

		if (!isStory) {
			CM::gotoxy(35, 7);
			cout << "STAGE";
			CM::gotoxy(35, 12);
			cout << "LINES";
			CM::gotoxy(35, 15);
			cout << "HighScore";
		}
		else {
			CM::gotoxy(35, 12);
			cout << "ENEMY HP";
		}
	}

	CM::gotoxy(35, 10);
	cout << setw(10) << score;

	if (!isStory) {
		CM::gotoxy(35, 13);
		cout << setw(10) << (stage_data[level].getLine() - lines);
		CM::gotoxy(41, 7);
		cout << level + 1;
		CM::gotoxy(35, 16);
		cout << setw(10) << highScore;
	}
	else {
		CM::gotoxy(35, 14);
		CM::SetColor(RED);
		cout << setw(7) << "��";
		CM::SetColor(GRAY);
		cout << " x " << stage_data[level].getLine() - lines;
		CM::SetColor(15);
	}

}

void Tetrix::show_bottom_block(Block& b) { // ���� �Լ�
	temp = b;
	while (!strike_check(temp)) { // ���� �κ�
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
				CM::gotoxy((i + temp.getX()) * 2 + ab_x, j + temp.getY() + ab_y);
				cout << "��";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}


void Tetrix::erase_bottom_block(Block& b) { // ���� �Լ�

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				CM::gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "  ";
			}
			CM::gotoxy(77, 23); // ������ �κ�
		}

	}
}


bool Tetrix::getIsClear() {
	return isClear;
}