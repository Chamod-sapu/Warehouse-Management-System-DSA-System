#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "buyer_info.h"
#include "3rd_a_page.h"

using namespace std;

//node
class Node_Item
{
public:
    string rDate;
    string iDate;
    string Supplier;
    int Item_Code;
    string Item_Name;//***
    string Style;//***
    string UOM;
    int Quantity; //***
    double Space;//***
    string Location;//***
    Node_Item* next;

    Node_Item() { //default constructor
        rDate = -1;
        iDate = -1;
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

    Node_Item(string rdate, string idate, string sup, int code, string nam, string style, string uom, double qty, double space, string loc) {

        rDate = rdate;
        iDate = idate;
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

//received items linked list
class Item_class {
private:
    Node_Item* head;
    Node_Item* tail;
    int size;
public:
    Item_class() {
        head = NULL;
        tail = NULL;
        size = 0;
        this->ItemReceive("05/12/2023","Not yet" ,"Supplier 1", 246, "Tea", "Green Tea", "UOM1", 50, 200 , "L1");
        this->ItemReceive("05/12/2023", "Not yet", "Supplier 2", 135, "Milk Powder", "Non Fat", "UOM2", 70, 150, "L2");
    }

    // Function to enter data to linked list
    void ItemReceive(string rdate, string idate, string sup, int code, string nam, string style, string uom, double qty, double space, string loc) {

        Node_Item* temp = new  Node_Item(rdate, idate, sup, code, nam, style, uom, qty, space, loc);
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

    bool isItemAvailable(int itemCodeToCheck) {
        const Node_Item* current = head;

        while (current != nullptr) {
            if (current->Item_Code == itemCodeToCheck) {
                // Item with the specified code is found
                return true;
            }
            current = current->next;
        }

        // Item with the specified code is not found
        return false;
    }

    void printItemProperty(int itemCodeToPrint, const string& property) {
        const Node_Item* current = head;

        while (current != nullptr) {
            if (current->Item_Code == itemCodeToPrint) {
                // Item with the specified code is found
                // Print the specified property
                if (property == "rDate") {
                    cout << "Recive Date: " << current->rDate << endl;
                }
                else if (property == "iDate") {
                    cout << "Issue Date: " << current->iDate << endl;
                }
                else if (property == "Supplier") {
                    cout << "Supplier: " << current->Supplier << endl;
                }
                else if (property == "Item_Name") {
                    cout << "Item Name: " << current->Item_Name << endl;
                }
                else if (property == "Style") {
                    cout << "Style: " << current->Style << endl;
                }
                else if (property == "UOM") {
                    cout << "UOM: " << current->UOM << endl;
                }
                else if (property == "Quantity") {
                    cout << "Quantity: " << current->Quantity << endl;
                }
                else if (property == "Space") {
                    cout << "Space: " << current->Space << endl;
                }
                else if (property == "Location") {
                    cout << "Location: " << current->Location << endl;
                }
                else {
                    cout << "Error: Invalid property specified." << endl;
                }
                return;
            }
            current = current->next;
        }

        // Item with the specified code is not found
        cout << "Error: Item not available." << endl;
    }
    // Function to enter data to file
    void ItemReceiveToFile() {
        ofstream file("D:/item_Recieve_data.csv");

        if (!file) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        Node_Item* current = head;

        while (current != NULL) {
            file << current->rDate << "," 
                << current->iDate << ","
                << current->Supplier << ","
                << current->Item_Code << ","
                << current->Item_Name << ","
                << current->Style << ","
                << current->UOM << ","
                << current->Quantity << ","
                << current->Space << ","
                << current->Location <<"," << endl;
            current = current->next;
        }

        file.close();
    }
    // Function to read data from the file
/*
    void readFromFile() {
        ifstream file("item_Recieve_data.csv");

        if (!file) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        string dt, splr, itm_cd, it_nm, st, um, lctn;
        double spc, qunty;

        while (file >> dt >> splr >> itm_cd >> it_nm >> st >> um >> spc >> qunty >> lctn) {
            Node_Recieve_Item* temp = new  Node_Recieve_Item(dt, splr, itm_cd, it_nm, st, um, spc, qunty, lctn);
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
*/
    /*void readCsvFileToNodes(const string& filename) {
        ifstream file(filename);

        if (!file) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        string line;
        getline(file, line); // Read and discard the header line if there is one

        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            Node_Item* newNode = new Node_Item();

            // Assuming the order of columns in the CSV matches the structure of your node
            getline(ss, newNode->Date, ',');
            getline(ss, newNode->Supplier, ',');
            getline(ss, newNode->Item_Code, ',');
            getline(ss, newNode->Item_Name, ',');
            getline(ss, newNode->Style, ',');
            getline(ss, newNode->UOM, ',');
            ss >> newNode->Quantity;
            ss.ignore();
            ss >> newNode->Space;
            ss.ignore();
            getline(ss, newNode->Location, ',');

            newNode->next = head;
            head = newNode;
        }

        file.close();
    }*/

    void printAllNodes() {
        const Node_Item* current = head;

        while (current != nullptr) {
            cout << "rDate: " << current->rDate << endl
                << "iDate: " << current->iDate << endl
                << "Supplier: " << current->Supplier << endl
                << "Item Code: " << current->Item_Code << endl
                << "Item Name: " << current->Item_Name << endl
                << "Style: " << current->Style << endl
                << "UOM: " << current->UOM << endl
                << "Quantity: " << current->Quantity << endl
                << "Space: " << current->Space << endl
                << "Location: " << current->Location << endl
                << "-------------------------" << endl;

            current = current->next;
        }
    }

    // Function to change a specific property of the item with the given item code
    void changeItemProperty(int itemCodeToChange, const string& property, const string& newValue) {
        Node_Item* current = head;

        while (current != nullptr) {
            if (current->Item_Code == itemCodeToChange) {
                // Item with the specified code is found
                // Change the specified property
                if (property == "rDate") {
                    current->rDate = newValue;
                }
                else if (property == "iDate") {
                    current->iDate = newValue;
                }
                else if (property == "Supplier") {
                    current->Supplier = newValue;
                }
                else if (property == "Item_Name") {
                    current->Item_Name = newValue;
                }
                else if (property == "Style") {
                    current->Style = newValue;
                }
                else if (property == "UOM") {
                    current->UOM = newValue;
                }
                else if (property == "Quantity") {
                    current->Quantity = stoi(newValue);
                }
                else if (property == "Space") {
                    current->Space = stod(newValue);
                }
                else if (property == "Location") {
                    current->Location = newValue;
                }
                else {
                    cout << "Error: Invalid property specified." << endl;
                    return;
                }
              //  cout << "Updated successfully." << endl;
                return;
            }
            
            current = current->next;
        }

        cout << "Error: Item not available." << endl;
    }

    string getItemProperty(int itemCodeToGet, const string& property) {
        const Node_Item* current = head;

        while (current != nullptr) {
            if (current->Item_Code == itemCodeToGet) {
                // Item with the specified code is found
                // Return the specified property as a string
                if (property == "rDate") {
                    return current->rDate;
                }
                if (property == "iDate") {
                    return current->iDate;
                }
                else if (property == "Supplier") {
                    return current->Supplier;
                }
                else if (property == "Item_Name") {
                    return current->Item_Name;
                }
                else if (property == "Style") {
                    return current->Style;
                }
                else if (property == "UOM") {
                    return current->UOM;
                }
                else if (property == "Quantity") {
                    return to_string(current->Quantity);
                }
                else if (property == "Space") {
                    return to_string(current->Space);
                }
                else if (property == "Location") {
                    return current->Location;
                }
                else {
                    return "Error: Invalid property specified.";
                }
            }
            current = current->next;
        }

        // Item with the specified code is not found
        return "Error: Item not available.";
    }


    // sum of used space
    void printSumOfSpace() {
        const Node_Item* current = head;
        double sum = 0.0;

        while (current != NULL) {
         
            try {
                sum += current->Space;  // Convert "Space" to double and add to sum
            }
            catch (const invalid_argument& e) {
                cerr << "Error: Invalid value for Space in node with Item Code " << current->Item_Code << endl;
            }
            catch (const out_of_range& e) {
                cerr << "Error: Out of range value for Space in node with Item Code " << current->Item_Code << endl;
            }
            current = current->next;
        } 
        cout << "Total used space : " << sum << " units" << endl;
        cout << "Total free space : " << 10000-sum <<" units" << endl;
    }
};

 

//int a; 

Item_class I1;

void itemReceiving(int id) {
   //  a = id;

     string Date;
     string Supplier;
     int Item_Code;
     string Item_Name;
     string Style;
     string UOM;
     int Quantity;
     double Space;
     string Location;


     cout << "Enter Item Details" << endl;;
     cout << "Date:";
     cin >> Date;
     cout << "Supplier:";
     cin >> Supplier;
     cout << "Item_Code:";
     cin >> Item_Code;
     cout << "Item Name:";
     cin >> Item_Name;
     cout << "Style:";
     cin >> Style;
     cout << "Unit of measurement:";
     cin >> UOM;
     cout << "Quantity:";
     cin >> Quantity;
     cout << "Space:";
     cin >> Space;
     cout << "Location:";
     cin >> Location;


     //I1.readCsvFileToNodes("D:/item_Recieve_data.csv");
     //I1.ItemReceive(Date, Supplier, Item_Code, Item_Name, Style, UOM, Quantity, Space, Location);
     
     cout << " " << endl;
     cout << "***********************************" << endl;
     I1.ItemReceive(Date,"Not Yet", Supplier, Item_Code, Item_Name, Style, UOM, Quantity, Space, Location);

     cout << "TO display all received orders enter 1" << endl;
     cout << "Go to back enter any number" << endl;
     cout << "Enter number : ";
     int num8;
     cin >> num8;

     if (num8 == 1) {
         cout << " " << endl;
         cout << "***********************************" << endl;
         I1.printAllNodes();
     }
     //I1.ItemReceiveToFile();
     //cout << "***** data added to the file";
     //cout << " " << endl;
     
}

int itemCodeToCheck;
bool itemAvailable = false;

void itemIssuing(int id) {

 //   int itemCodeToCheck
 //   bool itemAvailable = false;

    do {
        cout << "Enter the item code to check: ";
        cin >> itemCodeToCheck;

        itemAvailable = I1.isItemAvailable(itemCodeToCheck);

        if (!itemAvailable) {
            cout << "Error: Item not available. Please enter a valid item code." << endl;
        }

    } while (!itemAvailable);

    cout << " " << endl;
    cout << "Item is available." << endl;
    cout << " " << endl;


    I1.printItemProperty(itemCodeToCheck, "Item_Name");
    I1.printItemProperty(itemCodeToCheck, "Style"); 
    I1.printItemProperty(itemCodeToCheck, "Quantity");
    I1.printItemProperty(itemCodeToCheck, "Space"); //check location

    cout << " " << endl;
    cout << "Enter details" << endl;

    string issue_date;
    int issue_quantity;
    double issue_space;


    cout << "\nItem issuing date : " ;
    cin >> issue_date;
    I1.changeItemProperty(itemCodeToCheck, "iDate", issue_date);

    cout << "\nIssuing quantity  : " ;
    cin >> issue_quantity;
    int availableQuantity = stoi(I1.getItemProperty(itemCodeToCheck, "Quantity"));
    int x = availableQuantity - issue_quantity;
    I1.changeItemProperty(itemCodeToCheck, "Quantity", to_string(x));

    cout << "\nIssuing space : " ;
    cin >> issue_space;
    int availableSpace = stoi(I1.getItemProperty(itemCodeToCheck, "Space"));
    int y = availableSpace - issue_space;
    I1.changeItemProperty(itemCodeToCheck, "Space", to_string(y));

    

}