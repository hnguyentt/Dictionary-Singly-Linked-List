#include "XULYCHUOI.h"



XULYCHUOI::XULYCHUOI()
{
}


XULYCHUOI::~XULYCHUOI()
{
}
XULYCHUOI::XULYCHUOI(wchar_t *s) {
	chuoi = s;
}

bool XULYCHUOI::BatDauVoi(wchar_t s) {
	bool kq = false;
	if (chuoi[0] == s)
		kq = true;
	return kq;
}

bool XULYCHUOI::BatDauVoi(wchar_t *s) {
	bool kq = false;
	int dem = 0;
	for (int i = 0; i < wcslen(s); i++) {
		if (chuoi[i] != s[i])
			dem++;
	}
	if (dem == 0) {
		kq = true;
	}
	return kq;
}

wchar_t* XULYCHUOI::LayChuoiCon(int viTriBatDau, int soKyTu) {
	wchar_t *kq;
	kq = new wchar_t[soKyTu];
	int k = 0;
	for (int i = viTriBatDau; i < viTriBatDau + soKyTu; i++) {
		kq[k++] = chuoi[i];
	}
	kq[k] = '\0';
	return kq;
}

void XULYCHUOI::getwstring(int count) {
	int x = 0;
	wchar_t *a, wch;

	a = chuoi;
	while (x < count - 1) {
		wch = getwchar();
		if (wch == '\n') break;
		*a = wch;
		a++;
		x++;
	}
	*a = '\0';
}

void XULYCHUOI::SetChuoi(wchar_t* s) {
	chuoi = s;
}