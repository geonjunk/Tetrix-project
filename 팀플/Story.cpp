#include "Story.h"



Story::Story()
{
}


Story::~Story()
{
}


bool Story::skip() {
	char keytemp;
	while (true) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp == 13)
				return false;
			else if (keytemp == 27) {
				system("cls");
				return true;
			}
		}
	}
}


void Story::caution() {
	CM::SetColor(BLACK);
	Sleep(500);
	CM::SetColor(DARK_GRAY);
	CM::gotoxy(46, 12);
	cout << "�� �̾߱�� ���� Ư�� �ι��� ��Ī�Ͽ� �ۼ��� �̾߱Ⱑ �ƴϸ�,";
	CM::gotoxy(50, 14);
	cout << "��ǰ ���� �����ι��� ���� �㱸�� �ι����� �˷��帳�ϴ�.";
	Sleep(500);
	CM::SetColor(GRAY);
	CM::gotoxy(46, 12);
	cout << "�� �̾߱�� ���� Ư�� �ι��� ��Ī�Ͽ� �ۼ��� �̾߱Ⱑ �ƴϸ�,";
	CM::gotoxy(50, 14);
	cout << "��ǰ ���� �����ι��� ���� �㱸�� �ι����� �˷��帳�ϴ�.";
	Sleep(500);
	CM::SetColor(WHITE);
	CM::gotoxy(46, 12);
	cout << "�� �̾߱�� ���� Ư�� �ι��� ��Ī�Ͽ� �ۼ��� �̾߱Ⱑ �ƴϸ�,";
	CM::gotoxy(50, 14);
	cout << "��ǰ ���� �����ι��� ���� �㱸�� �ι����� �˷��帳�ϴ�.";
	Sleep(3000);
	Sleep(500);
	CM::SetColor(DARK_GRAY);
	CM::gotoxy(46, 12);
	cout << "�� �̾߱�� ���� Ư�� �ι��� ��Ī�Ͽ� �ۼ��� �̾߱Ⱑ �ƴϸ�,";
	CM::gotoxy(50, 14);
	cout << "��ǰ ���� �����ι��� ���� �㱸�� �ι����� �˷��帳�ϴ�.";
	Sleep(500);
	CM::SetColor(BLACK);
	system("cls");
	CM::SetColor(GRAY);
}


void Story::pro()
{
	PlaySound(TEXT("���ѷα�.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	CM::gotoxy(30, 3);
	cout << "��ȭ�Ӱ� �б���Ȱ�� �ϰ� �ִ� �Ǳ����б� 09�й� ���ñ达..." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 5);
	cout << "������ ������ �׾ư��� �ִ� �״�, ��� �� ���ڱ� ū �÷��� �°� �ȴ�" << endl;
	if (skip())
		return;
	CM::gotoxy(30, 7);
	cout << "�ٷ� ����� �ϰ��ִ� 1�г� �������� ��������Ʈ�� ������ �ϰ� �� ��!" << endl;
	if (skip())
		return;
	CM::gotoxy(30, 9);
	cout << "���ñ达�� �Ĺ��� �����ؼ� ������ �س����� ������ ���̶�� �����ߴ�." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 11);
	cout << "������, ���ñ达�� �������� ���ñ达�� �������� �ɰ��ߴ�!" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (09�й� ���ñ�)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �̹� ���õ� �������� �ƹ��� �ȿ��ٴ�....               ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(33, 3);
	cout << "����ģ ���� �������� �Ұ��Ѵ�....." << endl;
	if (skip())
		return;
	CM::gotoxy(33, 5);
	cout << "�켱 �׸����Ʊ��� �ͽŵ���� 17�й�  �������� " << "\n" << "\n" << endl;
	if (skip())
		return;

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (17�й� ������)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �� �˼��ؿ� ���� ���� ��� �����ؾ� �Ǽ�..             ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "�ι�°�� ���ýð����� ���������� ������ ������ �����Ѵٴ� 17�й� ��ǰ���" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (17�й� ��ǰ�)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���ڱ� ���������� �������� ������ �� ������ �Ǽ�..     ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "����°�� ���ڲ��� �´ٰ� ����ϸ鼭 �׻� �����ߴٴ� 14�й� ���л� ��ؾ" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (14�й� ��ؾ�)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���̰� �� ������ ���ȳ�! ���� �� ������ �� ���Կ�      ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "����������..�����ð����� ���� �ڳ��� ���ýð����� �𸣰ڴٰ� ���Ѱܹ�����," << "\n" << "\n" << endl;
	CM::gotoxy(30, 5);
	cout << "���� ������ �� ����� ������ 17�й� �Ƹ�����!" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (17�й� �Ƹ���)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �� �𸣰ڴµ�.. �� ppt����Կ�!                        ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "��....���̻��� �ȵȴ�! �Ѹ� �����;��� ������ �ϰڱ���!" << endl;
	if (skip())
		return;;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "������ ã�� ������ ���ñ达..." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 5);
	cout << "���� ������ ���� �����Ѵ�..." << endl;
	system("cls");
}


