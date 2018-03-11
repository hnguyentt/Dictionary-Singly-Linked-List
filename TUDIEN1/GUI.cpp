#include "GUI.h"
#pragma execution_character_set( "utf-8" )
#include"XULYCHUOI.h"

GUI::GUI()
{
}


GUI::~GUI()
{
}

void GUI::gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GUI::loading()
{
	int i;
	for (i = 0; i<5; i++)
	{
		cout << i * 25 << "%%%%%";
		Sleep(200);
	}
	Sleep(200);
}

void GUI::DrawMainEntrance()
{
	system("cls");
	system("color 3F");
	gotoxy(5, 2);
	int choice = 0;

	printf("ÛÛÛÛÛÛÛÛÛÛÛ  ÛÛÛÛÛÛÛÛÛÛÛ       ÛÛÛÛÛ        ÛÛÛÛÛÛÛÛÛÛ    ÛÛÛÛÛÛÛÛÛÛÛ     "); gotoxy(5, 3);
	printf("ÛÛÛ     ÛÛÛ  ÛÛÛ              ÛÛÛ ÛÛÛ      ÛÛÛ            ÛÛÛ             "); gotoxy(5, 4);
	printf("ÛÛÛ     ÛÛÛ  ÛÛÛ             ÛÛÛ   ÛÛÛ     ÛÛÛ            ÛÛÛ             "); gotoxy(5, 5);
	printf("ÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛÛÛÛÛÛÛÛ    ÛÛÛ     ÛÛÛ    ÛÛÛ            ÛÛÛÛÛÛÛÛÛÛÛ     "); gotoxy(5, 6);
	printf("ÛÛÛ          ÛÛÛ           ÛÛÛÛÛÛÛÛÛÛÛÛÛ   ÛÛÛ            ÛÛÛ             "); gotoxy(5, 7);
	printf("ÛÛÛ          ÛÛÛ          ÛÛÛ         ÛÛÛ  ÛÛÛ            ÛÛÛ             "); gotoxy(5, 8);
	printf("ÛÛÛ          ÛÛÛÛÛÛÛÛÛÛÛ ÛÛÛ           ÛÛÛ  ÛÛÛÛÛÛÛÛÛÛ    ÛÛÛÛÛÛÛÛÛÛÛ     "); gotoxy(5, 11);


	cout << "**********************************************************************" << endl;
	gotoxy(5, 13);
	cout << "                     ENGLISH - VIETNAMESE DICTIONARY                  " << endl; gotoxy(5, 14);
	printf("                           TỪ ĐIỂN ANH - VIỆT                         ");
	gotoxy(5, 16);
	cout << "**********************************************************************" << endl; gotoxy(5, 18);
	printf("\nĐang khởi tạo cơ sở dữ liệu. Vui lòng chờ trong giây lát.\n");

	tuDien.DocFile(L"tudienmoi.txt");
	gotoxy(5, 22);
	loading();
	printf("\nCơ sở dữ liệu đã được khởi tạo thành công.\n");
	//Sleep(1500);
	system("cls");
	DrawMainMenu();
}

void GUI::DrawMainMenu() {
	int choice;
	while (true)
	{
		system("cls");
		printf("\n\n  _________________________LỰA CHỌN_________________________");
		printf("\n\n 1: Tìm từ");
		printf("\n\n 2: Thêm từ");
		printf("\n\n 3: Xoá từ");
		printf("\n\n 4: Xem danh sách từ ghi nhớ");
		printf("\n\n 5: Xoá từ khỏi danh sách ghi nhớ");
		printf("\n\n 6: Thoát ");
		printf("\n\n Nhập lựa chọn của bạn: ");

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '7')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		wchar_t *tuTA=new wchar_t[100];
		wchar_t *temp = new wchar_t[100];
		XULYCHUOI chuoi(temp);
		NODE *tu;
		NODE *p;
		int tl;
		wchar_t*s = new wchar_t[100];
		XULYCHUOI buffer(s);

		system("cls");
		switch (choice)
		{
		case '1':
			buffer.getwstring(100);
			printf("Nhập từ cần tìm: ");
			chuoi.getwstring(100);
			tuTA = temp;
			buffer.getwstring(100);
			tu = tuDien.binarySearch(tuTA);
			if (tu == NULL) {
				printf("\nKhông có từ cần tìm.\n");
			}
			else {
				tu->GetData().Xuat();
				printf("\nBạn có muốn thêm từ này vào danh sách ghi nhớ không (0-không, 1-có)? ");
				cin >> tl;
				//cin.ignore();
				if (tl == 1) {
					if (dsGhiNho.binarySearch(tuTA) == NULL) {
						p = new NODE(tu->GetData());
						dsGhiNho.ThemCuoi(p);
						dsGhiNho.QuickSort(dsGhiNho);
					}
					else {
						printf("\nTừ đã tồn tại trong danh sách ghi nhớ.\n");
					}
				}
			}
			system("pause");
			break;
		case '2':
			tuDien.Nhap();
			tuDien.QuickSort(tuDien);
			system("pause");
			break;
		case '3':
			buffer.getwstring(100);
			printf("Nhập từ cần xoá: ");
			chuoi.getwstring(100);
			buffer.getwstring(100);
			tuTA = temp;
			tuDien.XoaTu(tuTA);
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			printf("________________DANH SÁCH TỪ GHI NHỚ________________\n\n");
			dsGhiNho.Xuat();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			printf("________________DANH SÁCH TỪ GHI NHỚ________________\n\n");
			dsGhiNho.Xuat();
			buffer.getwstring(100);
			printf("\n\nNhập từ cần xoá: ");
			chuoi.getwstring(100);
			buffer.getwstring(100);
			tuTA = temp;
			dsGhiNho.XoaTu(tuTA);
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			exit(0);
			break;
		default:
			cout << "\n\n Vui lòng nhập lựa chọn hợp lệ: \n\n";
			system("pause");
			break;
		}
	}
}
