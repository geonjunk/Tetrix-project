#pragma once
#include "Tetrix.h"
#include "Ghost.h"
#include "BlackOut.h"
#include "Rotate.h"
#include "Tetrix_Reverse.h"
#include "Graphics.h"
#include "Boss.h"
//#include "Tepago.h"

class gameManager
{
private:
	int clearStage, saveStage;
	Tetrix* t[5];
	int highScore;
	void arcade();
	void story();
	void tool(int num);
	Tetrix tetrix;
	Ghost ghost;
	Rotate rotate;
	BlackOut blackout;
	Reverse reverse;
public:
	gameManager();
	~gameManager();
	void gameStart();

};