void Story::endingcredit()
{
	CM::SetColor(15);
	CM::gotoxy(55, 1);
	cout << "���� �����" << endl;
	Sleep(700);
	CM::gotoxy(55, 3);
	cout << "���� ��ȹ" << endl;
	Sleep(700);
	CM::gotoxy(55, 5);
	cout << "�����, �Ǳ���, ��â��, ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 7);
	cout << "���ɺ�� ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 9);
	cout << "��â��, ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 11);
	cout << "���� ��� ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 13);
	cout << "�Ǳ���" << endl;
	Sleep(700);
	CM::gotoxy(55, 15);
	cout << "�������� ��� ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 17);
	cout << "��â��" << endl;
	Sleep(700);
	CM::gotoxy(55, 19);
	cout << "������� ��� ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 21);
	cout << "�����" << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(55, 3);
	cout << "���丮 ��ȹ" << endl;
	Sleep(700);
	CM::gotoxy(55, 5);
	cout << "�����, �Ǳ���, ��â��, ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 7);
	cout << "UI ���" << endl;
	Sleep(700);
	CM::gotoxy(55, 9);
	cout << "�Ǳ���" << endl;
	Sleep(700);
	CM::gotoxy(55, 11);
	cout << "���� ���" << endl;
	Sleep(700);
	CM::gotoxy(55, 13);
	cout << "�����" << endl;
	Sleep(700);
	CM::gotoxy(55, 15);
	cout << "���丮 ������" << endl;
	Sleep(700);
	CM::gotoxy(55, 17);
	cout << "����" << endl;
	Sleep(700);
	CM::gotoxy(55, 19);
	cout << "���� �������� ����" << endl;
	Sleep(700);
	CM::gotoxy(55, 21);
	cout << "��â��" << endl;
	if (skip())
		return;
	PlaySound(NULL, 0, 0);
	system("cls");
}

void Story::endinglogo()
{
	int i;
	int count = 0;

	while (count < 20)
	{
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 7);
		cout << "������    ��           �����        �����                      ��  " << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 8);
		cout << "    ��        ��           ��              ��                            ��" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 9);
		cout << "    ��        ��           ��              ��                            ��" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 10);
		cout << "    ��        �����     �����        �����    �����    �����" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 11);
		cout << "    ��        ��    ��     ��              ��          ��    ��    ��    ��" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 12);
		cout << "    ��        ��    ��     ��              ��          ��    ��    ��    ��" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 13);
		cout << "    ��        ��    ��     �����        �����    ��    ��    �����" << endl;
		Sleep(200);
		count++;
	}
	if (skip())
		return;
	system("cls");
	CM::SetColor(15);
}

void Story::title()
{
	CM::gotoxy(15, 7);
	cout << "     �����   ��     ������     �����   ��                                                    ��               " << endl;
	CM::gotoxy(15, 8);
	cout << "     ��         ��       ��  ��             ��   ��           ��                    ������     ������  ��       " << endl;
	CM::gotoxy(15, 9);
	cout << "     �����   ��       ��  ��             ��   ��         ��  ��      ��          ��      ��                 ��     " << endl;
	CM::gotoxy(15, 10);
	cout << "     ��         ��     ������           ��   ��       ��      ��    ��          ��      ��         ��      ��     " << endl;
	CM::gotoxy(15, 11);
	cout << "     �����   ��                          ��   ��     ��          ��  ��          ��      ��       ��  ��  ���     " << endl;
	CM::gotoxy(15, 12);
	cout << "                     ��������                       ��      ��    ��          ������         ��      ��     " << endl;
	CM::gotoxy(15, 13);
	cout << "       ������      ������         ������        ��  ��      ��              ��                     ��      " << endl;
	CM::gotoxy(15, 14);
	cout << "       ��      ��              ��         ��      ��          ��        ��              ��             �����        " << endl;
	CM::gotoxy(15, 15);
	cout << "       ��      ��      ������         ��      ��                    ��              ��             ��    ��        " << endl;
	CM::gotoxy(15, 16);
	cout << "       ��      ��      ��                 ��      ��                              ��������       ��    ��        " << endl;
	CM::gotoxy(15, 17);
	cout << "       ������      ������         ������     ���������                              �����        " << endl;

	if (skip())
		return;

	system("cls");


}

