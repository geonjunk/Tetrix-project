#pragma once

class STAGE {      //�� �������������� ���̵� ����
public:
	STAGE();
	~STAGE();
	STAGE(const int& speed, const int& stick_rate, const int& clear_line);
private:
	int speed;   //���ڰ� �������� �ӵ��� ������
	int stick_rate;      //���밡 ������ Ȯ�� 0~99 , 99�� ����⸸ ����
	int clear_line;
public:
	int getSpeed();
	int getRate();
	int getLine();
};