#pragma once
#include <iostream>
#include "3rd_a_page.h"
#include "3rd_page_buyers.h"


using namespace std;

void secondPage() {

	int num6;
	do {
		cout << " " << endl;
		cout << "***********************************" << endl;
		cout << " " << endl;
		cout << "-- 2nd page -- MENU" << endl;
		cout << " " << endl;

		cout << "(1) Buyers List " << endl;
		cout << "(2) Total Storage " << endl;
		cout << " " << endl;

		cout << "select a number : ";
		int num1;
		cin >> num1;

		switch (num1) {
		case 1:
			thirdBPage();
			break;
		case 2:
			thirdAPage();
			
			break;

		default:
			cout << "please enter valid number" << endl;
			break;
		}

		cout << " " << endl;
		cout << "Enter 1 to back to the menu." << endl;
		cout << "Enter other number to exit. " << endl;
		cout << " " << endl;
		cout << "Enter the number : " ;
		cin >> num6;


	} while (num6 ==1);
	

}