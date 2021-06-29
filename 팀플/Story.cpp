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
	cout << "본 이야기는 절대 특정 인물을 지칭하여 작성한 이야기가 아니며,";
	CM::gotoxy(50, 14);
	cout << "작품 내의 등장인물은 전원 허구의 인물임을 알려드립니다.";
	Sleep(500);
	CM::SetColor(GRAY);
	CM::gotoxy(46, 12);
	cout << "본 이야기는 절대 특정 인물을 지칭하여 작성한 이야기가 아니며,";
	CM::gotoxy(50, 14);
	cout << "작품 내의 등장인물은 전원 허구의 인물임을 알려드립니다.";
	Sleep(500);
	CM::SetColor(WHITE);
	CM::gotoxy(46, 12);
	cout << "본 이야기는 절대 특정 인물을 지칭하여 작성한 이야기가 아니며,";
	CM::gotoxy(50, 14);
	cout << "작품 내의 등장인물은 전원 허구의 인물임을 알려드립니다.";
	Sleep(3000);
	Sleep(500);
	CM::SetColor(DARK_GRAY);
	CM::gotoxy(46, 12);
	cout << "본 이야기는 절대 특정 인물을 지칭하여 작성한 이야기가 아니며,";
	CM::gotoxy(50, 14);
	cout << "작품 내의 등장인물은 전원 허구의 인물임을 알려드립니다.";
	Sleep(500);
	CM::SetColor(BLACK);
	system("cls");
	CM::SetColor(GRAY);
}


void Story::pro()
{
	PlaySound(TEXT("프롤로그.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	CM::gotoxy(30, 3);
	cout << "평화롭게 학교생활을 하고 있던 건국대학교 09학번 팀플김씨..." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 5);
	cout << "착실히 학점을 쌓아가고 있던 그는, 어느 날 갑자기 큰 시련을 맞게 된다" << endl;
	if (skip())
		return;
	CM::gotoxy(30, 7);
	cout << "바로 재수강 하고있는 1학년 전공수업 팀프로젝트의 조장을 하게 된 것!" << endl;
	if (skip())
		return;
	CM::gotoxy(30, 9);
	cout << "팀플김씨는 후배들과 협력해서 팀플을 해나가면 괜찮을 것이라고 생각했다." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 11);
	cout << "하지만, 팀플김씨의 팀원들은 팀플김씨의 생각보다 심각했다!" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (09학번 팀플김)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 이번 팀플도 조원들이 아무도 안오다니....               ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(33, 3);
	cout << "도망친 그의 팀원들을 소개한다....." << endl;
	if (skip())
		return;
	CM::gotoxy(33, 5);
	cout << "우선 그린조아교의 맹신도라는 17학번  석구람씨 " << "\n" << "\n" << endl;
	if (skip())
		return;

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (17학번 석구람)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 아 죄송해요 제가 종교 행사 참여해야 되서..             ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "두번째는 팀플시간마다 어지럼증이 심해져 병원에 가야한다는 17학번 김건강씨" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (17학번 김건강)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 갑자기 어지럼증이 심해져서 병원에 좀 가봐야 되서..     ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "세번째는 꼬박꼬박 온다고 대답하면서 항상 깜빡했다는 14학번 복학생 김붕어씨" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (14학번 김붕어)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 아이고 또 깜빡해 버렸네! 조장 형 다음엔 꼭 갈게요      ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "마지막으로..수업시간마다 매일 자놓고 팀플시간마다 모르겠다고 떠넘겨버리고," << "\n" << "\n" << endl;
	CM::gotoxy(30, 5);
	cout << "정작 시험은 잘 보기로 유명한 17학번 아몰랑씨!" << "\n" << "\n" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (17학번 아몰랑)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 잘 모르겠는데.. 전 ppt만들게요!                        ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "후....더이상은 안된다! 한명씩 데려와야지 참석을 하겠구만!" << endl;
	if (skip())
		return;;
	system("cls");

	CM::gotoxy(30, 3);
	cout << "팀원을 찾아 떠나는 팀플김씨..." << endl;
	if (skip())
		return;
	CM::gotoxy(30, 5);
	cout << "그의 여정이 지금 시작한다..." << endl;
	system("cls");
}


