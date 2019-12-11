#include<iostream>
#include<string>
using namespace std;
class cauhoi
{
private:
    int ID_ch=0;
    string NoiDung;
    string DapAn1;
    string DapAn2;
    string DapAn3;
    string DapAn4;
    int DapAnDung=0;
public:
    friend istream &operator>>(istream &is, cauhoi &cauhoi);
    friend ostream &operator<<(ostream &os,const cauhoi &cauhoi);
};
class thi
{
private:
    int ID_de;
    int ID_ch;
    int LuaChon;
    bool DungSai;
};
class de
{
private:    
    int ID_de;
    int ID_thisinh;
    int SoCau;
    string NgayTao;
};
class thisinh
{
    private:
    int ID_thisinh;
    string TenThiSinh;
    string DiaChi;
    string NgaySinh;
    public:
    friend istream &operator>>(istream &is, thisinh &thisinh);
    friend ostream &operator<<(ostream &os,const thisinh &thisinh);
};
