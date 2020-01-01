#pragma once
#include<iostream>
#include<string>
using namespace std;
class cauhoi
{
private:
	int ID_ch;
	char NoiDung[255];
	char DapAn1[255];
	char DapAn2[255];
	char DapAn3[255];
	char DapAn4[255];
	int DapAnDung = 0;
	bool available = 0;
public:
	cauhoi();
	cauhoi(const cauhoi& obj);
	cauhoi(int _ID_ch, char* _NoiDung, char* _DapAn1, char* _DapAn2, char* _DapAn3, char* _DapAn4,int _DapAnDung, bool _available);
	void scan();
	void scancauhoi();
	void scandapan();
	void print();
	void operator=(const cauhoi& obj);
	friend class database;
	friend void Thi(int _ID_thisinh);
};
class thi
{
private:
	int ID_de=0;
	int ID_ch=0;
	int LuaChon=0;
	int DungSai=0;
public:
	thi();
	thi(const thi& obj);
	thi(int _ID_de, int _ID_ch, int _LuaChon,int _DungSai);
	void operator=(const thi& obj);
	friend class database;
	friend void Thi(int _ID_thisinh);
};
class de
{
private:
	int ID_de;
	int ID_thisinh;
	int SoCau;
	float KetQua;
public:
	de();
	de(const de& obj);
	de(int _ID_de, int _ID_thisinh, int _SoCau,float _Ketqua=0.0);
	void operator=(const de& obj);
	friend class database;
};
class thisinh
{
private:
	int ID_thisinh;
	char TenThiSinh[255];
	char DiaChi[255];
public:
	thisinh();
	thisinh(const thisinh& obj);
	thisinh(int _ID_thisinh, char* _TenThiSinh, char* _DiaChi);
	void scan();
	void scanname();
	void scanaddress();
	int getID();
	void print();
	void operator=(const thisinh& obj);
	friend class database;
};