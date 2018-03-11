#include "TU.h"



TU::TU()
{
}


TU::~TU()
{
}
wchar_t* TU::GetTuTA() {
	return tuTA;
}
wchar_t* TU::GetPhienAm() {
	return phienAm;
}
vector<NGHIATV> TU::GetDsNghiaTV() {
	return dsNghiaTV;
}

void TU::SetTuTA(wchar_t* tuTA) {
	this->tuTA = new wchar_t[1000];
	wcsncpy(this->tuTA, tuTA,1000);
}
void TU::SetPhienAm(wchar_t* phienAm) {
	wcsncpy(this->phienAm, phienAm,1000);
}
void TU::SetNghiaTV(vector<NGHIATV> nghiaTV) {
	this->dsNghiaTV = nghiaTV;
}

void TU::Nhap() {
	tuTA=new wchar_t[100];
	XULYCHUOI chuoi(tuTA);
	wchar_t*s = new wchar_t[100];
	XULYCHUOI buffer(s);
	printf("Nhập từ Tiếng Anh: ");
	chuoi.getwstring(100);
	buffer.getwstring(100);
	int tl;
	NGHIATV nghiaTV;
	nghiaTV.Nhap();
	dsNghiaTV.push_back(nghiaTV);
	if (nghiaTV.GetLoaiTu() != NULL) {
		printf("\nBạn có muốn nhập thêm nghĩa tiếng Việt với từ loại mới không (0-không, 1-có)?: ");
		cin >> tl;
		cin.ignore();
		while (tl == 1) {
			NGHIATV nghiaTV;
			nghiaTV.Nhap();
			dsNghiaTV.push_back(nghiaTV);
			printf("\nBạn có muốn nhập thêm nghĩa tiếng Việt với từ loại mới không (0-không, 1-có)?: ");
			cin >> tl;
			cin.ignore();
		}
	}
}

void TU::Xuat() {
	printf("*******************");
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), tuTA, wcslen(tuTA), 0, 0);
	printf("*******************\n");
	for (int i = 0; i < dsNghiaTV.size(); i++) {
		dsNghiaTV[i].Xuat();
	}
}