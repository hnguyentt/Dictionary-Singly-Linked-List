#pragma once
#include<wchar.h>
using namespace std;
class XULYCHUOI
{
public:
	XULYCHUOI();
	~XULYCHUOI();
	XULYCHUOI(wchar_t*);

	wchar_t* chuoi;

	bool BatDauVoi(wchar_t);
	bool BatDauVoi(wchar_t*);
	wchar_t* LayChuoiCon(int, int);
	void getwstring(int);
	void SetChuoi(wchar_t*);
};

