#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma execution_character_set( "utf-8" )
#include<fcntl.h>
#include<wchar.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include"NGHIATV.h"
#include<vector>
#include"XULYCHUOI.h"

using namespace std;

class TU
{
private:
	wchar_t* tuTA;
	wchar_t* phienAm;
	vector<NGHIATV> dsNghiaTV;
public:
	TU();
	~TU();
	wchar_t* GetTuTA();
	wchar_t* GetPhienAm();
	vector<NGHIATV> GetDsNghiaTV();

	void SetTuTA(wchar_t*);
	void SetPhienAm(wchar_t*);
	void SetNghiaTV(vector<NGHIATV>);

	void Nhap();
	void Xuat();
};

