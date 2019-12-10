#include <iostream> 
#include "menu.h"
using namespace std;
void mainMenu() {
	int questions = 0;
	cout << "1. Danh cho Giang vien " << endl;
	cout << "2. Danh cho Thi sinh " << endl;
	cout << "3.Thoat chuong trinh !" << endl;
	cout << "Lua chon: ";
	cin >> questions;
	system("cls");
	switch (questions)
	{
	case 1:
		menuGiaoVien();
		break;
	case 2:
		menuSinhVien();
		break;
	case 3:
		exit(1);
	}
}
void menuGiaoVien() {
	int questions = 0;
	cout << "	menu Giang Vien " << endl;
	cout << "1.Them Cau Hoi " << endl;
	cout << "2.Xem Diem Thi " << endl;
	cout << "3.Tro Lai " << endl;
	cout << "Lua chon: ";
	cin >> questions;
	system("cls");
	switch (questions)
	{
	case 1:
		cout << " Moi Nhap Cau Hoi" << endl;
		break;
	case 2:
		cout << " Danh Sach Diem Thi :" << endl;
		break;
	case 3:
		mainMenu();
		break;
	}
}
void menuSinhVien() {
	int questions = 0;
	cout << "	menu Sinh Vien " << endl;
	cout << "1.Bat Dau Thi " << endl;
	cout << "2.Xem Diem Thi " << endl;
	cout << "3.Tro Lai " << endl;
	cout << "Lua chon: ";
	cin >> questions;
	system("cls");
	switch (questions)
	{
	case 1:
		cout << " Ma De:" << endl;
		break;
	case 2:
		cout << " Nhap Ma So Sinh Vien Cua Ban:" << endl;
		break;
	case 3:
		mainMenu();
		break;
	}
}