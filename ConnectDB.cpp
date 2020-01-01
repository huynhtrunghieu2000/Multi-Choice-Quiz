#include "ConnectDB.h"
//use the std namespace
using namespace std;
void database::init() {
	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();

	//output
	cout << "DANG KET NOI..."<<endl;

	//connect to SQL Server	
	//I am using a trusted connection and port 14808
	//it does not matter if you are using default or named instance
	//just make sure you define the server name and the port
	//You have the option to use a username/password instead of a trusted connection
	//but is more secure to use a trusted connection
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;UID=username;PWD=password;",
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=ADMIN;DATABASE=Multi-Choice-Quiz;Trusted=true;UID=sa;PWD=123",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "DA KET NOI"<<endl;
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "DA KET NOI"<<endl;
		break;

	case SQL_INVALID_HANDLE:
		cout << "KHONG THE KET NOI TOI SQL SERVER" << endl;
		close();
		break;

	case SQL_ERROR:
		cout << "KHONG THE KET NOI TOI SQL SERVER" << endl;
		close();
		break;

	default:
		break;
	}

	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();

}

void database::close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

	//pause the console window - exit when key is pressed
	cout <<endl<<"AN PHIM BAT KI...";
	system("pause");
}
/////////////////////////////////////QUERY CAU HOI/////////////////////////////////////////////////////
cauhoi database::getCauHoi(int _ID_ch) {//ok
	cauhoi ch;

	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select * from cauhoi where ID_ch = ?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT,SQL_C_ULONG , SQL_INTEGER, 20, 0, &_ID_ch, 0, 0);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout<<endl << "LOI";

		int ID_ch=0;
		char NoiDung[255];
		char DapAn1[255];
		char DapAn2[255];
		char DapAn3[255];
		char DapAn4[255];
		int DapAnDung=0;
		bool available=0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &ID_ch, 20, NULL);
			SQLGetData(sqlStmtHandle, 2, SQL_C_CHAR, NoiDung, 255, NULL);
			SQLGetData(sqlStmtHandle, 3, SQL_C_CHAR, DapAn1, 255, NULL);
			SQLGetData(sqlStmtHandle, 4, SQL_C_CHAR, DapAn2, 255, NULL);
			SQLGetData(sqlStmtHandle, 5, SQL_C_CHAR, DapAn3, 255, NULL);
			SQLGetData(sqlStmtHandle, 6, SQL_C_CHAR, DapAn4, 255, NULL);
			SQLGetData(sqlStmtHandle, 7, SQL_C_ULONG, &DapAnDung, 1, NULL);
			SQLGetData(sqlStmtHandle, 7, SQL_C_BIT, &available, 1, NULL);

		}
		cauhoi tmp(ID_ch, NoiDung, DapAn1, DapAn2, DapAn3, DapAn4,DapAnDung,available);
		ch=tmp;
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
	return ch;
}
int database::demSoCau()//ok
{
	int SoCau=0;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select * from cauhoi where Available = '1'", SQL_NTS);
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SoCau++;
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
	return SoCau;
}
void database::insertCauHoi(cauhoi &ch) { //OK
	bool available =true;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into cauhoi([NoiDung],[DapAn1],[DapAn2],[DapAn3],[DapAn4],[DapAnDung],[Available]) values(?,?,?,?,?,?,?)", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.NoiDung, 0, 0);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn1, 0, 0);
	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn2, 0, 0);
	SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn3, 0, 0);
	SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn4, 0, 0);
	SQLBindParameter(sqlStmtHandle, 6, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 1, 0, &ch.DapAnDung, 0, 0);
	SQLBindParameter(sqlStmtHandle, 7, SQL_PARAM_INPUT, SQL_C_BIT, SQL_BIT, 1, 0, &available, 0, 0);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl <<"KHONG THE THEM";
	else cout << endl << "DA THEM";
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
void database::getIDch(int* pick)//ok
{
	int i = 0, id;
	bool available;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select ID_ch, Available from cauhoi", SQL_NTS);
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &id, 20, NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_BIT, &available, 1, NULL);
		if (available == 1) {
			pick[i] = id;
			i++;
		}
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}

void database::updateCauHoi(cauhoi &ch){//OK
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update cauhoi set NoiDung = ?,DapAn1=?, DapAn2=?,DapAn3=?,DapAn4=?,DapAnDung=? where ID_ch = ? ", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.NoiDung, 0, 0);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn1, 0, 0);
	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn2, 0, 0);
	SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn3, 0, 0);
	SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ch.DapAn4, 0, 0);
	SQLBindParameter(sqlStmtHandle, 6, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 1, 0, &ch.DapAnDung, 0, 0);
	SQLBindParameter(sqlStmtHandle, 7, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &ch.ID_ch, 0, 0);
	SQLExecute(sqlStmtHandle);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "KHONG THE CAP NHAT";
	else cout << endl << "DA CAP NHAT";
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
void database::deleteCauHoi(int _ID_ch)
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update cauhoi set Available ='0' where ID_ch=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &_ID_ch, 0, 0);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "KHONG THE XOA, KIEM TRA LAI ID_ch";
	else cout << endl << "DA XOA";
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
///////////////////////////////////////////////////QUERY DE/////////////////////////////////////////////////////////////////
void database::insertDe(int _IDthisinh) {//OK
	cout << ".";
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into de(ID_thisinh,SoCau) values(?,20)", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &_IDthisinh, 0, 0);
	SQLExecute(sqlStmtHandle);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);

}
int database::getIDDe() {//OK
	int id=0;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"SELECT TOP 1 ID_de FROM de ORDER BY ID_de DESC ", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &id, 0, 0);
	SQLExecute(sqlStmtHandle);
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &id, 20, NULL);
		}
	
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
	return id;
}
void database::updateKetQua(double _KetQua,int _ID_de)//OK
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update de set KetQua = ? where ID_de = ? ", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DOUBLE, SQL_DOUBLE, 20, 0, &_KetQua, 0, 0);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &_ID_de, 0, 0);
	SQLExecute(sqlStmtHandle);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}

