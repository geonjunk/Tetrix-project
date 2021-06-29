#pragma once
#include "Tetrix.h"
class Reverse :
	public Tetrix
{
private:
	clock_t start, end;
	double duration =0;
	int rKey,rTime;
	int is_gameover;
	char keytemp;
public:
	Reverse();
	Reverse(bool is);
	~Reverse();
public:
	virtual void game();
	void showLevel();
	void change();
	void randKey1(int i);
	void randKey2(int i);
	void randKey3(int i);
	void randKey4(int i);
	void randKey5(int i);
	void randKey6(int i);
};

