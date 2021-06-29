#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include "STAGE.h"
#include "Block.h"
#include "ConsoleManager.h"
#include "Graphics.h"
using namespace std;

//*********************************
//상수 선언
//*********************************

const int EXT_KEY = 0xffffffe0;   //확장키 인식값 
const int KEY_LEFT = 0x4b;
const int KEY_RIGHT = 0x4d;
const int KEY_UP = 0x48;
const int KEY_DOWN = 0x50;

enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

class Tetrix {
protected:
	//*********************************
	//멤버변수선언
	//*********************************
	int highScore;
	bool isStory;
	bool isClear;
	char level;
	int ab_x, ab_y;   //화면중 블럭이 나타나는 좌표의 절대위치
	Block now_block, next_block, temp;
	int score;
	int lines;
	char total_block[21][14];      //화면에 표시되는 블럭들
	STAGE stage_data[10];
	char block[7][4][4][4] = {
		//막대모양
		1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

		//네모모양
		1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

		//'ㅓ' 모양
		0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'ㄱ'모양
		1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'ㄴ' 모양
		1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

		//'Z' 모양
		1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

		//'S' 모양
		0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

	};
	//*********************************
	//함수 선언
	//*********************************

	void init();
	virtual void show_cur_block(Block& b);
	virtual void erase_cur_block(Block& b);
	virtual void show_bottom_block(Block& b);
	virtual void erase_bottom_block(Block& b);
	virtual void show_next_block(Block& next_block);
	virtual void rotate_block(Block& b);
	virtual void show_total_block();
	void block_start(Block& b);
	virtual bool strike_check(Block& b);
	virtual void show_gamestat();
	virtual void check_full_line();
	virtual void merge_block(Block& b);
	virtual int move_block(Block& now_block, Block& next_block);
public:
	bool getIsClear();
	virtual void game();
	Tetrix();
	Tetrix(bool is);
	~Tetrix();

};

