#pragma once
#include "Tetrix.h"
#include "ConsoleManager.h"
#include "Story.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
class Graphics
{
private:
	static void show_block(Block& b);
public:
	Graphics();
	~Graphics();
	static void show_title();
	static bool show_logo(int& clear);
	static int show_story(int& clear);
	static int show_arcade();
	static int choice_continue();
	static int input_data();
	static void show_gameover();
};