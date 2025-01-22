#pragma once
#include <iostream>
#include "item.h"
//#include "item_issuing.h"
#include "check_buyers_stock.h"

using namespace std;

void buyerInfo(int id) { //id= num2 , given id in 3rd pg b
	
	cout << " " << endl;
	cout << "***********************************" << endl;
	cout << " " << endl;
	cout << "-- 4th page -- BUYER 1 " << endl;
	cout << " " << endl;

	cout << "(1) Item Receiving " << endl;
	cout << "(2) Item Issuing " << endl;
	cout << "(3) Check Buyer Stock " << endl;
	cout << " " << endl;

	cout << "select a number : ";
	int num3;
	cin >> num3;

	switch (num3) {
	case 1:
		cout << " " << endl;
		cout << "***********************************" << endl;
		itemReceiving(id);
		break;

	case 2:
		cout << " " << endl;
		cout << "***********************************" << endl;
		itemIssuing(id);
		break;

	case 3:
		cout << " " << endl;
		cout << "***********************************" << endl;
		check_buyers_stock(id);
		break;

	default:
		cout << " " << endl;
		cout << "***********************************" << endl;
		cout << "please enter valid number" << endl;
		break;
	}


}