void Story::endingcredit()
{
	CM::SetColor(15);
	CM::gotoxy(55, 1);
	cout << "만든 사람들" << endl;
	Sleep(700);
	CM::gotoxy(55, 3);
	cout << "게임 기획" << endl;
	Sleep(700);
	CM::gotoxy(55, 5);
	cout << "고건준, 권기준, 우창석, 최준" << endl;
	Sleep(700);
	CM::gotoxy(55, 7);
	cout << "유령블록 개발" << endl;
	Sleep(700);
	CM::gotoxy(55, 9);
	cout << "우창석, 최준" << endl;
	Sleep(700);
	CM::gotoxy(55, 11);
	cout << "동굴 블록 개발" << endl;
	Sleep(700);
	CM::gotoxy(55, 13);
	cout << "권기준" << endl;
	Sleep(700);
	CM::gotoxy(55, 15);
	cout << "돌려돌려 블록 개발" << endl;
	Sleep(700);
	CM::gotoxy(55, 17);
	cout << "우창석" << endl;
	Sleep(700);
	CM::gotoxy(55, 19);
	cout << "몰라몰라 블록 개발" << endl;
	Sleep(700);
	CM::gotoxy(55, 21);
	cout << "고건준" << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(55, 3);
	cout << "스토리 기획" << endl;
	Sleep(700);
	CM::gotoxy(55, 5);
	cout << "고건준, 권기준, 우창석, 최준" << endl;
	Sleep(700);
	CM::gotoxy(55, 7);
	cout << "UI 담당" << endl;
	Sleep(700);
	CM::gotoxy(55, 9);
	cout << "권기준" << endl;
	Sleep(700);
	CM::gotoxy(55, 11);
	cout << "음향 담당" << endl;
	Sleep(700);
	CM::gotoxy(55, 13);
	cout << "고건준" << endl;
	Sleep(700);
	CM::gotoxy(55, 15);
	cout << "스토리 디자인" << endl;
	Sleep(700);
	CM::gotoxy(55, 17);
	cout << "최준" << endl;
	Sleep(700);
	CM::gotoxy(55, 19);
	cout << "보스 스테이지 설계" << endl;
	Sleep(700);
	CM::gotoxy(55, 21);
	cout << "우창석" << endl;
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
		cout << "■■■■■    ■           ■■■■        ■■■■                      ■  " << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 8);
		cout << "    ■        ■           ■              ■                            ■" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 9);
		cout << "    ■        ■           ■              ■                            ■" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 10);
		cout << "    ■        ■■■■     ■■■■        ■■■■    ■■■■    ■■■■" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 11);
		cout << "    ■        ■    ■     ■              ■          ■    ■    ■    ■" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 12);
		cout << "    ■        ■    ■     ■              ■          ■    ■    ■    ■" << endl;
		i = rand() % 15 + 1;
		CM::SetColor(i);
		CM::gotoxy(30, 13);
		cout << "    ■        ■    ■     ■■■■        ■■■■    ■    ■    ■■■■" << endl;
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
	cout << "     ■■■■   ■     ■■■■■     ■■■■   ■                                                    ■               " << endl;
	CM::gotoxy(15, 8);
	cout << "     ■         ■       ■  ■             ■   ■           ■                    ■■■■■     ■■■■■  ■       " << endl;
	CM::gotoxy(15, 9);
	cout << "     ■■■■   ■       ■  ■             ■   ■         ■  ■      ■          ■      ■                 ■     " << endl;
	CM::gotoxy(15, 10);
	cout << "     ■         ■     ■■■■■           ■   ■       ■      ■    ■          ■      ■         ■      ■     " << endl;
	CM::gotoxy(15, 11);
	cout << "     ■■■■   ■                          ■   ■     ■          ■  ■          ■      ■       ■  ■  ■■     " << endl;
	CM::gotoxy(15, 12);
	cout << "                     ■■■■■■■                       ■      ■    ■          ■■■■■         ■      ■     " << endl;
	CM::gotoxy(15, 13);
	cout << "       ■■■■■      ■■■■■         ■■■■■        ■  ■      ■              ■                     ■      " << endl;
	CM::gotoxy(15, 14);
	cout << "       ■      ■              ■         ■      ■          ■        ■              ■             ■■■■        " << endl;
	CM::gotoxy(15, 15);
	cout << "       ■      ■      ■■■■■         ■      ■                    ■              ■             ■    ■        " << endl;
	CM::gotoxy(15, 16);
	cout << "       ■      ■      ■                 ■      ■                              ■■■■■■■       ■    ■        " << endl;
	CM::gotoxy(15, 17);
	cout << "       ■■■■■      ■■■■■         ■■■■■     ■■■■■■■■                              ■■■■        " << endl;

	if (skip())
		return;

	system("cls");


}

