//include the below additional libraries
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
	cout << "Loading...";
	cout << "\n";

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
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	default:
		break;
	}

	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();

}

void database::execute(int question) {
	//output
	
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;
	cout << "\n";
	cout << "Loading...";
	cout << "\n";
	switch (question)
	{
	case 1:
		//if there is a problem executing the query then exit application
		//else display query result
		if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM cauhoi", SQL_NTS)) {
			cout << "Error querying SQL Server";
			cout << "\n";
			close();
		}
		else {
			//Lay tat ca du lieu trong cauhoi
			char NoiDung[500];
			char DapAn1[100];
			char DapAn2[100];
			char DapAn3[100];
			char DapAn4[100];
			while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
			{
				SQLGetData(sqlStmtHandle, 2, SQL_C_CHAR, NoiDung, 500, NULL);
				SQLGetData(sqlStmtHandle, 3, SQL_C_CHAR, DapAn1, 50, NULL);
				SQLGetData(sqlStmtHandle, 4, SQL_C_CHAR, DapAn2, 50, NULL);
				SQLGetData(sqlStmtHandle, 5, SQL_C_CHAR, DapAn3, 50, NULL);
				SQLGetData(sqlStmtHandle, 6, SQL_C_CHAR, DapAn4, 50, NULL);

				cout << NoiDung << endl <<"1."<< DapAn1 << endl<< "2." << DapAn2<<endl<< "3." << DapAn3<<endl<< "4." << DapAn4<<endl;

			}
			break;
	case 2: //Them du lieu vao database 
		if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"insert into RUT values (2, '11', 30)", SQL_NTS)) {
			cout << "Error querying SQL Server";
			cout << "\n";
			close();
		}
		break;
		}
	}
}
void database::close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

	//pause the console window - exit when key is pressed
	cout << "\nPress any key to exit...";
	system("pause");
}