#pragma once
#include <iostream>

using namespace std;

void firstPage() {

	cout << "** Warehouse Management System **" << endl;
	cout << " " << endl;

	cout << "-- Login page --" << endl;
	cout << " " << endl;

	const int numUsers = 3;
	string givenUsernames[numUsers] = { "mayura", "sapumal" , "erandika" };
	string givenPasswords[numUsers] = { "1234", "5678" , "abcd" };

	for (int a = 1; a < 3; a++) {
		string username;
		string password;

		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
		

		bool correct = false;

		for (int i = 0; i < numUsers; ++i) {
			if (username == givenUsernames[i] && password == givenPasswords[i]) {
				cout << " " << endl;
				cout << "Login successful!" << endl;
				//next page
				correct = true;
				break; 
			}
		}

		if (!correct) {
			cout << " " << endl;
			cout << "Incorrect username or password. Try again." << endl;
			cout << " " << endl;
		}
		else {
			break; 
		}
	}
	
	cout << " " << endl;
	cout << "********************" << endl;
	
}

