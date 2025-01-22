#pragma once
#include <iostream>
#include "item.h"

using namespace std;

void check_buyers_stock(int id) {

    do {
        cout << "Enter the item code to check: ";
        cin >> itemCodeToCheck;

        itemAvailable = I1.isItemAvailable(itemCodeToCheck);

        if (!itemAvailable) {
            cout << "Error: Item not available. Please enter a valid item code." << endl;
        }

    } while (!itemAvailable);

    cout << "Item is available. Continue with further processing." << endl;
    I1.printItemProperty(itemCodeToCheck, "Item_Name");
    I1.printItemProperty(itemCodeToCheck, "Style");
    I1.printItemProperty(itemCodeToCheck, "Quantity");
    I1.printItemProperty(itemCodeToCheck, "Space");
}