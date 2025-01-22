#pragma once
#include <iostream>
#include "second_page.h"
#include "3rd_page_buyers.h"
#include "item.h"

using namespace std;

int num4 = 0;
double totalSpace = 10000; //total space

void thirdAPage() {
	cout << " " << endl;
	cout << "***********************************" << endl;
	cout << " " << endl;
	cout << "-- 3rd page -- STORAGE " << endl;
	cout << " " << endl;

	
	cout << "Total space of the warehouse : "<< totalSpace << " units "<< endl;

	I1.printSumOfSpace();

	//cout << "(1) Back" << endl;
	//cout << "select a number : ";
	//cin >> num4;

}

