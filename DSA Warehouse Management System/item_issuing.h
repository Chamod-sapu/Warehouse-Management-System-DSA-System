#pragma once
#include <iostream>
#include <fstream>

using namespace std;



class Node_issued_Item
{
public:
    string Date;
    string Supplier;
    string Item_Code;
    string Item_Name;
    string Style;
    string UOM;
    double Quantity;
    double Space;
    string Location;
    Node_issued_Item* next;

    Node_issued_Item() {
        Date = -1;
        Supplier = -1;
        Item_Code = -1;
        Item_Name = -1;
        Style = -1;
        UOM = -1;
        Quantity = -1;
        Space = -1;
        Location = -1;
        next = NULL;
    }

    Node_issued_Item(string date, string sup, string code, string nam, string style, string uom, double qty, double space, string loc) {

        Date = date;
        Supplier = sup;
        Item_Code = code;
        Item_Name = nam;
        Style = style;
        UOM = uom;
        Quantity = qty;
        Space = space;
        Location = loc;
        next = NULL;
    }
};

//issued item linked list
class Item_Issuing
{
private:
    Node_issued_Item* head;
    Node_issued_Item* tail;
    int size;
public:
    Item_Issuing() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //enter data to linked list
    void ItemIssue(string date, string sup, string code, string nam, string style, string uom, double qty, double space, string loc) {
        Node_issued_Item* temp = new Node_issued_Item(date, sup, code, nam, style, uom, qty, space, loc);
        if (head == NULL) {

            head = temp;
            tail = temp;
            size++;
        }
        else {
            temp->next = head;
            head = temp;
            size++;
        }
    }
    //enter data to file
    void ItemIssueToFile() {
        ofstream file("item_Issue_data.csv");

        if (!file) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        Node_issued_Item* current = head;

        while (current != NULL) {
            file << current->Date << " "
                << current->Supplier << " "
                << current->Item_Code << " "
                << current->Item_Name << " "
                << current->Style << " "
                << current->UOM << " "
                << current->Quantity << " "
                << current->Space << " "
                << current->Location << endl;
            current = current->next;
        }

        file.close();
    }
    //read data from the file
    void readFromFile() {
        ifstream file("item_Issue_data.csv");

        if (!file) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        string dt, splr, itm_cd, it_nm, st, um, lctn;
        double spc, qunty;

        while (file >> dt >> splr >> itm_cd >> it_nm >> st >> um >> spc >> qunty >> lctn) {
            Node_issued_Item* temp = new Node_issued_Item(dt, splr, itm_cd, it_nm, st, um, spc, qunty, lctn);
            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        file.close();
    }

};
