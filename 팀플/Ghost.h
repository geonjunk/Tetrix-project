#pragma once
#include "Tetrix.h"
class Ghost :
	public Tetrix
{
public:
	Ghost();
	Ghost(bool is);
	~Ghost();
	virtual void game();
	virtual void show_cur_block(Block& b);
	virtual void erase_cur_block(Block& b);
	virtual void show_total_block(); // Rotate�� ������ ���ľ� ��. ���������δ� G�� ���
	virtual bool strike_check(Block& b); //
	virtual void merge_block(Block& b); //
	virtual int move_block(Block& now_block, Block& next_block); //
	virtual void check_full_line(); //
	virtual void show_next_block(Block& b); //
	void change(Block& b);
	void rechange(Block& b);
	virtual void show_bottom_block(Block& b);
	virtual void erase_bottom_block(Block& b);
	virtual void rotate_block(Block& b);
};

