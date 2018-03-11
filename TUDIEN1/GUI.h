#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>                  
#include <ctime>		           	 
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h> 
#include"TUDIEN.h"

using namespace std;

static COORD coord = { 0, 0 };

class GUI
{
private:
	TUDIEN tuDien;
	TUDIEN dsGhiNho;
public:
	GUI();
	~GUI();

	void gotoxy(int x, int y);
	void loading();
	void DrawMainEntrance();
	void DrawMainMenu();
};

