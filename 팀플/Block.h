#pragma once
#include "STAGE.h"
#include <ctime>
#include <cstdlib>
class Block
{
private:
	int shape, angle, x, y, ghost_rate;
public:
	Block();
	~Block();
	Block(STAGE& stage);
	Block(const int& block_shape, const int& block_angle, const int& block_x, const int& block_y);
	int getShape();
	int getAngle();
	int getX();
	int getY();
	void setShape(const int& block_shape);
	void setAngle(const int& block_angle);
	void setX(const int& block_x);
	void setY(const int& block_y);
	int getGhost();
};

