#include "TUDIEN.h"
#include<vector>
#include"XULYCHUOI.h"
#include<string>

TUDIEN::TUDIEN()
{
	Head = NULL;
	Tail = NULL;
}


TUDIEN::~TUDIEN()
{
}
void TUDIEN::DocFile(wchar_t *filename) {

	FILE *fin = _wfopen(filename, L"r,ccs=UTF-8");
	wchar_t** alllines = new wchar_t*[460600];
	int i = 0;
	while (!feof(fin)) {
		alllines[i] = new wchar_t[500];
		fgetws(alllines[i], 500, fin);
		i++;
	}
	//WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), alllines[2], wcslen(alllines[2]), 0, 0);
	int k = 2;
	while(k<i) {
		TU tu;
		wchar_t *tuTA = new wchar_t[500];
		NGHIATV nghiaTV;
		vector<NGHIATV> dsNghiaTV;
		wchar_t *temp = new wchar_t[500];
		XULYCHUOI dong(alllines[k]);
		wcscpy(tuTA, dong.LayChuoiCon(1, wcslen(alllines[k]) - 2));
		k++;
		dong.SetChuoi(alllines[k]);
		while (dong.BatDauVoi(L'*')) {
			wcscpy(temp, dong.LayChuoiCon(2, wcslen(alllines[k]) - 3));
			nghiaTV.SetLoaiTu(temp);
			k++;
			dong.SetChuoi(alllines[k]);
			int j = 0;
			wchar_t **dsnghia = new wchar_t*[50];
			while (!dong.BatDauVoi(L'@') && !dong.BatDauVoi(L'*') && k < i) {
				dsnghia[j] = new wchar_t[500];
				wcscpy(dsnghia[j], alllines[k]);
				j++;
				k++;
				dong.SetChuoi(alllines[k]);
			}
			dsnghia[j] = L"dung";
			nghiaTV.SetNghiaTV(dsnghia);
			delete[] dsnghia;
			dsNghiaTV.push_back(nghiaTV);
		}
		if (!dong.BatDauVoi(L'*') && !dong.BatDauVoi(L'@')) {
			int j = 0;
			wchar_t **dsnghia = new wchar_t*[50];
			while (!dong.BatDauVoi(L'@') && !dong.BatDauVoi(L'*') && k < i) {
				dsnghia[j] = new wchar_t[500];
				wcscpy(dsnghia[j], alllines[k]);
				j++;
				k++;
				dong.SetChuoi(alllines[k]);
			}
			dsnghia[j] = L"dung";
			nghiaTV.SetNghiaTV(dsnghia);
			delete[] dsnghia;
			dsNghiaTV.push_back(nghiaTV);
		}
		tu.SetNghiaTV(dsNghiaTV);
		NODE *p = new NODE(tu);
		ThemCuoi(p);
	}
	/*if (!fin) {
		printf("Không thể đọc file.\n");
	}
	else {
		wchar_t *line = new wchar_t[500];
		wchar_t *temp = new wchar_t[500];

		fgetws(line, 500, fin);
		fgetws(line, 500, fin);
		fgetws(line, 500, fin);
		while (!feof(fin)) {
			if (line == NULL)break;

			TU tu;
			wchar_t *tuTA=new wchar_t[500];
			NGHIATV nghiaTV;
			vector<NGHIATV> dsNghiaTV;

			XULYCHUOI dong(line);
			wcscpy(tuTA,dong.LayChuoiCon(1, wcslen(line) - 2));
			tu.SetTuTA(tuTA);
			
			fgetws(line, 500, fin);

			while (dong.BatDauVoi(L'*')) {

				wcscpy(temp,dong.LayChuoiCon(2, wcslen(line) - 3));
				nghiaTV.SetLoaiTu(temp);

				wchar_t **alllines = new wchar_t*[50];
				int i = 0;
				fgetws(line, 500, fin);
				while (!dong.BatDauVoi(L'@') && !dong.BatDauVoi(L'*')&&!feof(fin)) {
					alllines[i] = new wchar_t[500];
					wcscpy(alllines[i], line);
					i++;
					fgetws(line, 500, fin);
				}
				alllines[i] = L"dung";
				nghiaTV.SetNghiaTV(alllines);
				i=0;
				delete[] alllines;
				dsNghiaTV.push_back(nghiaTV);
			}
			if (!dong.BatDauVoi(L'*')&& !dong.BatDauVoi(L'@')) {
				int i = 0;
				wchar_t **alllines = new wchar_t*[50];
				while (!dong.BatDauVoi(L'@') && !dong.BatDauVoi(L'*')&&!feof(fin)) {
					alllines[i] = new wchar_t[500];
					wcscpy(alllines[i], line);
					i++;
					fgetws(line, 500, fin);
				}
				alllines[i] = L"dung";
				nghiaTV.SetNghiaTV(alllines);
				i = 0;
				delete[] alllines;
				dsNghiaTV.push_back(nghiaTV);
			}
			tu.SetNghiaTV(dsNghiaTV);
			NODE *p = new NODE(tu);
			ThemCuoi(p);
		}
	}*/
}

void TUDIEN::ThemDau(NODE* tu) {
	if (this->Head == NULL) {
		this->Head = tu;
		this->Tail = this->Head;
	}
	else {
		tu->SetNext(this->Head);
		this->Head = tu;
	}
}
void TUDIEN::ThemCuoi(NODE* tu) {
	if (this->Head == NULL)
		ThemDau(tu);
	else {
		this->Tail->SetNext(tu);
		this->Tail = tu;
	}
}

