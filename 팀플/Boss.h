#pragma once
#include "Tetrix.h"
#include "Graphics.h"
#include "ConsoleManager.h"
#include <ctime>
#include <cstdlib>

class Boss : public Tetrix {
private :
	bool checkBlack = false;
	bool checkBBlack = false;
	bool checkBRotate = false;
	bool checkReverse = false;
	int game_change;
	//키바꾸기
	clock_t start, end;
	double duration = 0;
	int rKey, rTime;
	int is_gameover;
	char keytemp;
public:
	//Rotate
	int rotate; // 수정 사안 : rotate가 0일 때는 원상태, +가 될 때마다 반시계방향으로 90도 씩 돔
	int dis_x, dis_y; // 수정 사안 : 화면에 표기할 goto의 x,y좌표
	Boss(); // 생성자 스테이지 -> 변경
	Boss(bool is);
	~Boss();
	virtual void game();
	//유령블록
	virtual void show_cur_block(Block& b);
	virtual void erase_cur_block(Block& b);
	virtual void show_total_block();
	virtual bool strike_check(Block& b);
	virtual void merge_block(Block& b);
	virtual int move_block(Block& now_block, Block& next_block);
	virtual void check_full_line();
	virtual void show_next_block(Block& b);
	void Gchange(Block& block1);
	void Grechange(Block& block1);
	virtual void show_bottom_block(Block& block1);
	virtual void erase_bottom_block(Block& b);
	virtual void rotate_block(Block& b);
	//BlackOut
	void Bshow_around(Block& b);
	void Bmerge_block(Block& b);
	int Bmove_block(Block& now_block, Block& next_block);
	//Reverse
	void showLevel();
	void Rchange();
	void randKey1(int i);
	void randKey2(int i);
	void randKey3(int i);
	void randKey4(int i);
	void randKey5(int i);
	void randKey6(int i);
	//Rotate
	void Rotating(const int& rotate, int* x, int* y);
	void Rshow_cur_block(Block& b);
	void Rerase_cur_block(Block& b);
	void Rshow_total_block();
	void Rcheck_full_line();
	void Rshow_next_block(Block& next_block);
	void Rshow_gamestat();
	void Rshow_bottom_block(Block& b);
	void Rerase_bottom_block(Block& b);
	int Rmove_block(Block& now_block, Block& next_block);
	void Rmerge_block(Block& b);
	void Rrotate_block(Block& b);
};