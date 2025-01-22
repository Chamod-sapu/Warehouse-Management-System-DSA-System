#pragma once
#include <iostream>
#include "buyer_info.h"
//#include "item_receiving.h"
#include "item_issuing.h"
#include "check_buyers_stock.h"
#include "Buyers_List.h"

using namespace std;


int num2;

void thirdBPage() {

	cout << " " << endl;
	cout << "***********************************" << endl;
	cout << " " << endl;
	cout << "-- 3rd page -- BUYERS LIST " << endl;
	cout << " " << endl;

	cout << "Select the buyer " << endl;
	cout << " " << endl;

	print_buyer_name();
	cout << " " << endl;

	cout << "*Please select the first buyer. " << endl;
	cout << "Enter Buyer ID number : " ;
	cin >> num2;

	buyerInfo(num2); //give buyer id
	


}