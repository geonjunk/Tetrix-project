#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ConsoleManager.h"
#include "Tetrix.h"

using namespace std;

class Story
{
public:
	Story();
	~Story();
	static void caution();
	static void pro();
	static void endingcredit();
	static void endinglogo();
	static void title();
	static void clear();
	static void ghost();
	static void blackout();
	static void rotate();
	static void reverse();
	static void boss();
	static void ending();
	static bool skip();
};