void TUDIEN::XoaDau() {
	NODE *h = this->Head;
	this->Head = this->Head->Next();
	delete(h);
}
void TUDIEN::XoaCuoi() {
	NODE *p = this->Head;
	while (p->Next() != this->Tail)
		p = p->Next();
	NODE *k = this->Tail;
	this->Tail = p;
	this->Tail->SetNext(NULL);
	delete(k);
}
void TUDIEN::XoaNode(NODE *p) {
	if (p == this->Head) {
		XoaDau();
	}
	else if (p == this->Tail) {
		XoaCuoi();
	}
	else {
		NODE *k = this->Head;
		while (k->Next() != p)
			k = k->Next();
		k->SetNext(p->Next());
		delete(p);
	}
}
void TUDIEN::XoaTu(wchar_t* tuTA) {
	NODE *p;
	for (p = this->Head; p; p = p->Next()) {
		wchar_t* tu = p->GetData().GetTuTA();
		XULYCHUOI chuoi(tu);
		if (wcscmp(p->GetData().GetTuTA(), tuTA) == 0 || (chuoi.BatDauVoi(tuTA) && tu[wcslen(tuTA)] == L' ' && tu[wcslen(tuTA)+1] == L'/')) {
			if (p == this->Head)
				this->XoaDau();
			else
				if (p == this->Tail)
					this->XoaCuoi();
				else
					this->XoaNode(p);
			break;
		}
	}
	if (p == NULL) {
		printf("\nKhông tìm thấy từ.\n");
	}
	else {
		printf("\n\nĐã xoá thành công\n");
	}
}

void TUDIEN::Nhap() {
	int n;
	printf("Nhập số từ mới cần thêm: ");
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		printf("\nNhập từ thứ ");
		cout << i + 1;
		cout << "\n---------------------------------\n";
		TU tu;
		tu.Nhap();
		printf("\nTừ đã nhập:\n");
		tu.Xuat();
		NODE *p = new NODE(tu);
		ThemCuoi(p);
		cout << endl << endl;
	}
}
void TUDIEN::Xuat() {
	int i = 0;
	TU tu;
	for (NODE *p = this->Head; p != NULL; p = p->Next()) {
		tu = p->GetData();
		tu.Xuat();
		if (p != this->Tail)
			printf("______________________________________________________________________________________\n\n\n\n\n");
		i++;
	}
	printf("****************************************************************************************\n\n");
}

NODE * TUDIEN::middleNode(NODE * startNode, NODE * endNode)
{
	if (startNode == NULL)
	{
		return NULL;
	}

	NODE * slowPtr = startNode;
	NODE * fastPtr = startNode->Next();

	while (fastPtr != endNode)
	{
		fastPtr = fastPtr->Next();

		//if (fastPtr == NULL) return NULL;

		if (fastPtr != endNode)
		{
			slowPtr = slowPtr->Next();
			fastPtr = fastPtr->Next();

		}
	}

	return slowPtr;
}

NODE* TUDIEN::binarySearch(wchar_t *valueToSearch)
{
	NODE * startNode = Head;
	NODE * endNode = NULL;
	wchar_t *tu;
	if (startNode == NULL) {
		return NULL;
	}
	do
	{
		if (startNode == endNode) {
			tu = startNode->GetData().GetTuTA();
			XULYCHUOI chuoi(tu);
			if (wcscmp(tu, valueToSearch) == 0 || (chuoi.BatDauVoi(valueToSearch) && tu[wcslen(valueToSearch)] == L' ' && tu[wcslen(valueToSearch) + 1] == L'/')) {
				return startNode;
			}
			else {
				return NULL;
			}
		}
		else {
			NODE *middle = middleNode(startNode, endNode);

			if (middle == NULL)
			{
				return NULL;
			}
			tu = middle->GetData().GetTuTA();
			XULYCHUOI chuoi(tu);
			wchar_t subs = tu[wcslen(valueToSearch)];
			if (wcscmp(tu, valueToSearch) == 0 || (chuoi.BatDauVoi(valueToSearch) && tu[wcslen(valueToSearch)] == L' ' && tu[wcslen(valueToSearch) + 1] == L'/'))
			{
				return middle;
			}
			else if (wcscmp(middle->GetData().GetTuTA(), valueToSearch)<0) {
				startNode = middle->Next();
				if (startNode == NULL) break;
			}
			else
			{
				endNode = middle;
			}
		}
	} while (endNode == NULL || endNode ->Next() != startNode);

	return NULL;
}

void TUDIEN::QuickSort(TUDIEN &tuDien) {
	TUDIEN l1, l2;
	NODE *pivot, *p;
	if (tuDien.Head == tuDien.Tail) return;
	pivot = tuDien.Head;
	tuDien.Head = tuDien.Head->Next();
	pivot->SetNext(NULL);
	while (tuDien.Head != NULL) {
		p = tuDien.Head;
		tuDien.Head = tuDien.Head->Next();
		p->SetNext(NULL);
		if (wcscmp(p->GetData().GetTuTA(),pivot->GetData().GetTuTA())<=0) l1.ThemCuoi(p);
		else l2.ThemCuoi(p);
	}
	QuickSort(l1);
	QuickSort(l2);
	if (l1.Head != NULL) {
		pivot->SetNext(l2.Head);
		l1.Tail->SetNext(pivot);
		tuDien.Head = l1.Head;
	}
	else {
		pivot->SetNext(l2.Head);
		tuDien.Head = pivot;
	}
}
