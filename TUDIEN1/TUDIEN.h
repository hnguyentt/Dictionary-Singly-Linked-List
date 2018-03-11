#pragma once
#include"NODE.h"
#pragma execution_character_set( "utf-8" )

class TUDIEN
{
private:
	NODE *Head;
	NODE *Tail;
public:
	TUDIEN();
	~TUDIEN();

	void ThemDau(NODE*);
	void ThemCuoi(NODE*);

	void XoaDau();
	void XoaCuoi();
	void XoaNode(NODE*);
	void XoaTu(wchar_t*);

	void Nhap();
	void Xuat();

	void QuickSort(TUDIEN&);

	void DocFile(wchar_t*);
	NODE* binarySearch(wchar_t*);
	NODE* middleNode(NODE*, NODE*);
};

