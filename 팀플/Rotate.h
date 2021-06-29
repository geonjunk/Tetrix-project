#pragma once
#include "Block.h"
#include "STAGE.h"
#include "Tetrix.h"

class Rotate
	:public Tetrix
{
public:
	int rotate; // ���� ��� : rotate�� 0�� ���� ������, +�� �� ������ �ݽð�������� 90�� �� ��
	int dis_x, dis_y; // ���� ��� : ȭ�鿡 ǥ���� goto�� x,y��ǥ
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
