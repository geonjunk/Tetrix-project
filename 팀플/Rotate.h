#pragma once
#include "Block.h"
#include "STAGE.h"
#include "Tetrix.h"

class Rotate
	:public Tetrix
{
public:
	int rotate; // 수정 사안 : rotate가 0일 때는 원상태, +가 될 때마다 반시계방향으로 90도 씩 돔
	int dis_x, dis_y; // 수정 사안 : 화면에 표기할 goto의 x,y좌표
	Rotate();
	Rotate(bool is);
	~Rotate();
	void Rotating(const int& rotate, int* x, int* y);
	virtual void show_cur_block(Block& b);
	virtual void erase_cur_block(Block& b);
	virtual void show_total_block();
	virtual void check_full_line();
	virtual void show_next_block(Block& next_block);
	virtual void show_gamestat();
	virtual void show_bottom_block(Block& b);
	virtual void erase_bottom_block(Block& b);
	virtual void game();
};
