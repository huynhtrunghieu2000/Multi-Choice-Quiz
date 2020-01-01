#include"table.h"
#include <iostream>
#include <string.h>
#include "ConnectDB.h"
///////////////////////////////////////////CAUHOI/////////////////////////////////////////////////////////////////////
cauhoi::cauhoi() {
	ID_ch = 0;
	strcpy_s(NoiDung, 255, "");
	strcpy_s(DapAn1, 255, "");
	strcpy_s(DapAn2, 255, "");
	strcpy_s(DapAn3, 255, "");
	strcpy_s(DapAn4, 255, "");
	DapAnDung = 0;
	available = 1;
}
cauhoi::cauhoi (const cauhoi& obj)
{
	ID_ch = obj.ID_ch;
	strcpy_s(NoiDung, 255, obj.NoiDung);
	strcpy_s(DapAn1, 255, obj.DapAn1);
	strcpy_s(DapAn2, 255, obj.DapAn2);
	strcpy_s(DapAn3, 255, obj.DapAn3);
	strcpy_s(DapAn4, 255, obj.DapAn4);
	DapAnDung = obj.DapAnDung;
	available = obj.available;
}
cauhoi::cauhoi(int _ID_ch, char* _NoiDung, char* _DapAn1, char* _DapAn2, char* _DapAn3, char* _DapAn4,int _DapAnDung, bool _available) {
		ID_ch = _ID_ch;
		strcpy_s(NoiDung, 255, _NoiDung);
		strcpy_s(DapAn1, 255, _DapAn1);
		strcpy_s(DapAn2, 255, _DapAn2);
		strcpy_s(DapAn3, 255, _DapAn3);
		strcpy_s(DapAn4,255, _DapAn4);
		DapAnDung = _DapAnDung;
		available = _available;
}
void cauhoi::scan()
{
	cin.ignore();
	cout << "NHAP NOI DUNG CAU HOI: ";
	cin.getline(NoiDung,255); cout << endl;

	cout << "NHAP NOI DUNG DAP AN 1: ";
	cin.getline(DapAn1, 255); cout << endl;

	cout << "NHAP NOI DUNG DAP AN 2: ";
	cin.getline(DapAn2, 255); cout << endl;

	cout << "NHAP NOI DUNG DAP AN 3: ";
	cin.getline(DapAn3, 255) ; cout << endl;

	cout << "NHAP NOI DUNG DAP AN 4: ";
	cin.getline(DapAn4, 255); cout << endl;

	cout << "DAP AN CUA CAU HOI TREN (1/2/3/4): ";
	do cin >> DapAnDung;
	while (DapAnDung < 1 || DapAnDung>4);
};
void cauhoi::scancauhoi()
{
	cin.ignore();
	cout << "NHAP NOI DUNG CAU HOI: ";
	cin.getline(NoiDung, 255); cout << endl;
}
void cauhoi::scandapan()
{
	int option=0;
	cout << endl
		<< " ===============================================================" << endl
		<< "|                                                              |" << endl
		<< "|             1/2/3/4.SUA DAP AN                               |" << endl
		<< "|             5.SUA DAP AN DUNG                                |" << endl
		<< "|                                                              |" << endl
		<< " ==============================================================" << endl;
	do {
		cout << "LUA CHON: ";
		cin >> option;
		if (option < 1 || option >6) cout << "NHAP LAI" << endl;
	} while (option < 1 || option >6);
	system("cls");
	cin.ignore();
	switch (option) {
	case 1:
		cout << "NHAP NOI DUNG DAP AN 1: ";
		cin.getline(DapAn1, 255); cout << endl;
		break;
	case 2:
		cout << "NHAP NOI DUNG DAP AN 2: ";
		cin.getline(DapAn2, 255); cout << endl;
		break;
	case 3:
		cout << "NHAP NOI DUNG DAP AN 3: ";
		cin.getline(DapAn3, 255); cout << endl;
		break;
	case 4:
		cout << "NHAP NOI DUNG DAP AN 4: ";
		cin.getline(DapAn4, 255); cout << endl;
		break;
	case 5:
		cout << "DAP AN CUA CAU HOI TREN (1/2/3/4): ";
		do cin >> DapAnDung;
		while (DapAnDung < 1 || DapAnDung>4);
		break;
	}
}
void cauhoi::print()
{
		cout << NoiDung << endl
		<< "1. " << DapAn1 << endl
		<< "2. " << DapAn2 << endl
		<< "3. " << DapAn3 << endl
		<< "4. " << DapAn4 << endl;
}