///////////////////////////////////////////////////QUERY THI////////////////////////////////////////////////////////////////
void database::insertThi(thi &thi) {//OK
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into thi values(?,?,?,?)", SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &thi.ID_de, 0, 0);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &thi.ID_ch, 0, 0);
		SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 1, 0, &thi.LuaChon, 0, 0);
		SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_BIT, SQL_BIT, 1, 0, &thi.DungSai, 0, 0);
		SQLExecute(sqlStmtHandle);
		SQLFreeStmt(
			sqlStmtHandle,
			SQL_UNBIND);
		SQLFreeStmt(
			sqlStmtHandle,
			SQL_CLOSE);
		SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}

///////////////////////////////////////////////////QUERY THI SINH///////////////////////////////////////////////////////////
int database::demThiSinh()//ok
{
	int SoThiSinh = 0;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select * from thisinh ", SQL_NTS);
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SoThiSinh++;
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
	return SoThiSinh;
}
void database::getIDts(int* pick)//ok
{
	int i = 0, id;
	bool available;
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select ID_thisinh from thisinh", SQL_NTS);
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &id, 20, NULL);
			pick[i] = id;
			i++;
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
thisinh database::getThiSinh(int _ID_thisinh)
{
	thisinh ts;
	int ID_ts = 0;
	char TenThiSinh[255];
	char DiaChi[255];
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select * from thisinh where ID_thisinh = ?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 20, 0, &_ID_thisinh, 0, 0);

	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "LOI";
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &ID_ts, 20, NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_CHAR, TenThiSinh, 50, NULL);
		SQLGetData(sqlStmtHandle, 3, SQL_C_CHAR, DiaChi, 255, NULL);
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
	thisinh tmp(ID_ts,TenThiSinh,DiaChi);
	ts = tmp;
	return ts;
}
void database::insertThiSinh(thisinh &ts)
{
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into thisinh values(?,?)", SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, ts.TenThiSinh, 0, 0);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ts.DiaChi, 0, 0);
		if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout<<endl << "KHONG THE THEM THI SINH";
		else cout <<endl<< "DA THEM";
		SQLFreeStmt(
			sqlStmtHandle,
			SQL_UNBIND);
		SQLFreeStmt(
			sqlStmtHandle,
			SQL_CLOSE);
		SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
void database::updateThiSinh(thisinh& ts)
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update thisinh set TenThiSinh = ?, DiaChi = ? where ID_thisinh = ? ", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, ts.TenThiSinh, 0, 0);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 255, 0, ts.DiaChi, 0, 0);
	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &ts.ID_thisinh, 0, 0);

	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "KHONG THE CAP NHAT";
	else cout << endl << "DA CAP NHAT";
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
void database::deleteThiSinh(thisinh& ts)
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"DELETE FROM thisinh WHERE ID_thisinh= ?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 20, 0, &ts.ID_thisinh, 0, 0);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout <<endl<< "KHONG THE THUC HIEN, KIEM TRA LAI ID_thisinh";
	else cout << endl << "DA XOA";
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
/////////////////////////////////////////////////XEM DIEM THI////////////////////////////////////////////
void database::bangDiemGV()
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select TenThiSinh,ID_de, KetQua from de join thisinh on de.ID_thisinh=thisinh.ID_thisinh", SQL_NTS);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "LOI";
	char TenThiSinh[255];
	int ID_de = 0;
	double Ketqua=0.0;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_CHAR, TenThiSinh, 255, NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_ULONG, &ID_de, 255, NULL);
		SQLGetData(sqlStmtHandle, 3, SQL_C_DOUBLE, &Ketqua, 255, NULL);
		cout << TenThiSinh << "\t" << ID_de << "\t" << Ketqua<<endl;
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}
void database::bangDiemThiSinh(int ID_thisinh)
{
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select TenThiSinh,ID_de, KetQua from de join thisinh on de.ID_thisinh = thisinh.ID_thisinh where thisinh.ID_thisinh = ?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 7, 0, &ID_thisinh, 0, 0);
	if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) cout << endl << "LOI";
	char TenThiSinh[255];
	int ID_de = 0;
	double Ketqua=0.0;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_CHAR, TenThiSinh, 255, NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_ULONG, &ID_de, 255, NULL);
		SQLGetData(sqlStmtHandle, 3, SQL_C_DOUBLE, &Ketqua, 255, NULL);
		cout << TenThiSinh << "\t" << ID_de << "\t" << Ketqua<<endl;
	}
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_UNBIND);
	SQLFreeStmt(
		sqlStmtHandle,
		SQL_CLOSE);
	SQLFreeStmt(sqlStmtHandle, SQL_RESET_PARAMS);
}



