#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdlib.h>
#include "table.h"

#include <string>

class database {
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 2048
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void init();
	//void execute(int);
	void close();
	//Cau Hoi:
	cauhoi getCauHoi(int _ID_ch);
	void insertCauHoi(cauhoi &ch);
	void updateCauHoi(cauhoi& ch);
	void deleteCauHoi(int _ID_ch);
	void getIDch(int* pick);
	int demSoCau();


	//De
	void updateKetQua(double _KetQua, int _ID_de);
	int getIDDe();
	void insertDe(int _IDthisinh);

	//Thi
	void insertThi(thi &thi);

	//Thi Sinh
	int demThiSinh();
	void getIDts(int* pick);
	thisinh getThiSinh(int _ID_thisinh);
	void insertThiSinh(thisinh& ts);
	void updateThiSinh(thisinh& ts);
	void deleteThiSinh(thisinh& ts);

	void bangDiemGV();
	void bangDiemThiSinh(int ID_thisinh);
	

};