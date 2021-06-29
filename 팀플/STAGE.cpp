#include "STAGE.h"

STAGE::STAGE() {
}

STAGE::~STAGE() {
}

STAGE::STAGE(const int& speed, const int& stick_rate, const int& clear_line) {
	this->speed = speed;
	this->stick_rate = stick_rate;
	this->clear_line = clear_line;
}

int STAGE::getSpeed()
{
	return speed;
}


int STAGE::getRate()
{
	return stick_rate;
}


int STAGE::getLine()
{
	return clear_line;
}
