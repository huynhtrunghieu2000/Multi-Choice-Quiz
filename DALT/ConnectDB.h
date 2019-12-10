#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdlib.h>
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 2048

class database {
	SQLHANDLE sqlConnHandle=NULL;
	SQLHANDLE sqlStmtHandle=NULL;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void init();
	void execute();
};