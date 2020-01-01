#include "DoTheTest.h"
#include <iomanip>
////////////////////////////////////////RANDOMIZE///////////////////////////////////////////////////////////
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void randomize(int arr[], int n)
{

	srand(time(NULL));


	for (int i = n - 1; i > 0; i--)
	{

		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}
///////////////////////////////////////////////////THI////////////////////////////////////////////////////
void Thi(int ID_thisinh)
{
	database db;
	db.init();
	List<thi> test;
	List<cauhoi> ch;
	db.insertDe(ID_thisinh);
	de de;
	int SoCau = db.demSoCau();
	int ID_de = db.getIDDe();
	int count = 0;
	int* pick = new int[SoCau];
	db.getIDch(pick);
	randomize(pick,SoCau);
	for (int i = 0; i < 20; i++)
	{

		thi tmp1(ID_de, pick[i], 0, 0);
		cauhoi tmp;
		tmp = db.getCauHoi(pick[i]);
		test.addTail(tmp1);
		ch.addTail(tmp);
	}
	test.current = test.head;
	ch.current = ch.head;
	while (test.current != NULL) {
		system("cls");
		ch.current->data.print();
		int choice = 0;
		cout << "===================================================================" << endl
			<< "DAP AN(1/2/3/4)          7.QUAY LAI      8.TIEP        9.NOP BAI" << endl
			<< "===================================================================" << endl;
		do {
			cout << "LUA CHON: ";
			cin >> choice;
			if ((choice < 1) || (choice > 4 && choice < 7) || (choice > 9)) cout << "Nhap lai"<<endl;
		} while ((choice < 1) || (choice > 4 && choice < 7) || (choice > 9));
		switch (choice)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			test.current->data.LuaChon = choice;
			if (choice == ch.current->data.DapAnDung) {
				test.current->data.DungSai = 1;
			}
			test.current = test.current->next;
			ch.current = ch.current->next;
			break;
		case 7:
			if (test.current->prev != NULL) {
				test.current = test.current->prev;
				ch.current = ch.current->prev;
			}
			break;
		case 8:
			if (test.current->next != NULL) {
				test.current = test.current->next;
				ch.current = ch.current->next;
			}
			break;
		case 9:
			test.current = NULL;
			ch.current = NULL;
			break;
		default:
			break;
		}
	}
	/*test.current = test.head;
	while (test.current != NULL) {
		cout<<setw(5)<< ID_de << setw(5) << test.current->data.ID_ch << setw(5) << test.current->data.LuaChon << setw(5) << test.current->data.DungSai<<endl;
		db.insertThi(test.current->data);
		test.current = test.current->next;
	}*/
	test.current = test.head;
	while (test.current != NULL) {
		if (test.current->data.DungSai == 1)count++;
		test.current = test.current->next;
	}
	double Diem = (10.0 / 20) * count;
	cout << "DIEM: " << Diem;
	db.updateKetQua(Diem,ID_de);
	db.close();
	delete[]pick;
}