void Story::clear()
{

	CM::gotoxy(35, 3);
	cout << ".....통과했군... 이번은 살려주마. " << endl;
	PlaySound(TEXT("클리어.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	Sleep(2000);
	PlaySound(NULL, 0, 0);
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 10);
	CM::SetColor(12);
	cout << "그럼 이제 다음 조원을 시험하러 가볼까....?? " << endl;
	if (skip())
		return;
	system("cls");
	CM::SetColor(15);
}

void Story::ghost()
{
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 석구람)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 으....으음... 여긴 어디야..? 감...옥?                  ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( ??학번 ???)                                          ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■  여기 어디야!! 꺼내줘!!!                               ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 석구람)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 우리 조원들 목소리인데..???                            ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "다들 깨어 났군....." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 석구람)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 어?? 조장 형!! 여기서 좀 꺼내주세요!!                  ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "석구람... 종교행사를 핑계로 팀플에 빠졌지...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "이 사라지지 않는 유령 블록 테트리스를 깬다면 탈출 할 수 있다....." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 석구람)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 네 조장 형?? 죄송해요 팀플 잘 참여할게요!! 꺼내주세요!!■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "너희 모두 각자의 이유로 팀플에 빠졌지..." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "그 이유에 맞는 테트리스를 통과한다면 나갈 수 있다." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "하지만 통과하지 못한다면...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "너희 기여도는 0이야!! F학점이지!!..." << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(45, 9);
	CM::SetColor(12);
	cout << "자 이제 게임을 시작하자!!!!!" << endl;
	if (skip())
		return;
	system("cls");
	CM::SetColor(15);
}

void Story::blackout()
{
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 14학번 김붕어)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 조장 형!! 저 진짜 깜빡했어요. 다음엔 까먹지 않을게요!! ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "저번에도 깜빡...이번에도 깜빡...." << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "너의 기억력같은 깜빡거림을 뚫고 테트리스를 클리어한다면 꺼내주마..." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::rotate()
{
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                          ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 김건강)                                         ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                          ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 조장 오빠 저 정말 고질적인 어지럼증 때문에 병원간거에요!!■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                          ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "남자친구가 의사인가...? 카페가 병원인가..?" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "어지럼증처럼 빙글빙글 도는 테트리스다. 클리어 해봐라." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::reverse()
{
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                          ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 17학번 아몰랑)                                         ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                          ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 조장 형 저 수업에 집중못해서 내용을 잘 몰라서            ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■ 피해 끼칠까봐 ppt만든다는 거에요!!                       ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "팀플 시간에 따로 공부해서 시험 점수는 높다지...??" << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "모르겠다는 너의 태도같이 조작법은 나도 모른다. 한번 시도해봐라..." << endl;
	if (skip())
		return;
	system("cls");
}

void Story::ending()
{
	PlaySound(TEXT("엔딩.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	CM::gotoxy(35, 3);
	cout << "테트리스는 서로 다른 블록 끼리 힘을 모아 한 줄을 완성한다. 팀플도 그런 것이다." << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ ( 09학번 팀플김)                                       ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 오늘도 혼자 팀플이구나...                              ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 3);
	cout << "팀플김은 이번 학기를 마지막으로 학교를 떠나지만," << endl;
	if (skip())
		return;
	CM::gotoxy(35, 5);
	cout << "남은 팀원들에게 테트리스를 통해 팀프로젝트의 진정한 의미를 설명해 주고 싶었다" << endl;
	if (skip())
		return;

	system("cls");
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■  ( 조원들)                                             ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 조장님...!!                                            ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");
}

void Story::boss()
{
	CM::gotoxy(35, 3);
	cout << "중간 점검의 날..." << endl;
	if (skip())
		return;
	system("cls");
	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (교수님)                                               ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 다른 팀원들은 어디에 있는가???                         ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

	CM::gotoxy(35, 17);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	CM::gotoxy(35, 18);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 19);
	cout << "■ (09학번 팀플김)                                        ■" << endl;
	CM::gotoxy(35, 20);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 21);
	cout << "■ 예...? 그러니까....                                    ■" << endl;
	CM::gotoxy(35, 22);
	cout << "■                                                        ■" << endl;
	CM::gotoxy(35, 23);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	if (skip())
		return;
	system("cls");

}