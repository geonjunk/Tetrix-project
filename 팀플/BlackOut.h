#pragma once
#include "Tetrix.h"

class BlackOut : public Tetrix {
	void show_around(Block& b);
	virtual void merge_block(Block& b);
	virtual int move_block(Block& now_block, Block& next_block);
	char keytemp;
public:
	BlackOut(); // 생성자 스테이지 -> 변경
	~BlackOut();
	BlackOut(bool is);
	virtual void game();
};

