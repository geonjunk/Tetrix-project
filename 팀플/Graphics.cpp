#include "Graphics.h"



Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}


int Graphics::input_data()
{
	char i = 0;
	CM::SetColor(GRAY);
	CM::gotoxy(10, 7);
	cout << "����������<GAME KEY>������������";
	Sleep(10);
	CM::gotoxy(10, 8);
	cout << "�� UP   : Rotate Block        ��";
	Sleep(10);
	CM::gotoxy(10, 9);
	cout << "�� DOWN : Move One-Step Down  ��";
	Sleep(10);
	CM::gotoxy(10, 10);
	cout << "�� SPACE: Move Bottom Down    ��";
	Sleep(10);
	CM::gotoxy(10, 11);
	cout << "�� LEFT : Move Left           ��";
	Sleep(10);
	CM::gotoxy(10, 12);
	cout << "�� RIGHT: Move Right          ��";
	Sleep(10);
	CM::gotoxy(10, 13);
	cout << "��������������������������������";


	while (i < 1 || i>8)
	{
		CM::gotoxy(10, 3);
		cout << "Select Start level[1-8]:       \b\b\b\b\b\b\b";
		cin >> i;
		i -= 48;
	}

	int level = i - 1;
	system("cls");
	return level;
}


void Graphics::show_title() {
	for (int i = 0; i < 25; i++) {
		CM::gotoxy(50, i);
		Sleep(20);
		cout << "��";
	}
	CM::gotoxy(11, 2);
	cout << "��ȭ�Ӱ� �б���Ȱ�� �ϰ� �ִ� ";
	Sleep(2000);
	CM::gotoxy(1, 5);
	cout << "�Ǳ����б� ��Ʈ�����а� 09�й� 5�г� ���ñ�(28)��";
	CM::gotoxy(8, 8);
	Sleep(2000);
	cout << "��������������������������";
	for (int i = 9; i < 11; i++) {
		CM::gotoxy(8, i);
		cout << "��                      ��";
	}
	CM::gotoxy(8, 11);
	cout << "��                  ��  ��";
	CM::gotoxy(8, 12);
	cout << "��                  ��  ��";
	CM::gotoxy(8, 13);
	cout << "��                  ��  ��";
	CM::gotoxy(8, 14);
	cout << "��                  ��  ��";
	CM::gotoxy(8, 15);
	cout << "��                  ��  ��";
	for (int i = 16; i < 25; i++) {
		CM::gotoxy(8, i);
		cout << "��                      ��";
	}
	Sleep(800);
	CM::SetColor(RED);
	for (int i = 20; i < 24; i++) {
		CM::gotoxy(40, i);
		cout << "��";
	}
	CM::SetColor(GRAY);
	CM::gotoxy(35, 24);
	cout << "���ñ�, 28��";
	Sleep(100000);
}


