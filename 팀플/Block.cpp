#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(STAGE& stage)
{
	int i, j;
	i = rand() % 100;
	if (i <= stage.getRate()) {      //����� ����Ȯ�� ���
		shape = 0;                   //����� ������� ����
	}
	else
		shape = (rand() % 6) + 1;      //shape���� 1~6�� ���� ��
	j = rand() % 100;
	if (j <= (stage.getRate()/2)) {
		ghost_rate = 1;
	}
}

Block::Block(const int& block_shape, const int& block_angle, const int& block_x, const int& block_y)
	:shape(block_shape), angle(block_angle), x(block_x), y(block_y)
{
}

int Block::getShape()
{
	return shape;
}

int Block::getAngle()
{
	return angle;
}

int Block::getX()
{
	return x;
}

int Block::getY()
{
	return y;
}

void Block::setShape(const int& block_shape)
{
	this->shape = block_shape;
}

void Block::setAngle(const int& block_angle)
{
	this->angle = block_angle;
}

void Block::setX(const int& block_x)
{
	this->x = block_x;
}

void Block::setY(const int& block_y)
{
	this->y = block_y;
}

int Block::getGhost()
{
	return ghost_rate;
}