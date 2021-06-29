#include "Tetrix_Reverse.h"
#include "Tetrix.h"


Reverse::Reverse()
{
}
Reverse::Reverse(bool is)
	:Tetrix(is)
{
}


Reverse::~Reverse()
{
}
void Reverse::change() {

	if (duration > rTime) {
		int pre = rKey;
		do {
			rKey = rand() % 6 + 1;

		} while (rKey == pre);
		start = clock();
		CM::gotoxy(35, 21);
		CM::SetColor(RED);
		cout << "  CHANGE      ";
	}
}
void Reverse::showLevel() {
	if (stage_data[level].getLine()-lines<=20&&stage_data[level].getLine()-lines>10) {
		rTime = 25;
		
	}
	else if (stage_data[level].getLine() - lines <= 10 && stage_data[level].getLine() - lines>3) {
		rTime = 20;
		
	}
	else if (stage_data[level].getLine() - lines <= 3&& stage_data[level].getLine() - lines>1) {
		rTime = 15;
		
	}
	else if (stage_data[level].getLine() - lines <= 1) {
		rTime = 10;
		
	}

}
void Reverse::game() {
	
	is_gameover = 0;
	keytemp;
	CM::SetCursorView(false);
	init();
	if (isStory)
		level = 4;
	else {
		level = Graphics::input_data();
	}
	PlaySound(TEXT("�ٲ�ٲ�.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	is_gameover = 0;
	show_total_block();
	now_block = Block(stage_data[level]);
	next_block = Block(stage_data[level]);
	show_next_block(next_block);
	block_start(now_block);
	show_bottom_block(now_block);
	show_gamestat();
	start = clock();
	rKey = 2;
	for (int i = 1; 1; i++)//1.�������μ������� �ٲ�� �ð����ҽ�Ŵ 2. change ��������
	{
		showLevel();
		change();
		switch (rKey)
		{
		case 1:
			randKey1(i);
			break;
		case 2:
			randKey2(i);
			break;
		case 3:
			randKey3(i);
			break;
		case 4:
			randKey4(i);
			break;
		case 5:
			randKey5(i);
			break;
		case 6:
			randKey6(i);
			break;
		}
		if (is_gameover == 1) {
			isClear = false;
			break;
		}
		else if (stage_data[level].getLine() <= lines&&isStory) {
			isClear = true;
			break;
		}
		CM::gotoxy(35, 21);
		CM::SetColor(BLACK);
		cout << "  CHANGE      ";
	}
	if (score > highScore)
		highScore = score;
	init();

}


void Reverse::randKey1(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;
	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_DOWN:     //ȸ���ϱ�
				erase_bottom_block(temp); //
				rotate_block(now_block);
				show_bottom_block(now_block);
				break;
			case KEY_RIGHT:      //�������� �̵�
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
			case KEY_LEFT:      //���������� �̵�

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
			case KEY_UP:      //�Ʒ��� �̵�
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
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
			show_bottom_block(now_block); //
			show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}
	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();
}
void Reverse::randKey2(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;
	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_UP:      //ȸ���ϱ�
				erase_bottom_block(temp); //
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
					erase_bottom_block(temp); //
					show_bottom_block(now_block); //
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
					erase_bottom_block(temp); //
					show_bottom_block(now_block); //
					show_cur_block(now_block);
				}
				break;
			case KEY_DOWN:      //�Ʒ��� �̵�
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
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
			show_bottom_block(now_block); //
			show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}

	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();

}
void Reverse::randKey3(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;
	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_RIGHT:      //ȸ���ϱ�
				erase_bottom_block(temp); //
				rotate_block(now_block);
				show_bottom_block(now_block);
				break;
			case KEY_UP:      //�������� �̵�
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
			case KEY_DOWN:      //���������� �̵�

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
			case KEY_LEFT:      //�Ʒ��� �̵�
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
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
			show_bottom_block(now_block); //
			show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}

	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();


}
void Reverse::randKey4(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;

	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_LEFT:      //ȸ���ϱ�
				erase_bottom_block(temp); //
				rotate_block(now_block);
				show_bottom_block(now_block);
				break;
			case KEY_DOWN:      //�������� �̵�
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
			case KEY_UP:      //���������� �̵�

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
			case KEY_RIGHT:      //�Ʒ��� �̵�
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
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
			show_bottom_block(now_block); //
			show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}

	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();

}
void Reverse::randKey5(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;

	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_LEFT: //�Ʒ��� 
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
				show_cur_block(now_block);
				break;
			case KEY_DOWN:  //���������� 
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
			case KEY_UP:    //������  
				erase_bottom_block(temp); //
				rotate_block(now_block);
				show_bottom_block(now_block);
				break;
			case KEY_RIGHT: //�����̽���     
				while (is_gameover == 0)
				{
					is_gameover = move_block(now_block, next_block);
				}
				show_bottom_block(now_block); //
				show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
				break;
			}
		}
		if (keytemp == 32)   //��������
		{
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
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}

	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();
}
void Reverse::randKey6(int i) {
	end = clock();
	duration = (end - start) / CLOCKS_PER_SEC;
	if (_kbhit())
	{
		keytemp = _getch();
		if (keytemp == EXT_KEY)
		{
			keytemp = _getch();
			switch (keytemp)
			{
			case KEY_UP:      //ȸ���ϱ�
				while (is_gameover == 0)
				{
					is_gameover = move_block(now_block, next_block);
				}
				show_bottom_block(now_block); //
				show_cur_block(now_block); // ���� ������ �Ǹ� �� ȭ���� ������
				break;
			case KEY_LEFT:      //�������� �̵�
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
			case KEY_RIGHT:      //���������� �̵�

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
			case KEY_DOWN:      //�Ʒ��� �̵�
				is_gameover = move_block(now_block, next_block);
				show_bottom_block(now_block); //
				show_cur_block(now_block);
				break;
			}
		}
		if (keytemp == 32)   //�����̽��ٸ� ��������
		{
			erase_bottom_block(temp); //
			rotate_block(now_block);
			show_bottom_block(now_block);
		}
	}
	if (i%stage_data[level].getSpeed() == 0)
	{
		is_gameover = move_block(now_block, next_block);
		show_bottom_block(now_block); //
		show_cur_block(now_block);
	}
	if (stage_data[level].getLine() <= lines)
	{
		PlaySound(NULL, 0, 0);
		if (isStory) {
			isClear = true;
			return;
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
		isClear = false;
		merge_block(now_block);
		Graphics::show_gameover();
		CM::SetColor(GRAY);
		return;
	}

	CM::gotoxy(77, 23);
	Sleep(15);
	CM::gotoxy(77, 23);
	end = clock();

}