bool Graphics::show_logo(int& clear)
{
	PlaySound(TEXT("����ȭ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	bool S_A = false;
	CM::gotoxy(50, 3);
	cout << "��������������������������������������������������";
	Sleep(100);
	CM::gotoxy(50, 4);
	cout << "���ߡߡ�  �ߡߡ�  �ߡߡ�   �ߡ�     ��   ��  �� ��";
	Sleep(100);
	CM::gotoxy(50, 5);
	cout << "��  ��    ��        ��     �� ��    ��    �ߡ�  ��";
	Sleep(100);
	CM::gotoxy(50, 6);
	cout << "��  ��    �ߡߡ�    ��     �ߡ�     ��     ��   ��";
	Sleep(100);
	CM::gotoxy(50, 7);
	cout << "��  ��    ��        ��     �� ��    ��    �ߡ�  ��";
	Sleep(100);
	CM::gotoxy(50, 8);
	cout << "��  ��    �ߡߡ�    ��     ��  ��   ��   ��  �� ��";
	Sleep(100);
	CM::gotoxy(50, 9);
	cout << "��������������������������������������������������";
	CM::gotoxy(51, 13);
	cout << "- �� �� �� ��   �� ��,  �� �� ��   û �� �� �� -";

	CM::gotoxy(8, 3);
	cout << "����������������������������������";
	CM::gotoxy(8, 4);
	cout << "��                              ��";
	CM::gotoxy(8, 5);
	cout << "��                              ��";
	CM::gotoxy(8, 6);
	cout << "��     ��    ��    ��    ��     ��";
	CM::gotoxy(8, 7);
	cout << "��                              ��";
	CM::gotoxy(8, 8);
	cout << "��           ��    ��           ��";
	CM::gotoxy(8, 9);
	cout << "��                              ��";
	CM::gotoxy(8, 10);
	cout << "��                              ��";
	CM::gotoxy(8, 11);
	cout << "��                              ��";
	CM::gotoxy(8, 12);
	cout << "��            ����            ��";
	CM::gotoxy(8, 13);
	cout << "��            ��  ��            ��";
	CM::gotoxy(8, 14);
	cout << "��            ����            ��";
	CM::gotoxy(8, 15);
	cout << "��                ��            ��";
	CM::gotoxy(8, 16);
	cout << "��            ����            ��";
	CM::gotoxy(8, 17);
	cout << "��                              ��";
	CM::gotoxy(8, 18);
	cout << "��                              ��";
	CM::gotoxy(8, 19);
	cout << "����������������������������������";
	CM::gotoxy(15, 20);
	cout << "S T O R Y   M O D E";

	if (clear > 3) {
		CM::gotoxy(108, 3);
		cout << "����������������������������������";
		CM::gotoxy(108, 4);
		cout << "��              ��              ��";
		CM::gotoxy(108, 5);
		cout << "��   �����   ��              ��";
		CM::gotoxy(108, 6);
		cout << "�� ��        �� ��              ��";
		CM::gotoxy(108, 7);
		cout << "�� �� ��  �� �� ��              ��";
		CM::gotoxy(108, 8);
		cout << "�� ��        �� ��              "; CM::SetColor(DARK_GRAY); cout << "��"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(108, 9);
		cout << "�� ��   ��   �� ��            "; CM::SetColor(DARK_GRAY); cout << "��"; CM::SetColor(GRAY); cout << "�᦭";
		CM::gotoxy(108, 10);
		cout << "�� ��        �� ��        ��"; CM::SetColor(DARK_GRAY); cout << "��"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "��"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(108, 11);
		cout << "����������������������������������";
		CM::gotoxy(108, 12);
		cout << "��  ������  ��    ����    ��";
		CM::gotoxy(108, 13);
		cout << "��  ��          ��  ��      ��  ��";
		CM::gotoxy(108, 14);
		cout << "��  ��      ��  ��  ��      ��  ��";
		CM::gotoxy(108, 15);
		cout << "������  ���覭        ��    ��";
		CM::gotoxy(108, 16);
		cout << "��  ��      ��  ��      ��      ��";
		CM::gotoxy(108, 17);
		cout << "��          ��  ��              ��";
		CM::gotoxy(108, 18);
		cout << "��  ������  ��      ��      ��";
		CM::gotoxy(108, 19);
		cout << "����������������������������������";
		CM::gotoxy(114, 20);
		cout << "A R C A D E   M O D E";
	}
	else {
		CM::SetColor(GRAY, DARK_GRAY);
		CM::gotoxy(108, 3);
		cout << "����������������������������������";
		CM::gotoxy(108, 4);
		cout << "��                              ��";
		CM::gotoxy(108, 5);
		cout << "��                              ��";
		CM::gotoxy(108, 6);
		cout << "��                              ��";
		CM::gotoxy(108, 7);
		cout << "��            ����            ��";
		CM::gotoxy(108, 8);
		cout << "��          ��      ��          ��";
		CM::gotoxy(108, 9);
		cout << "��          ��      ��          ��";
		CM::gotoxy(108, 10);
		cout << "��        ��������        ��";
		CM::gotoxy(108, 11);
		cout << "��        ��   ���   ��        ��";
		CM::gotoxy(108, 12);
		cout << "��        �� ����� ��        ��";
		CM::gotoxy(108, 13);
		cout << "��        ��   ���   ��        ��";
		CM::gotoxy(108, 14);
		cout << "��        ��������        ��";
		CM::gotoxy(108, 15);
		cout << "��                              ��";
		CM::gotoxy(108, 16);
		cout << "��                              ��";
		CM::gotoxy(108, 17);
		cout << "��                              ��";
		CM::gotoxy(108, 18);
		cout << "��                              ��";
		CM::gotoxy(108, 19);
		cout << "����������������������������������";
		CM::gotoxy(114, 20);
		CM::SetColor(GRAY, BLACK);
		cout << "A R C A D E   M O D E";
		CM::gotoxy(108, 22);
		cout << "���丮 ��带 ��� Ŭ���� ���ּ���.";
	}

	CM::SetColor(DARK_RED);
	CM::gotoxy(6, 2);
	cout << "��������������������";
	for (int j = 3; j < 22; j++) {
		CM::gotoxy(6, j);
		cout << "��";
		CM::gotoxy(42, j);
		cout << "��";
	}
	CM::gotoxy(6, 22);
	cout << "��������������������";

	char keytemp;

	for (int i = 0; i >= 0; i++) {
		if (i % 40 == 0) {
			for (int j = 0; j < 5; j++)
			{
				CM::gotoxy(48, 17 + j);
				cout << "                                                  ";
			}
			show_block(Block(rand() % 7, rand() % 4, 25, 17));
			show_block(Block(rand() % 7, rand() % 4, 31, 17));
			show_block(Block(rand() % 7, rand() % 4, 38, 17));
			show_block(Block(rand() % 7, rand() % 4, 43, 17));
		}
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp == 13) {
				system("cls");
				PlaySound(NULL, 0, 0);
				return S_A;
			}
			else if (keytemp == EXT_KEY) {
				keytemp = _getch();
				if (keytemp == KEY_RIGHT) {
					if (clear < 4)
						continue;
					S_A = true;
					CM::gotoxy(6, 2);
					cout << "                                      ";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(6, j);
						cout << "  ";
						CM::gotoxy(42, j);
						cout << "  ";
					}
					CM::gotoxy(6, 22);
					cout << "                                        ";
					CM::SetColor(DARK_VOILET);
					CM::gotoxy(106, 2);
					cout << "��������������������";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(106, j);
						cout << "��";
						CM::gotoxy(142, j);
						cout << "��";
					}
					CM::gotoxy(106, 22);
					cout << "��������������������";
				}
				else if (keytemp == KEY_LEFT) {
					if (clear < 4)
						continue;
					S_A = false;
					CM::gotoxy(106, 2);
					cout << "                                      ";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(106, j);
						cout << "  ";
						CM::gotoxy(142, j);
						cout << "  ";
					}
					CM::gotoxy(106, 22);
					cout << "                                        ";
					CM::SetColor(DARK_RED);
					CM::gotoxy(6, 2);
					cout << "��������������������";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(6, j);
						cout << "��";
						CM::gotoxy(42, j);
						cout << "��";
					}
					CM::gotoxy(6, 22);
					cout << "��������������������";
				}
			}
		}

		Sleep(30);
	}
	PlaySound(NULL, 0, 0);
	return S_A;
}