void cauhoi::operator=(const cauhoi& obj)
{
	ID_ch = obj.ID_ch;
	strcpy_s(NoiDung, 255, obj.NoiDung);
	strcpy_s(DapAn1, 255, obj.DapAn1);
	strcpy_s(DapAn2, 255, obj.DapAn2);
	strcpy_s(DapAn3, 255, obj.DapAn3);
	strcpy_s(DapAn4, 255, obj.DapAn4);
	DapAnDung = obj.DapAnDung;
}
///////////////////////////////////////////////////THI//////////////////////////////////////////////////////
thi::thi(){
	ID_de = 0;
	ID_ch = 0;
	LuaChon = 0;
	DungSai = 0;
}
thi::thi(int _ID_de, int _ID_ch, int _LuaChon,int _DungSai)
{
	ID_de = _ID_de;
	ID_ch = _ID_ch;
	LuaChon = _LuaChon;
	DungSai = _DungSai;
}
void thi::operator=(const thi& obj)
{
	ID_de = obj.ID_de;
	ID_ch = obj.ID_ch;
	LuaChon = obj.LuaChon;
}

thi::thi(const thi& obj)
{
	ID_de = obj.ID_de;
	ID_ch = obj.ID_ch;
	LuaChon = obj.LuaChon;
}
///////////////////////////////////////////DE////////////////////////////////////////////////////////////////////
de::de() {}
de::de(int _ID_de, int _ID_thisinh, int _SoCau,float _KetQua)
{
	ID_de = _ID_de;
	ID_thisinh = _ID_thisinh;
	SoCau = _SoCau;
	KetQua = _KetQua;
}
de::de(const de& obj)
{
	ID_de = obj.ID_de;
	ID_thisinh = obj.ID_thisinh;
	SoCau = obj.SoCau;
}
void de::operator=(const de& obj)
{
	ID_de = obj.ID_de;
	ID_thisinh = obj.ID_thisinh;
	SoCau = obj.SoCau;
}
/////////////////////////////////////////THISINH/////////////////////////////////////////////////////////////////
thisinh::thisinh() {
	ID_thisinh = 0;
	strcpy_s(TenThiSinh, 255, "");
	strcpy_s(DiaChi, 255, "");
}
thisinh::thisinh(const thisinh& obj)
{
	ID_thisinh = obj.ID_thisinh;
	strcpy_s(TenThiSinh, 255, obj.TenThiSinh);
	strcpy_s(DiaChi, 255, obj.DiaChi);
}
void thisinh::scan()
{
	cin.ignore();
	cout << "NHAP HO TEN: ";
	cin.getline(TenThiSinh, 255); cout << endl;
	cout << "NHAP DIA CHI: ";
	cin.getline(DiaChi, 255); cout << endl;
}
void thisinh::scanname()
{
	cin.ignore();
	cout << "NHAP HO TEN: ";
	cin.getline(TenThiSinh, 255); cout << endl;
}
void thisinh::scanaddress()
{
	cin.ignore();
	cout << "NHAP DIA CHI: ";
	cin.getline(DiaChi, 255); cout << endl;
}
void thisinh::print()
{
	cout << endl
		<< "==================================================" << endl
		<< "THI SINH: " << TenThiSinh << endl
		<< "MA THI SINH: " << ID_thisinh << endl
		<< "DIA CHI: " << DiaChi << endl
		<< "==================================================" << endl;
}
thisinh::thisinh(int _ID_thisinh, char* _TenThiSinh, char* _DiaChi)
{
	ID_thisinh = _ID_thisinh;
	strcpy_s(TenThiSinh, 255, _TenThiSinh);
	strcpy_s(DiaChi, 255, _DiaChi);
}
void thisinh::operator=(const thisinh& obj)
{
	ID_thisinh = obj.ID_thisinh;
	strcpy_s(TenThiSinh, 255, obj.TenThiSinh);
	strcpy_s(DiaChi, 255, obj.DiaChi);
}
int thisinh::getID()
{
	return ID_thisinh;
}