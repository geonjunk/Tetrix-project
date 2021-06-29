#include "Boss.h"

Boss::Boss()
{
}
Boss::Boss(bool is) : Tetrix(is)
{
}
Boss::~Boss()
{
}
void Boss::game() {
	rotate = 0;
	CM::SetCursorView(false);
	init();
	is_gameover = 0;
	if (isStory)
		level = 1;
	else {
		level = Graphics::input_data();
	}
	PlaySound(TEXT("보스.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	game_change = rand()%4;
	if (game_change == 2) {
		start = clock(); // Reverse
		rKey = 2; // Reverse
	}

	switch (game_change) {
	case 1: // BlackOut
		break;
	case 2: // 키바꾸기
	case 3: // Rorate
	case 0: // 유령블록
		show_total_block();
		break;
	}
	now_block = Block(stage_data[level]);
	next_block = Block(stage_data[level]);
	show_next_block(next_block);
	block_start(now_block);
	show_gamestat();
	switch (game_change) {
	case 1: // BlackOut
		break;
	case 0: // 유령 블록
	case 2: // Reverse
	case 3: // Rotate
		Rshow_cur_block(now_block);
		Rshow_bottom_block(now_block);
		break;
	}
	for (int i = 1; 1; i++) {
		if (checkBRotate) { // 전이 로테이트였는지 확인
			system("cls");
			show_total_block();
			show_next_block(next_block);
			show_gamestat();
			show_cur_block(now_block);
			show_bottom_block(now_block);
			checkBRotate = false;
			rotate = 0;
		}
		if (checkBBlack) {
			system("cls");
			show_total_block();
			show_next_block(next_block);
			show_gamestat();
			show_cur_block(now_block);
			show_bottom_block(now_block);
			checkBBlack = false;
		}
		if (checkBlack) { // 현재가 블랙인지 확인
			system("cls");
			show_next_block(next_block);
			show_gamestat();
			checkBlack = false;
		}
		if (checkReverse) {
			start = clock(); // Reverse
			rKey = 2; // Reverse
			checkReverse = false;
		}
		if (game_change == 0) // 클리어 라인 할 때 -> 3개씩 클리어할 때마다 변경 -> 변수 : int game_change -> rand % 4
							  // 유령 블록 -> 각 함수들의 :: 연산자로 어떠한 것인지 표기하여야함
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
		else if (game_change == 1)
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
						Bshow_around(now_block);
						break;
					case KEY_LEFT:      //왼쪽으로 이동
						if (now_block.getX() > 1)
						{
							erase_cur_block(now_block);
							now_block.setX(now_block.getX() - 1);
							if (strike_check(now_block))
								now_block.setX(now_block.getX() + 1);
							Bshow_around(now_block);
						}
						break;
					case KEY_RIGHT:      //오른쪽으로 이동

						if (now_block.getX() < 14)
						{
							erase_cur_block(now_block);
							now_block.setX(now_block.getX() + 1);
							if (strike_check(now_block))
								now_block.setX(now_block.getX() - 1);
							Bshow_around(now_block);
						}
						break;
					case KEY_DOWN:      //아래로 이동
						is_gameover = Bmove_block(now_block, next_block);
						Bshow_around(now_block);
						break;
					}
				}
				if (keytemp == 32)   //스페이스바를 눌렀을때
				{
					while (is_gameover == 0)
					{
						is_gameover = Bmove_block(now_block, next_block);
					}
					show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
				}
			}
			if (i%stage_data[level].getSpeed() == 0)
			{
				is_gameover = Bmove_block(now_block, next_block);

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
				Bshow_around(now_block);
				show_next_block(next_block);
				show_gamestat();
			}
			if (is_gameover == 1)
			{
				PlaySound(NULL, 0, 0);
				isClear = false;
				Bmerge_block(now_block);
				Graphics::show_gameover();
				CM::SetColor(GRAY);
				break;
			}
			CM::gotoxy(77, 23);
			Sleep(15);
			CM::gotoxy(77, 23);
		}
		else if (game_change == 2)
		{
			if (checkBRotate) {
				i = 0;
				rotate = 0;
				checkBRotate = false;
			}
			showLevel();
			Rchange();
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
		else if (game_change == 3)
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
						Rerase_bottom_block(temp); //
						Rrotate_block(now_block);
						Rshow_bottom_block(now_block);
						break;
					case KEY_LEFT:      //왼쪽으로 이동
						if (now_block.getX() > 1)
						{
							Rerase_cur_block(now_block);
							now_block.setX(now_block.getX() - 1);
							if (strike_check(now_block))
								now_block.setX(now_block.getX() + 1);
							Rerase_bottom_block(temp); //
							Rshow_bottom_block(now_block); //
							Rshow_cur_block(now_block);
						}
						break;
					case KEY_RIGHT:      //오른쪽으로 이동

						if (now_block.getX() < 14)
						{
							Rerase_cur_block(now_block);
							now_block.setX(now_block.getX() + 1);
							if (strike_check(now_block))
								now_block.setX(now_block.getX() - 1);
							Rerase_bottom_block(temp); //
							Rshow_bottom_block(now_block); //
							Rshow_cur_block(now_block);
						}
						break;
					case KEY_DOWN:      //아래로 이동
						is_gameover = Rmove_block(now_block, next_block);
						Rshow_bottom_block(now_block);
						Rshow_cur_block(now_block);
					}
				}
				if (keytemp == 32)   //스페이스바를 눌렀을때
				{
					while (is_gameover == 0)
					{
						is_gameover = Rmove_block(now_block, next_block);
					}
					Rshow_bottom_block(now_block);
					Rshow_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌

				}
			}
			if (i % ((stage_data[level].getSpeed() * 4)) == 0) { // 시간마다 rotate함
				rotate = (rotate + 1) % 4;
				system("cls");
				Rshow_total_block();
				Rshow_next_block(next_block);
				Rshow_gamestat();

			}
			if (i%stage_data[level].getSpeed() == 0)
			{
				is_gameover = Rmove_block(now_block, next_block);
				Rshow_bottom_block(now_block);
				Rshow_cur_block(now_block);
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
				Rshow_total_block();
				Rshow_next_block(next_block);
				Rshow_gamestat();
			}
			if (is_gameover == 1)
			{
				PlaySound(NULL, 0, 0);
				isClear = false;
				Rmerge_block(now_block);
				Graphics::show_gameover();
				CM::SetColor(GRAY);
				break;
			}

			CM::gotoxy(77, 23);
			Sleep(15);
			CM::gotoxy(77, 23);
		}
	}
	if (score > highScore)
		highScore = score;
	init();
	return;
}
//Ghostblock
void Boss::show_cur_block(Block& b) { // 변화
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
void Boss::erase_cur_block(Block& b) { // 변화
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
void Boss::show_total_block() { // 변화
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
bool Boss::strike_check(Block& b) // 변화
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
					block_dat = total_block[b.getY() + i][b.getX() + j];
					if (total_block[b.getY() + i][b.getX() + j] == 2)
					{
						block_dat = 1;
					}
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
void Boss::merge_block(Block& b)// 변화
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
int Boss::move_block(Block& now_block, Block& next_block)// 변화
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
			Grechange(now_block);
			now_block = next_block;
			next_block = Block(stage_data[level]);
			Gchange(next_block);
			block_start(now_block);
			show_next_block(next_block);
			return 2;
		}
		return 0;
	}
void Boss::check_full_line() // 변화
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
			if (stage_data[level].getLine() != lines) {
				lines++;
				if (game_change == 1) {
					checkBBlack = true;
				}
				if (rand() % 3 == 0 || true) {
					game_change = (game_change + (rand() % 4)) % 4;
				}
				if (game_change == 1) { // 유령 블록의 경우 출력 형식이 다름
					checkBlack = true;
				}
				if (game_change == 2) {
					checkReverse = true;
				}
			}
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
void Boss::show_next_block(Block& next_block) // 변화
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
void Boss::Gchange(Block& block1) // 변화
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
void Boss::Grechange(Block& block1) // 변화
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
void Boss::show_bottom_block(Block& b) { // 수정 함수
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
void Boss::erase_bottom_block(Block& b) { // 수정 함수

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
void Boss::rotate_block(Block& b)
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
//BlackOut
void Boss::Bshow_around(Block& b) {
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
void Boss::Bmerge_block(Block& b)
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
int Boss::Bmove_block(Block& now_block, Block& next_block)
{

	erase_cur_block(now_block);
	now_block.setY(now_block.getY() + 1);   //블럭을 한칸 아래로 내림
	if (!strike_check(now_block)) { //
		if (keytemp != 32) {
			keytemp = KEY_DOWN;
			Bshow_around(now_block);
		}
	}
	if (strike_check(now_block))
	{
		if (now_block.getY() <= 0)   //게임오버
		{

			return 1;
		}
		now_block.setY(now_block.getY() - 1);
		Bmerge_block(now_block);
		now_block = next_block;
		next_block = Block(stage_data[level]);

		block_start(now_block);
		show_next_block(next_block);
		return 2;
	}
	return 0;
}
//Reverse
void Boss::Rchange() {

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
void Boss::showLevel() {
		if (lines >= 0 && lines < 10) {
			rTime = 30;
			
		}
		else if (lines >= 10 && lines < 18) {
			rTime = 20;
			
		}
		else if (lines >= 18 && lines < 19) {
			rTime = 10;
			
		}
		else if (lines == 19) {
			rTime = 5;
			
		}

	}
void Boss::randKey1(int i) {
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
				case KEY_DOWN:     //회전하기
					erase_bottom_block(temp); //
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_RIGHT:      //왼쪽으로 이동
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
				case KEY_LEFT:      //오른쪽으로 이동

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
				case KEY_UP:      //아래로 이동
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block); //
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
				show_bottom_block(now_block); //
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
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
			return;
		}
		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();
	}
void Boss::randKey2(int i) {
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
					show_bottom_block(now_block); //
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
				show_bottom_block(now_block); //
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
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
			return;
		}

		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();

	}
void Boss::randKey3(int i) {
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
				case KEY_RIGHT:      //회전하기
					erase_bottom_block(temp); //
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_UP:      //왼쪽으로 이동
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
				case KEY_DOWN:      //오른쪽으로 이동

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
				case KEY_LEFT:      //아래로 이동
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block); //
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
				show_bottom_block(now_block); //
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
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
			return;
		}

		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();


	}