void Story::clear()
{

	CM::gotoxy(35, 3);
	cout << ".....����߱�... �̹��� ����ָ�. " << endl;
	PlaySound(TEXT("Ŭ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	Sleep(2000);
	PlaySound(NULL, 0, 0);
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 10);
	CM::SetColor(12);
	cout << "�׷� ���� ���� ������ �����Ϸ� ������....?? " << endl;
	if (skip())
		return;
	system("cls");
	CM::SetColor(15);
}

void Story::ghost()
{
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� ������)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ��....����... ���� ����..? ��...��?                  ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( ??�й� ???)                                          ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "��  ���� ����!! ������!!!                               ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� ������)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �츮 ������ ��Ҹ��ε�..???                            ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "�ٵ� ���� ����....." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� ������)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ��?? ���� ��!! ���⼭ �� �����ּ���!!                  ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "������... ������縦 �ΰ�� ���ÿ� ������...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "�� ������� �ʴ� ���� ��� ��Ʈ������ ���ٸ� Ż�� �� �� �ִ�....." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� ������)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �� ���� ��?? �˼��ؿ� ���� �� �����ҰԿ�!! �����ּ���!!��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "���� ��� ������ ������ ���ÿ� ������..." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "�� ������ �´� ��Ʈ������ ����Ѵٸ� ���� �� �ִ�." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "������ ������� ���Ѵٸ�...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "���� �⿩���� 0�̾�!! F��������!!..." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(45, 9);
	CM::SetColor(12);
	cout << "�� ���� ������ ��������!!!!!" << endl;
	if (skip())
		return;
	system("cls");
	CM::SetColor(15);
}

void Story::blackout()
{
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 14�й� ��ؾ�)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���� ��!! �� ��¥ �����߾��. ������ ����� �����Կ�!! ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "�������� ����...�̹����� ����...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "���� ���°��� �����Ÿ��� �հ� ��Ʈ������ Ŭ�����Ѵٸ� �����ָ�..." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::rotate()
{
	CM::gotoxy(35, 17);
	cout << "��������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                          ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� ��ǰ�)                                         ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                          ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���� ���� �� ���� �������� �������� ������ �������ſ���!!��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                          ��" << endl;
	CM::gotoxy(35, 23);
	cout << "��������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "����ģ���� �ǻ��ΰ�...? ī�䰡 �����ΰ�..?" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "��������ó�� ���ۺ��� ���� ��Ʈ������. Ŭ���� �غ���." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::reverse()
{
	CM::gotoxy(35, 17);
	cout << "��������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                          ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 17�й� �Ƹ���)                                         ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                          ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���� �� �� ������ ���߸��ؼ� ������ �� ����            ��" << endl;
	CM::gotoxy(35, 22);
	cout << "�� ���� ��ĥ��� ppt����ٴ� �ſ���!!                       ��" << endl;
	CM::gotoxy(35, 23);
	cout << "��������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "���� �ð��� ���� �����ؼ� ���� ������ ������...??" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "�𸣰ڴٴ� ���� �µ����� ���۹��� ���� �𸥴�. �ѹ� �õ��غ���..." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::ending()
{
	PlaySound(TEXT("����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	CM::gotoxy(35, 3);
	cout << "��Ʈ������ ���� �ٸ� ��� ���� ���� ��� �� ���� �ϼ��Ѵ�. ���õ� �׷� ���̴�." << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� ( 09�й� ���ñ�)                                       ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ���õ� ȥ�� �����̱���...                              ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "���ñ��� �̹� �б⸦ ���������� �б��� ��������," << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "���� �����鿡�� ��Ʈ������ ���� ��������Ʈ�� ������ �ǹ̸� ������ �ְ� �;���" << endl;
	if (skip())
		return;

	system("cls");
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "��  ( ������)                                             ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �����...!!                                            ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");
}

void Story::boss()
{
	CM::gotoxy(35, 3);
	cout << "�߰� ������ ��..." << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (������)                                               ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� �ٸ� �������� ��� �ִ°�???                         ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "�������������������������������" << endl;
	CM::gotoxy(35, 18);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 19);
	cout << "�� (09�й� ���ñ�)                                        ��" << endl;
	CM::gotoxy(35, 20);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 21);
	cout << "�� ��...? �׷��ϱ�....                                    ��" << endl;
	CM::gotoxy(35, 22);
	cout << "��                                                        ��" << endl;
	CM::gotoxy(35, 23);
	cout << "�������������������������������" << endl;
	if (skip())
		return;
	system("cls");

}