int Graphics::show_story(int& clear) {
	CM::gotoxy(68, 25);
	cout << "ESC - MAIN MENU";

	CM::gotoxy(8, 3);
	cout << "����������������������";
	CM::gotoxy(8, 4);
	cout << "��                  ��";
	CM::gotoxy(8, 5);
	cout << "��   G  H  O  S  T  ��";
	CM::gotoxy(8, 6);
	cout << "��                  ��";
	CM::gotoxy(8, 7);
	cout << "��      ����      ��";
	CM::gotoxy(8, 8);
	cout << "��    ��      ��    ��";
	CM::gotoxy(8, 9);
	cout << "��  ��         ��   ��";
	CM::gotoxy(8, 10);
	cout << "��  ��  ��  ��  ��  ��";
	CM::gotoxy(8, 11);
	cout << "��   ��         ��  ��";
	CM::gotoxy(8, 12);
	cout << "��    ��  ��    ��  ��";
	CM::gotoxy(8, 13);
	cout << "��     ��      ��   ��";
	CM::gotoxy(8, 14);
	cout << "��     ��    ��     ��";
	CM::gotoxy(8, 15);
	cout << "��    ��   ��       ��";
	CM::gotoxy(8, 16);
	cout << "��   ����         ��";
	CM::gotoxy(8, 17);
	cout << "��  ���            ��";
	CM::gotoxy(8, 18);
	cout << "��                  ��";
	CM::gotoxy(8, 19);
	cout << "����������������������";
	CM::gotoxy(13, 20);
	cout << "S T A G E   1";

	if (clear < 1) {
		CM::SetColor(GRAY, DARK_GRAY);
		CM::gotoxy(36, 3);
		cout << "����������������������";
		CM::gotoxy(36, 4);
		cout << "��                  ��";
		CM::gotoxy(36, 5);
		cout << "��                  ��";
		CM::gotoxy(36, 6);
		cout << "��                  ��";
		CM::gotoxy(36, 7);
		cout << "��      ����      ��";
		CM::gotoxy(36, 8);
		cout << "��    ��      ��    ��";
		CM::gotoxy(36, 9);
		cout << "��    ��      ��    ��";
		CM::gotoxy(36, 10);
		cout << "��  ��������  ��";
		CM::gotoxy(36, 11);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(36, 12);
		cout << "��  �� ����� ��  ��";
		CM::gotoxy(36, 13);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(36, 14);
		cout << "��  ��������  ��";
		CM::gotoxy(36, 15);
		cout << "��                  ��";
		CM::gotoxy(36, 16);
		cout << "��                  ��";
		CM::gotoxy(36, 17);
		cout << "��                  ��";
		CM::gotoxy(36, 18);
		cout << "��                  ��";
		CM::gotoxy(36, 19);
		cout << "����������������������";
		CM::gotoxy(41, 20);
		CM::SetColor(GRAY, BLACK);
		cout << "S T A G E   2";
	}
	else {
		CM::gotoxy(36, 3);
		cout << "����������������������";
		CM::gotoxy(36, 4);
		cout << "��                  ��";
		CM::gotoxy(36, 5);
		cout << "�� B L A C K  O U T ��";
		CM::gotoxy(36, 6);
		cout << "��                  ��";
		CM::gotoxy(36, 7);
		cout << "��                  ��";
		CM::gotoxy(36, 8);
		cout << "��                  ��";
		CM::gotoxy(36, 9);
		cout << "��                  ��";
		CM::gotoxy(36, 10);
		cout << "��                  ��";
		CM::gotoxy(36, 11);
		cout << "��                  ��";
		CM::gotoxy(36, 12);
		cout << "��                  ��";
		CM::gotoxy(36, 13);
		cout << "��                  ��";
		CM::gotoxy(36, 14);
		cout << "��        "; CM::SetColor(DARK_GRAY); cout << "    ����"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(36, 15);
		cout << "��        "; CM::SetColor(DARK_GRAY); cout << "  �����"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(36, 16);
		cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "���᦭";
		CM::gotoxy(36, 17);
		cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(36, 18);
		cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
		CM::gotoxy(36, 19);
		cout << "����������������������";
		CM::gotoxy(41, 20);
		cout << "S T A G E   2";
	}

	if (clear < 2) {
		CM::SetColor(GRAY, DARK_GRAY);
		CM::gotoxy(64, 3);
		cout << "����������������������";
		CM::gotoxy(64, 4);
		cout << "��                  ��";
		CM::gotoxy(64, 5);
		cout << "��                  ��";
		CM::gotoxy(64, 6);
		cout << "��                  ��";
		CM::gotoxy(64, 7);
		cout << "��      ����      ��";
		CM::gotoxy(64, 8);
		cout << "��    ��      ��    ��";
		CM::gotoxy(64, 9);
		cout << "��    ��      ��    ��";
		CM::gotoxy(64, 10);
		cout << "��  ��������  ��";
		CM::gotoxy(64, 11);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(64, 12);
		cout << "��  �� ����� ��  ��";
		CM::gotoxy(64, 13);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(64, 14);
		cout << "��  ��������  ��";
		CM::gotoxy(64, 15);
		cout << "��                  ��";
		CM::gotoxy(64, 16);
		cout << "��                  ��";
		CM::gotoxy(64, 17);
		cout << "��                  ��";
		CM::gotoxy(64, 18);
		cout << "��                  ��";
		CM::gotoxy(64, 19);
		cout << "����������������������";
		CM::gotoxy(69, 20);
		CM::SetColor(GRAY, BLACK);
		cout << "S T A G E   3";
	}
	else {
		CM::gotoxy(64, 3);
		cout << "����������������������";
		CM::gotoxy(64, 4);
		cout << "��                  ��";
		CM::gotoxy(64, 5);
		cout << "��    R O T A T E   ��";
		CM::gotoxy(64, 6);
		cout << "��                  ��";
		CM::gotoxy(64, 7);
		cout << "��     ������   ��";
		CM::gotoxy(64, 8);
		cout << "��     ��      ��   ��";
		CM::gotoxy(64, 9);
		cout << "��             ��   ��";
		CM::gotoxy(64, 10);
		cout << "��             ��   ��";
		CM::gotoxy(64, 11);
		cout << "��             ��   ��";
		CM::gotoxy(64, 12);
		cout << "��     ��    ���� ��";
		CM::gotoxy(64, 13);
		cout << "��   ����    ��   ��";
		CM::gotoxy(64, 14);
		cout << "��     ��           ��";
		CM::gotoxy(64, 15);
		cout << "��     ��           ��";
		CM::gotoxy(64, 16);
		cout << "��     ��      ��   ��";
		CM::gotoxy(64, 17);
		cout << "��     ��      ��   ��";
		CM::gotoxy(64, 18);
		cout << "��     ������   ��";
		CM::gotoxy(64, 19);
		cout << "����������������������";
		CM::gotoxy(69, 20);
		cout << "S T A G E   3";
	}

	if (clear < 3) {
		CM::SetColor(GRAY, DARK_GRAY);
		CM::gotoxy(92, 3);
		cout << "����������������������";
		CM::gotoxy(92, 4);
		cout << "��                  ��";
		CM::gotoxy(92, 5);
		cout << "��                  ��";
		CM::gotoxy(92, 6);
		cout << "��                  ��";
		CM::gotoxy(92, 7);
		cout << "��      ����      ��";
		CM::gotoxy(92, 8);
		cout << "��    ��      ��    ��";
		CM::gotoxy(92, 9);
		cout << "��    ��      ��    ��";
		CM::gotoxy(92, 10);
		cout << "��  ��������  ��";
		CM::gotoxy(92, 11);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(92, 12);
		cout << "��  �� ����� ��  ��";
		CM::gotoxy(92, 13);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(92, 14);
		cout << "��  ��������  ��";
		CM::gotoxy(92, 15);
		cout << "��                  ��";
		CM::gotoxy(92, 16);
		cout << "��                  ��";
		CM::gotoxy(92, 17);
		cout << "��                  ��";
		CM::gotoxy(92, 18);
		cout << "��                  ��";
		CM::gotoxy(92, 19);
		cout << "����������������������";
		CM::gotoxy(97, 20);
		CM::SetColor(GRAY, BLACK);
		cout << "S T A G E   4";
	}
	else {
		CM::gotoxy(92, 3);
		cout << "����������������������";
		CM::gotoxy(92, 4);
		cout << "��                  ��";
		CM::gotoxy(92, 5);
		cout << "��   R E V E R S E  ��";
		CM::gotoxy(92, 6);
		cout << "��                  ��";
		CM::gotoxy(92, 7);
		cout << "��      �����    ��";
		CM::gotoxy(92, 8);
		cout << "��    ��        ��  ��";
		CM::gotoxy(92, 9);
		cout << "��    ��        ��  ��";
		CM::gotoxy(92, 10);
		cout << "��    ��        ��  ��";
		CM::gotoxy(92, 11);
		cout << "��    ��        ��  ��";
		CM::gotoxy(92, 12);
		cout << "��          ���    ��";
		CM::gotoxy(92, 13);
		cout << "��        ��        ��";
		CM::gotoxy(92, 14);
		cout << "��        ��        ��";
		CM::gotoxy(92, 15);
		cout << "��        ��        ��";
		CM::gotoxy(92, 16);
		cout << "��                  ��";
		CM::gotoxy(92, 17);
		cout << "��        ��        ��";
		CM::gotoxy(92, 18);
		cout << "��                 ��";
		CM::gotoxy(92, 19);
		cout << "����������������������";
		CM::gotoxy(97, 20);
		cout << "S T A G E   4";
	}

	if (clear < 4) {
		CM::SetColor(GRAY, DARK_GRAY);
		CM::gotoxy(120, 3);
		cout << "����������������������";
		CM::gotoxy(120, 4);
		cout << "��                  ��";
		CM::gotoxy(120, 5);
		cout << "��                  ��";
		CM::gotoxy(120, 6);
		cout << "��                  ��";
		CM::gotoxy(120, 7);
		cout << "��      ����      ��";
		CM::gotoxy(120, 8);
		cout << "��    ��      ��    ��";
		CM::gotoxy(120, 9);
		cout << "��    ��      ��    ��";
		CM::gotoxy(120, 10);
		cout << "��  ��������  ��";
		CM::gotoxy(120, 11);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(120, 12);
		cout << "��  �� ����� ��  ��";
		CM::gotoxy(120, 13);
		cout << "��  ��   ���   ��  ��";
		CM::gotoxy(120, 14);
		cout << "��  ��������  ��";
		CM::gotoxy(120, 15);
		cout << "��                  ��";
		CM::gotoxy(120, 16);
		cout << "��                  ��";
		CM::gotoxy(120, 17);
		cout << "��                  ��";
		CM::gotoxy(120, 18);
		cout << "��                  ��";
		CM::gotoxy(120, 19);
		cout << "����������������������";
		CM::gotoxy(122, 20);
		CM::SetColor(GRAY, BLACK);
		cout << "S T A G E   B O S S";
	}
	else {
		CM::SetColor(DARK_RED);
		CM::gotoxy(120, 3);
		cout << "����������������������";
		CM::gotoxy(120, 4);
		cout << "��                  ��";
		CM::gotoxy(120, 5);
		cout << "��        ��        ��";
		CM::gotoxy(120, 6);
		cout << "��                  ��";
		CM::gotoxy(120, 7);
		cout << "��      ��  ��      ��";
		CM::gotoxy(120, 8);
		cout << "��                  ��";
		CM::gotoxy(120, 9);
		cout << "��    ��      ��    ��";
		CM::gotoxy(120, 10);
		cout << "��                  ��";
		CM::gotoxy(120, 11);
		cout << "��  �� �� �� �� ��  ��";
		CM::gotoxy(120, 12);
		cout << "��                  ��";
		CM::gotoxy(120, 13);
		cout << "��    ��      ��    ��";
		CM::gotoxy(120, 14);
		cout << "��                  ��";
		CM::gotoxy(120, 15);
		cout << "��      ��  ��      ��";
		CM::gotoxy(120, 16);
		cout << "��                  ��";
		CM::gotoxy(120, 17);
		cout << "��        ��        ��";
		CM::gotoxy(120, 18);
		cout << "��                  ��";
		CM::gotoxy(120, 19);
		cout << "����������������������";
		CM::gotoxy(122, 20);
		CM::SetColor(GRAY);
		cout << "S T A G E   B O S S";
	}

	char colors[5] = { DARK_RED,DARK_BLUE,DARK_GREEN,DARK_YELLOW,RED };
	int c_c = 0;

	CM::SetColor(colors[c_c]);
	CM::gotoxy(6, 2);
	cout << "��������������";
	for (int i = 3; i < 22; i++) {
		CM::gotoxy(6, i);
		cout << "��";
		CM::gotoxy(30, i);
		cout << "��";
	}
	CM::gotoxy(6, 22);
	cout << "��������������";

	int x = 6;
	int limit;
	switch (clear) {
	case 0:
		limit = 6;
		break;
	case 1:
		limit = 34;
		break;
	case 2:
		limit = 62;
		break;
	case 3:
		limit = 90;
		break;
	case 4:
		limit = 118;
		break;
	}
	char keytemp;

	while (true) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp == 13) {
				system("cls");
				CM::SetColor(GRAY);
				return x;
			}
			else if (keytemp == 27) {
				system("cls");
				CM::SetColor(GRAY);
				return 0;
			}
			else if (keytemp == 'c') {
				system("cls");
				CM::SetColor(GRAY);
				clear = 4;
				return 0;
			}
			else if (keytemp == EXT_KEY) {
				keytemp = _getch();
				if (keytemp == KEY_RIGHT) {
					if (x == limit)
						continue;
					CM::gotoxy(x, 2);
					cout << "                                      ";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(x, j);
						cout << "  ";
						CM::gotoxy(x + 24, j);
						cout << "  ";
					}
					CM::gotoxy(x, 22);
					cout << "                                        ";
					x += 28;
					CM::SetColor(colors[++c_c]);
					CM::gotoxy(x, 2);
					cout << "��������������";
					for (int i = 3; i < 22; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, 22);
					cout << "��������������";
				}
				else if (keytemp == KEY_LEFT) {
					if (x == 6)
						continue;
					CM::gotoxy(x, 2);
					cout << "                                      ";
					for (int j = 3; j < 22; j++) {
						CM::gotoxy(x, j);
						cout << "  ";
						CM::gotoxy(x + 24, j);
						cout << "  ";
					}
					CM::gotoxy(x, 22);
					cout << "                                        ";
					x -= 28;
					CM::SetColor(colors[--c_c]);
					CM::gotoxy(x, 2);
					cout << "��������������";
					for (int i = 3; i < 22; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, 22);
					cout << "��������������";
				}
			}
		}
	}
}