void Boss::randKey4(int i) {
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
				case KEY_LEFT:      //회전하기
					erase_bottom_block(temp); //
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_DOWN:      //왼쪽으로 이동
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
				case KEY_UP:      //오른쪽으로 이동

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
				case KEY_RIGHT:      //아래로 이동
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block); //
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
				show_bottom_block(now_block); //
				show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
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
			return;
		}

		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();

	}
void Boss::randKey5(int i) {
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
				case KEY_LEFT: //아래로 
					is_gameover = move_block(now_block, next_block);
					show_bottom_block(now_block); //
					show_cur_block(now_block);
					break;
				case KEY_DOWN:  //오른쪽으로 
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
				case KEY_UP:    //돌리기  
					erase_bottom_block(temp); //
					rotate_block(now_block);
					show_bottom_block(now_block);
					break;
				case KEY_RIGHT: //스페이스바     
					while (is_gameover == 0)
					{
						is_gameover = move_block(now_block, next_block);
					}
					show_bottom_block(now_block); //
					show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
					break;
				}
			}
			if (keytemp == 32)   //왼쪽으로
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
			return;
		}

		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();
	}
void Boss::randKey6(int i) {
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
				case KEY_UP:      //회전하기
					while (is_gameover == 0)
					{
						is_gameover = move_block(now_block, next_block);
					}
					show_bottom_block(now_block); //
					show_cur_block(now_block); // 게임 오버가 되면 그 화면을 보여줌
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
					show_bottom_block(now_block); //
					show_cur_block(now_block);
					break;
				}
			}
			if (keytemp == 32)   //스페이스바를 눌렀을때
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
			return;
		}

		CM::gotoxy(77, 23);
		Sleep(15);
		CM::gotoxy(77, 23);
		end = clock();

	}
