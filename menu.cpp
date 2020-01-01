#include "menu.h"
void mainmenu(database& db) {
	system("cls");
	cout << endl
		<< " ------------------------------------------------------ " << endl
		<< "|                       DE TAI                         |" << endl
		<< "|  QUAN LY CAU HOI DE THI TRAC NGHIEM                  |" << endl
		<< "|  LOP 18TCTC-DT3                                      |" << endl
		<< "|  NHOM 18N15-DA-06                                    |" << endl
		<< "|  SINH VIEN THUC HIEN:    LE HUU LONG                 |" << endl
		<< "|                          HUYNH THAI NGHIA            |" << endl
		<< "|                          HUYNH TRUNG HIEU            |" << endl
		<< " ------------------------------------------------------ " << endl;
	cout << endl
		<< " =========================HOME========================= " << endl
		<< "|                                                      |" << endl
		<< "|  1. DANH CHO GIANG VIEN                              |" << endl
		<< "|  2. DANH CHO THI SINH                                |" << endl
		<< "|  3. THOAT CHUONG TRINH                               |" << endl
		<< "|                                                      |" << endl
		<< " ====================================================== " << endl;
	int option = 0;
	do
	{
		cout << "LUA CHON: ";
		cin >> option;
		if (option < 1 || option >3)cout << "NHAP LAI" << endl;
	} while (option < 1 || option>3);
	switch (option)
	{
	case 1:
		menuGiaoVien(db);
		break;
	case 2:
		int ID_thisinh;
		cout << "MOI NHAP ID THI SINH: ";
		cin >> ID_thisinh;
		menuThiSinh(ID_thisinh,db);
		break;
	case 3:
		exit(1);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void menuGiaoVien(database& db)
{
	system("cls");
	cauhoi ch;
	thisinh ts;
	//////////////////////////////////
	List<cauhoi> listch;
	int SoCau = db.demSoCau();
	int* pick = new int[SoCau];
	db.getIDch(pick);
	for (int i = 0; i < SoCau; i++)
	{
		cauhoi tmp;
		tmp = db.getCauHoi(pick[i]);
		listch.addTail(tmp);
	}
	/////////////////////////////////
	int count = 0;
	int choice = 0;
	int option = 0;
	cout << endl
		<< " =========================GIAO VIEN============================" << endl
		<< "|                                                              |" << endl
		<< "|             1.THEM CAU HOI                                   |" << endl
		<< "|             2.SUA CAU HOI                                    |" << endl
		<< "|             3.XOA CAU HOI                                    |" << endl
		<< "|             4.THEM THI SINH                                  |" << endl
		<< "|             5.XEM DU LIEU BAI LAM                            |" << endl
		<< "|             6.QUAY LAI                                       |" << endl
		<< "|                                                              |" << endl
		<< " ==============================================================" << endl;

	do
	{
		cout << "LUA CHON: ";
		cin >> option;
		if (option < 1 || option >6)cout << "NHAP LAI" << endl;
	} while (option < 1 || option>6);
	system("cls");
	switch (option)
	{
	case 1:
		cout << "MOI NHAP NOI DUNG CAU HOI: " << endl;
		ch.scan();
		db.insertCauHoi(ch);
		cout << endl;
		system("pause");
		menuGiaoVien(db);
		break;
	case 2:
		listch.current = listch.head;
		while (listch.current != NULL) {

			count++;
			cout <<"CAU "<< count << ": ";
			listch.current->data.print();
			listch.current = listch.current->next;
		}
		cout << endl<< "CHON CAU HOI CAN SUA: ";
		cin >> choice;
		listch.current = listch.head;
		for (int j = 1; j < choice; j++) {

			listch.current = listch.current->next;
			if (j == choice) break;
		}
		system("cls");
		suaCauhoi(listch.current->data,db);
		cout << endl; 
		system("pause");
		menuGiaoVien(db);
		break;
	case 3:
		count = 0;
		listch.current = listch.head;
		while (listch.current != NULL) {
			count++;
			cout <<"CAU " << count << ": ";
			listch.current->data.print();
			listch.current = listch.current->next;
		}
		cout <<endl<< "CHON CAU HOI CAN XOA: ";
		cin >> choice;
		db.deleteCauHoi(pick[choice]);
		cout << endl;
		system("pause");
		menuGiaoVien(db);
		break;
	case 4:
		ts.scan();
		db.insertThiSinh(ts);
		cout << endl;
		system("pause");
		menuGiaoVien(db);
		break;
	case 5:
		cout << "DU LIEU LAM BAI CUA CAC THI SINH:" << endl;
		cout << "TEN THI SINH" << "\t\t\t\t\t\tMA DE" << "\tDIEM" << endl;
		db.bangDiemGV();
		cout << endl;
		system("pause");
		menuGiaoVien(db);
		break;
	case 6:
		mainmenu(db);
		break;
	}
	delete[]pick;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void menuThiSinh(int _ID_ThiSinh, database& db)
{
	int SoTs = db.demThiSinh();
	int* IDthisinh=new int[SoTs];
	db.getIDts(IDthisinh);
	for (int i = 0; i < SoTs; i++) {
		if (_ID_ThiSinh == IDthisinh[i]) break;
		else if (_ID_ThiSinh != IDthisinh[i] && i == SoTs-1)
		{
			cout << "KHONG TON TAI THI SINH NAY TRONG DANH SACH" << endl
				<< "BAM PHIM BAT KY DE NHAP LAI..."<<endl;
			system("pause");
			mainmenu(db);
		}
	}
	system("cls");
	int option = 0;
	thisinh ts;
	cout << endl
		<< " =========================THI SINH=============================" << endl
		<< "|                                                              |" << endl
		<< "|             1.BAT DAU THI                                    |" << endl
		<< "|             2.XEM KET QUA                                    |" << endl
		<< "|             3.SUA THONG TIN CA NHAN                          |" << endl
		<< "|             4.QUAY LAI                                       |" << endl
		<< "|                                                              |" << endl
		<< " ==============================================================" << endl;
	do
	{
		cout << "LUA CHON: ";
		cin >> option;
		if (option < 1 || option >4)cout << "NHAP LAI" << endl;
	} while (option < 1 || option>4);
	system("cls");
	switch (option)
	{
	case 1:
		Thi(_ID_ThiSinh);
		menuThiSinh(_ID_ThiSinh, db);
		break;
	case 2:
		cout << "KET QUA THI CUA BAN" << endl;
		cout << "TEN THI SINH" << "\t\t\t\t\t\tMA DE" << "\tDIEM" << endl;
		db.bangDiemThiSinh(_ID_ThiSinh);
		cout <<endl;
		system("pause");
		menuThiSinh(_ID_ThiSinh, db);
		break;
	case 3:
		cout << "THONG TIN CUA BAN: " << endl;
		ts = db.getThiSinh(_ID_ThiSinh);
		ts.print();
		suaThiSinh(ts, db);
		cout << endl;
		menuThiSinh(_ID_ThiSinh, db);
		break;
	case 4:
		mainmenu(db);
		break;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void suaCauhoi(cauhoi& ch, database& db)
{
	cout << endl
		<< " =========================SUA CAU HOI========================== " << endl
		<< "|                                                              |" << endl
		<< "|             1.SUA NOI DUNG CAU HOI                           |" << endl
		<< "|             2.SUA DAP AN                                     |" << endl
		<< "|             3.SUA TOAN BO CAU HOI                            |" << endl
		<< "|                                                              |" << endl
		<< " ============================================================== " << endl;
	ch.print();
	int option = 0;
	do {
		cout << "LUA CHON: ";
		cin >> option;
		if (option < 1 || option >3) cout << "NHAP LAI" << endl;
	} while (option < 1 || option >3);
	system("cls");
	switch (option) {
	case 1:
		ch.scancauhoi();
		break;
	case 2:
		ch.scandapan();
		break;
	case 3:
		ch.scan();
		break;
	}
	db.updateCauHoi(ch);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void suaThiSinh(thisinh& ts, database& db)
{
	cout << endl
		<< " ====================SUA THONG TIN CA NHAN===================== " << endl
		<< "|                                                              |" << endl
		<< "|             1.SUA TEN                                        |" << endl
		<< "|             2.SUA DIA CHI                                    |" << endl
		<< "|             3.QUAY LAI                                       |" << endl
		<< "|                                                              |" << endl
		<< " ============================================================== " << endl;
	int choice = 0;
	do {
		cout << "LUA CHON: ";
		cin >> choice;
		if (choice < 1 || choice >3) cout << "NHAP LAI" << endl;
	} while (choice < 1 || choice >3);
	system("cls");
	cin.ignore();
	switch (choice) {
	case 1:
		ts.scanname();
		db.updateThiSinh(ts);
		cout << endl;
		system("pause");
		break;
	case 2:
		ts.scanaddress();
		db.updateThiSinh(ts);
		cout << endl;
		system("pause");
		break;
	case 3:
		break;
	}
}