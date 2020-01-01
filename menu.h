#pragma once
#include <iostream>
#include "table.h"
#include <string.h>
#include "ConnectDB.h"
#include "list.h"
#include "DoTheTest.h"
using namespace std;
void menuGiaoVien(database& db);
void menuThiSinh(int _ID_ThiSinh, database& db);
void mainmenu(database &db);
void suaCauhoi(cauhoi &ch,database& db);
void suaThiSinh(thisinh& ts, database& db);
