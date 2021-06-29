#pragma once

class STAGE {      //각 스테이지마다의 난이도 설정
public:
	STAGE();
	~STAGE();
	STAGE(const int& speed, const int& stick_rate, const int& clear_line);
private:
	int speed;   //숫자가 낮을수록 속도가 빠르다
	int stick_rate;      //막대가 나오는 확률 0~99 , 99면 막대기만 나옴
	int clear_line;
public:
	int getSpeed();
	int getRate();
	int getLine();
};