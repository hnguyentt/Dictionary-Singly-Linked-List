#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma execution_character_set( "utf-8" )
#include<fcntl.h>
#include<wchar.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<iostream>
#include<string>
#include"XULYCHUOI.h"

using namespace std;

class NGHIATV
{
private:
	wchar_t *loaiTu;
	wchar_t **nghiaTV;
public:
	NGHIATV();
	~NGHIATV();

	wchar_t* GetLoaiTu();
	wchar_t** GetNghiaTV();

	void SetLoaiTu(wchar_t *loaiTu);
	void SetNghiaTV(wchar_t **nghiaTV);

	void Nhap();
	void Xuat();
};