//Rotate
void Boss::Rotating(const int& rotate, int* x, int* y) {
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
void Boss::Rshow_cur_block(Block& b) { // Rotate를 쓰기 위해 수정
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
void Boss::Rerase_cur_block(Block& b) { // Rotate를 쓰기 위해 수정
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (block[b.getShape()][b.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
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
		CM::gotoxy(77, 23);

	}
void Boss::Rshow_total_block() { // Rotate를 쓰기 위해 수정
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
				else if (total_block[i][j] == 2)
				{
					cout << "□";
				}
				else {
					cout << "  ";
				}

			}
		}
		CM::SetColor(BLACK);
		CM::gotoxy(77, 23);
	}
void Boss::Rcheck_full_line() // 돌았을 때 클리어시 표시 수정
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
			if (stage_data[level].getLine() != lines) {
				lines++;
				if (game_change == 1) {
					checkBBlack = true;
				}
				if (game_change == 3) {
					checkBRotate = true;
				}
				if (rand() % 3 == 0 || true) {
					game_change = (game_change + (rand() % 4)) % 4;
				}
				if (game_change == 1) { // 유령 블록의 경우 출력 형식이 다름
					checkBlack = true;
				}
				if (game_change == 2) {
					checkReverse = true;
				}
				
			}
			Rshow_total_block();
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
			Rshow_gamestat();
		}
	}

}
void Boss::Rshow_next_block(Block& next_block) // 옆으로 돌리면서 수정이 필요해짐
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

				if (block[next_block.getShape()][0][j][i] == 1 || block[next_block.getShape()][0][j][i] == 2)
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
void Boss::Rshow_gamestat() // 옆으로 돌리면서 수정이 필요해짐
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
void Boss::Rshow_bottom_block(Block& b) {
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
void Boss::Rerase_bottom_block(Block& b) {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (block[temp.getShape()][temp.getAngle()][j][i] == 1 || block[b.getShape()][b.getAngle()][j][i] == 2)
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
int Boss::Rmove_block(Block& now_block, Block& next_block)// 변화
{
	Rerase_cur_block(now_block);
	now_block.setY(now_block.getY() + 1);   //블럭을 한칸 아래로 내림		
	if (strike_check(now_block))
	{
		if (now_block.getY() <= 0)   //게임오버
		{

			return 1;
		}
		now_block.setY(now_block.getY() - 1);
		Rmerge_block(now_block);
		Grechange(now_block);
		now_block = next_block;
		next_block = Block(stage_data[level]);
		Gchange(next_block);
		block_start(now_block);
		Rshow_next_block(next_block);
		return 2;
	}
	return 0;
}
void Boss::Rmerge_block(Block& b)// 변화
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
	Rcheck_full_line();
	Rshow_total_block();
}
void Boss::Rrotate_block(Block& b)
{
	if (!strike_check(Block(b.getShape(), (b.getAngle() + 1) % 4, b.getX(), b.getY())))
	{
		if (b.getX() < 14) {
			Rerase_cur_block(b);
			b.setAngle((b.getAngle() + 1) % 4);
			Rshow_cur_block(b);
		}
	}
	else {
		if (b.getShape() == 0 && b.getX() + 3 >= 13) {
			Rerase_cur_block(b);
			b.setX(b.getX() - 3);
			b.setAngle((b.getAngle() + 1) % 4);
			if (strike_check(b)) {
				b.setX(b.getX() + 3);
				b.setAngle((b.getAngle() + 3) % 4);

				Rshow_cur_block(b);
				return;
			}

			Rshow_cur_block(b);
		}
		else if (b.getX() + 3 >= 13) {
			Rerase_cur_block(b);
			b.setX(b.getX() - 1);
			b.setAngle((b.getAngle() + 1) % 4);
			if (strike_check(b)) {
				b.setX(b.getX() + 1);
				b.setAngle((b.getAngle() + 3) % 4);

				Rshow_cur_block(b);
				return;
			}

			Rshow_cur_block(b);
		}
	}
}