int Graphics::show_arcade() {
	CM::gotoxy(68, 25);
	cout << "ESC - MAIN MENU";

	CM::gotoxy(8, 2);
	cout << "����������������������";
	CM::gotoxy(8, 3);
	cout << "��   B  A  S  I  C  ��";
	CM::gotoxy(8, 4);
	cout << "��                  ��";
	CM::gotoxy(8, 5);
	cout << "������    ����᦭";
	CM::gotoxy(8, 6);
	cout << "����    ��  ��      ��";
	CM::gotoxy(8, 7);
	cout << "������    ����᦭";
	CM::gotoxy(8, 8);
	cout << "����    ��        �᦭";
	CM::gotoxy(8, 9);
	cout << "������    ����᦭";
	CM::gotoxy(8, 10);
	cout << "����������������������";
	CM::gotoxy(11, 11);
	cout << "B A S I C : 1 P";

	CM::gotoxy(36, 2);
	cout << "����������������������";
	CM::gotoxy(36, 3);
	cout << "��   G  H  O  S  T  ��";
	CM::gotoxy(36, 4);
	cout << "��      ����      ��";
	CM::gotoxy(36, 5);
	cout << "��    ��       ��   ��";
	CM::gotoxy(36, 6);
	cout << "��   ��  ��  ��  �� ��";
	CM::gotoxy(36, 7);
	cout << "��    ��  ��    ��  ��";
	CM::gotoxy(36, 8);
	cout << "��     ��      ��   ��";
	CM::gotoxy(36, 9);
	cout << "��     ��    ��     ��";
	CM::gotoxy(36, 10);
	cout << "����������������������";
	CM::gotoxy(38, 11);
	cout << "S T A G E  1 : 1 P";

	CM::gotoxy(64, 2);
	cout << "����������������������";
	CM::gotoxy(64, 3);
	cout << "�� B L A C K  O U T ��";
	CM::gotoxy(64, 4);
	cout << "��                  ��";
	CM::gotoxy(64, 5);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "    ����"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 6);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "  �����"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 7);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "���᦭";
	CM::gotoxy(64, 8);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 9);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 10);
	cout << "����������������������";
	CM::gotoxy(66, 11);
	cout << "S T A G E  2 : 1 P";

	CM::gotoxy(92, 2);
	cout << "����������������������";
	CM::gotoxy(92, 3);
	cout << "��    R O T A T E   ��";
	CM::gotoxy(92, 4);
	cout << "��     ������   ��";
	CM::gotoxy(92, 5);
	cout << "��             ��   ��";
	CM::gotoxy(92, 6);
	cout << "��     ��    ���� ��";
	CM::gotoxy(92, 7);
	cout << "��   ����    ��   ��";
	CM::gotoxy(92, 8);
	cout << "��     ��           ��";
	CM::gotoxy(92, 9);
	cout << "��     ������   ��";
	CM::gotoxy(92, 10);
	cout << "����������������������";
	CM::gotoxy(94, 11);
	cout << "S T A G E  3 : 1 P";

	CM::gotoxy(120, 2);
	cout << "����������������������";
	CM::gotoxy(120, 3);
	cout << "��   R E V E R S E  ��";
	CM::gotoxy(120, 4);
	cout << "��      �����    ��";
	CM::gotoxy(120, 5);
	cout << "��    ��        ��  ��";
	CM::gotoxy(120, 6);
	cout << "��    ��        ��  ��";
	CM::gotoxy(120, 7);
	cout << "��          ���    ��";
	CM::gotoxy(120, 8);
	cout << "��         ��       ��";
	CM::gotoxy(120, 9);
	cout << "��         ��       ��";
	CM::gotoxy(120, 10);
	cout << "����������������������";
	CM::gotoxy(122, 11);
	cout << "S T A G E  4 : 1 P";


	CM::gotoxy(8, 14);
	cout << "����������������������";
	CM::gotoxy(8, 15);
	cout << "��   S  T  O  R  Y  ��";
	CM::gotoxy(8, 16);
	cout << "��                  ��";
	CM::gotoxy(8, 17);
	cout << "��        ��        ��";
	CM::gotoxy(8, 18);
	cout << "��     ��    ��     ��";
	CM::gotoxy(8, 19);
	cout << "��   ��  ���  ��   ��";
	CM::gotoxy(8, 20);
	cout << "��     ��    ��     ��";
	CM::gotoxy(8, 21);
	cout << "��        ��        ��";
	CM::gotoxy(8, 22);
	cout << "����������������������";
	CM::gotoxy(9, 23);
	cout << "S T O R Y : B O S S";

	CM::gotoxy(36, 14);
	cout << "����������������������";
	CM::gotoxy(36, 15);
	cout << "��   S  T  O  R  Y  ��";
	CM::gotoxy(36, 16);
	cout << "��      ����      ��";
	CM::gotoxy(36, 17);
	cout << "��    ��       ��   ��";
	CM::gotoxy(36, 18);
	cout << "��   ��  ��  ��  �� ��";
	CM::gotoxy(36, 19);
	cout << "��    ��  ��    ��  ��";
	CM::gotoxy(36, 20);
	cout << "��     ��      ��   ��";
	CM::gotoxy(36, 21);
	cout << "��     ��    ��     ��";
	CM::gotoxy(36, 22);
	cout << "����������������������";
	CM::gotoxy(43, 23);
	cout << "G H O S T";

	CM::gotoxy(64, 14);
	cout << "����������������������";
	CM::gotoxy(64, 15);
	cout << "��   S  T  O  R  Y  ��";
	CM::gotoxy(64, 16);
	cout << "��                  ��";
	CM::gotoxy(64, 17);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "    ����"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 18);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "  �����"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 19);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "���᦭";
	CM::gotoxy(64, 20);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 21);
	cout << "��        "; CM::SetColor(DARK_GRAY); cout << "���"; CM::SetColor(GRAY); cout << "��"; CM::SetColor(WHITE); cout << "���"; CM::SetColor(GRAY); cout << "��";
	CM::gotoxy(64, 22);
	cout << "����������������������";
	CM::gotoxy(67, 23);
	cout << "B L A C K  O U T";

	CM::gotoxy(92, 14);
	cout << "����������������������";
	CM::gotoxy(92, 15);
	cout << "��   S  T  O  R  Y  ��";
	CM::gotoxy(92, 16);
	cout << "��     ������   ��";
	CM::gotoxy(92, 17);
	cout << "��             ��   ��";
	CM::gotoxy(92, 18);
	cout << "��     ��    ���� ��";
	CM::gotoxy(92, 19);
	cout << "��   ����    ��   ��";
	CM::gotoxy(92, 20);
	cout << "��     ��           ��";
	CM::gotoxy(92, 21);
	cout << "��     ������   ��";
	CM::gotoxy(92, 22);
	cout << "����������������������";
	CM::gotoxy(97, 23);
	cout << "R O T A T E";

	CM::gotoxy(120, 14);
	cout << "����������������������";
	CM::gotoxy(120, 15);
	cout << "��   S  T  O  R  Y  ��";
	CM::gotoxy(120, 16);
	cout << "��      �����    ��";
	CM::gotoxy(120, 17);
	cout << "��    ��        ��  ��";
	CM::gotoxy(120, 18);
	cout << "��    ��        ��  ��";
	CM::gotoxy(120, 19);
	cout << "��          ���    ��";
	CM::gotoxy(120, 20);
	cout << "��         ��       ��";
	CM::gotoxy(120, 21);
	cout << "��         ��       ��";
	CM::gotoxy(120, 22);
	cout << "����������������������";
	CM::gotoxy(125, 23);
	cout << "R E V E R S E";

	CM::SetColor(DARK_RED);
	CM::gotoxy(6, 1);
	cout << "��������������";
	for (int i = 2; i < 12; i++) {
		CM::gotoxy(6, i);
		cout << "��";
		CM::gotoxy(30, i);
		cout << "��";
	}
	CM::gotoxy(6, 12);
	cout << "��������������";

	int x = 6, y = 1;
	char keytemp;

	while (true) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp == 13) {
				system("cls");
				CM::SetColor(GRAY);
				return x * y;
			}
			else if (keytemp == 27) {
				system("cls");
				CM::SetColor(GRAY);
				return 0;
			}
			else if (keytemp == EXT_KEY) {
				keytemp = _getch();
				if (keytemp == KEY_RIGHT) {
					if (x == 118)
						continue;
					CM::gotoxy(x, y);
					cout << "                                      ";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "  ";
						CM::gotoxy(x + 24, i);
						cout << "  ";
					}
					CM::gotoxy(x, y + 11);
					cout << "                                        ";
					x += 28;
					CM::gotoxy(x, y);
					cout << "��������������";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, y + 11);
					cout << "��������������";
				}
				else if (keytemp == KEY_LEFT) {
					if (x == 6)
						continue;
					CM::gotoxy(x, y);
					cout << "                                      ";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "  ";
						CM::gotoxy(x + 24, i);
						cout << "  ";
					}
					CM::gotoxy(x, y + 11);
					cout << "                                        ";
					x -= 28;
					CM::gotoxy(x, y);
					cout << "��������������";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, y + 11);
					cout << "��������������";
				}
				else if (keytemp == KEY_DOWN) {
					if (y == 13)
						continue;
					CM::gotoxy(x, y);
					cout << "                                      ";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "  ";
						CM::gotoxy(x + 24, i);
						cout << "  ";
					}
					CM::gotoxy(x, y + 11);
					cout << "                                        ";
					y += 12;
					CM::SetColor(DARK_BLUE);
					CM::gotoxy(x, y);
					cout << "��������������";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, y + 11);
					cout << "��������������";
				}
				else if (keytemp == KEY_UP) {
					if (y == 1)
						continue;
					CM::gotoxy(x, y);
					cout << "                                      ";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "  ";
						CM::gotoxy(x + 24, i);
						cout << "  ";
					}
					CM::gotoxy(x, y + 11);
					cout << "                                        ";
					y -= 12;
					CM::SetColor(DARK_RED);
					CM::gotoxy(x, y);
					cout << "��������������";
					for (int i = y + 1; i < y + 11; i++) {
						CM::gotoxy(x, i);
						cout << "��";
						CM::gotoxy(x + 24, i);
						cout << "��";
					}
					CM::gotoxy(x, y + 11);
					cout << "��������������";
				}
			}
		}
	}

	return 0;
}


