#include"table.h"
istream &operator>>(istream &is, cauhoi &cauhoi)
{
 //   cout<<"ID_ch: ";
    cin>>cauhoi.ID_ch;
//    cout<<"Nhap noi dung cau hoi: ";
    is.ignore();
    getline(is,cauhoi.NoiDung);
    cout<<endl;
//    cout<<"Nhap noi dung dap an 1: ";
    getline(is,cauhoi.DapAn1);
    cout<<endl;
//    cout<<"Nhap noi dung dap an 2: ";
    getline(is,cauhoi.DapAn2);
    cout<<endl;
//    cout<<"Nhap noi dung dap an 3: ";
    getline(is,cauhoi.DapAn3);
    cout<<endl;
//    cout<<"Nhap noi dung dap an 4: ";
    getline(is,cauhoi.DapAn4);
    cout<<endl;
//    cout<<"Dap an cua cau hoi tren (1/2/3/4): ";
    do cin>>cauhoi.DapAnDung;
    while(cauhoi.DapAnDung<1||cauhoi.DapAnDung>4);
    return is;
};
ostream &operator<<(ostream &os,const cauhoi &cauhoi)
{
    cout<<cauhoi.NoiDung<<endl
        <<"1. "<<cauhoi.DapAn1<<endl
        <<"2. "<<cauhoi.DapAn2<<endl
        <<"3. "<<cauhoi.DapAn3<<endl
        <<"4. "<<cauhoi.DapAn4<<endl;
    return os;
}
istream &operator>>(istream &is, thisinh &thisinh)
{
    cout<<"ID_ch: ";
    cin>>thisinh.ID_thisinh;
    cout<<"Nhap ho ten thi sinh: ";
    is.ignore();
    getline(is,thisinh.TenThiSinh);
    cout<<endl;
    cout<<"Nhap dia chi cua thi sinh: ";
    getline(is,thisinh.DiaChi);
    cout<<endl;
    cout<<"Nhap ngay sinh cua thi sinh: ";
    getline(is,thisinh.NgaySinh);
    cout<<endl;
    return is;
}
ostream &operator<<(ostream &os,const thisinh &thisinh)
{
    cout<<"Thi sinh: "<<thisinh.TenThiSinh<<endl
        <<"Ma thi sinh: "<<thisinh.ID_thisinh<<endl
        <<"Dia chi: "<<thisinh.DiaChi<<endl
        <<"Ngay sinh: "<<thisinh.NgaySinh<<endl;
    return os;
}
/*int main()
{
    //List<cauhoi> listch;
    cauhoi ch;
    cin>>ch;
    //listch.addTail(ch);
    return 0;
}*/