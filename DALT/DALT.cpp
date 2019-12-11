// DALT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include "menu.h"
#include "ConnectDB.h"
using namespace std;
int main() {
	database db;
	db.init();
	db.execute(1);
	db.close();
	}