int Graphics::choice_continue() {
	system("cls");
	CM::gotoxy(70, 12);
	cout << "To The Next Story";
	CM::gotoxy(71, 14);
	cout << "To The Main Menu";
	int x = 89, y = 12;
	CM::gotoxy(x, y);
	cout << "��";
	char keytemp;

	while (true) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp == EXT_KEY) {
				keytemp = _getch();
				switch (keytemp) {
				case KEY_UP:
					if (y == 12)
						continue;
					CM::gotoxy(x, y);
					cout << "  ";
					y -= 2;
					CM::gotoxy(x, y);
					cout << "��";
					break;
				case KEY_DOWN:
					if (y == 14)
						continue;
					CM::gotoxy(x, y);
					cout << "  ";
					y += 2;
					CM::gotoxy(x, y);
					cout << "��";
					break;
				}
			}
			else if (keytemp == 13) {
				system("cls");
				return y;
			}
		}
	}
}


void Graphics::show_block(Block& b) {
	char block[7][4][4][4] = {
		//������
		1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

		//�׸���
		1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

		//'��' ���
		0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'��'���
		1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'��' ���
		1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

		//'Z' ���
		1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

		//'S' ���
		0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

	};
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
				CM::gotoxy((i + b.getX()) * 2 + 5, j + b.getY() + 1);
				cout << "��";
			}
		}
	}
	CM::SetColor(BLACK);
	CM::gotoxy(77, 23);
}


void Graphics::show_gameover()
{
	PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	CM::SetColor(RED);
	CM::gotoxy(15, 8);
	cout << "������������������������������";
	CM::gotoxy(15, 9);
	cout << "��**************************��";
	CM::gotoxy(15, 10);
	cout << "��*        GAME OVER       *��";
	CM::gotoxy(15, 11);
	cout << "��**************************��";
	CM::gotoxy(15, 12);
	cout << "������������������������������";
	fflush(stdin);
	if (Story::skip())
		return;
	system("cls");
	PlaySound(NULL, 0, 0);
	CM::gotoxy(30, 3);
	cout << "������!! �����Ͽ���!!! ���� ���� �⿩���� 0�̴�.. F������ Ȯ���̶��!!" << endl;
	if (Story::skip())
		return;
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( ??�й� ???)                                          ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ��...�ȵ�!!! F��������....!!                           ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (Story::skip())
		return;
	system("cls");
	CM::gotoxy(35, 10);
	cout << "�ƹ� Ű�� �����ÿ�..." << endl;
	if (Story::skip())
		return;
	system("cls");
}