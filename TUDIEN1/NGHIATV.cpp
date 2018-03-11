#include "NGHIATV.h"



NGHIATV::NGHIATV()
{
}


NGHIATV::~NGHIATV()
{
}

wchar_t* NGHIATV::GetLoaiTu() {
	return loaiTu;
}
wchar_t** NGHIATV::GetNghiaTV() {
	return nghiaTV;
}

void NGHIATV::SetLoaiTu(wchar_t *loaiTu) {
	this->loaiTu = new wchar_t[500];
	wcscpy(this->loaiTu, loaiTu);
}

void NGHIATV::SetNghiaTV(wchar_t **nghiaTV) {
	int i = 0;
	this->nghiaTV = new wchar_t*[50];

	while (nghiaTV[i] != L"dung") {
		this->nghiaTV[i] = new wchar_t[500];
		wcscpy(this->nghiaTV[i], nghiaTV[i]);
		i++;
	}
	this->nghiaTV[i] = L"dung";
}

void NGHIATV::Nhap() {
	int tl;
	nghiaTV = new wchar_t*[50];
	wchar_t*s = new wchar_t[100];
	XULYCHUOI buffer(s);
	printf("Bạn có muốn nhập từ loại không (0-không, 1-có)?: ");
	cin >> tl;
	cin.ignore();
	if (tl == 0) {
		loaiTu = NULL;
		int tl1 = 1;
		int i = 0;
		while (tl1 == 1) {
			wchar_t *chuoi = new wchar_t[500];
			XULYCHUOI dong(chuoi);
			nghiaTV[i] = new wchar_t[500];
			printf("\nVui lòng nhập nghĩa Tiếng Việt, bắt đầu bằng '-':\n");
			dong.getwstring(500);
			wcsncpy(nghiaTV[i], dong.chuoi, 500);
			buffer.getwstring(100);
			i++;
			printf("Bạn còn muốn nhập nghĩa TV nữa không (0-không, 1-có)?:");
			cin >> tl1;
			cin.ignore();
		}
		nghiaTV[i] = L"dung";
	}
	else {
		loaiTu = new wchar_t[100];
		XULYCHUOI dong1(loaiTu);
		printf("Nhập từ loại: ");
		dong1.getwstring(500);
		buffer.getwstring(100);
		int tl1 = 1;
		int i = 0;
		while (tl1 == 1) {
			wchar_t *chuoi = new wchar_t[500];
			XULYCHUOI dong(chuoi);
			nghiaTV[i] = new wchar_t[500];
			printf("\nVui lòng nhập nghĩa Tiếng Việt, bắt đầu bằng '-':\n");
			dong.getwstring(500);
			wcsncpy(nghiaTV[i], dong.chuoi, 500);
			buffer.getwstring(100);
			i++;
			printf("Bạn còn muốn nhập nghĩa TV nữa không (0-không, 1-có)?:");
			cin >> tl1;
			cin.ignore();
		}
		nghiaTV[i] = L"dung";
	}
}

void NGHIATV::Xuat() {
	if (loaiTu == NULL) {
		int i = 0;
		while (nghiaTV[i] != L"dung") {
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), nghiaTV[i], wcslen(nghiaTV[i]), 0, 0);
			printf("\n");
			i++;
		}
	}
	else {
		printf("###");
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), loaiTu, wcslen(loaiTu), 0, 0);
		cout << endl;
		int i = 0;
		while (nghiaTV[i] != L"dung") {
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), nghiaTV[i], wcslen(nghiaTV[i]), 0, 0);
			printf("\n");
			i++;
		}
	}
	printf("--------------------------------------\n");
}
