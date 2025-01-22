#pragma once
#include <iostream>

using namespace std;

void print_buyer_name();

// define node 
class Node_Buyer {

public:
    string buyerName;
    int buyerID;
    double buyerStorage;
    Node_Buyer* next;

    /*
  Node_Buyer() {
      buyerName ="z";
        buyerID = -1;
        buyerStorage =-1;
        next = NULL;
    }
*/
    Node_Buyer(string name, int id, double storage) {
        buyerName = name;
        buyerID = id;
        buyerStorage = storage;
        next = NULL;
    }

};

class Buyers_Linked_List {
private:
    Node_Buyer* head;
    Node_Buyer* tail;
    int size;

public:


    // Constructor
    Buyers_Linked_List() {
        head = NULL;
        tail = NULL;
        size = 0;

        this->insertFirst("Hemas", 3, 150);
        this->insertFirst("Keels", 2, 200.5);
        this->insertFirst("Cargills", 1, 100.5);
    }

    // Destructor (to free memory when the list is destroyed)

    ~Buyers_Linked_List() {
        Node_Buyer* current = head;
        while (current != NULL) {
            Node_Buyer* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }

    Node_Buyer* getHead()
    {
        return head;
    }

    // insert
    void insertFirst(string name, int id, double storage) {
        Node_Buyer* temp = new Node_Buyer(name, id, storage);
        if (head == NULL) {
            //linked list is empty
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
    // delete
    void deleteFirst() {
        if (head == NULL) {
            cout << "There is no Buyer yet.\ Please create a buyer account." << endl;
        }
        else {
            Node_Buyer* temp = head;
            if (size == 1) {
                head = NULL;
                tail = NULL;
                delete temp;
                size = 0;
            }
            else {
                head = head->next;
                delete temp;
                size--;
            }
        }
    }
    void deleteLast() {
        if (tail == NULL)
            cout << "There is no Buyer yet.\ Please create a buyer account." << endl;
        else {
            Node_Buyer* temp = tail;
            if (size == 1) {
                head == NULL;
                tail = NULL;
                delete temp;
                size = 0;
            }
            else {
                Node_Buyer* current = head;
                for (int i = 0; i < size - 2; i++) {
                    current = current->next;
                }
                tail = current;
                tail->next = NULL;
                size--;
            }
        }
    }
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid Buyer." << endl;
        }
        else {
            Node_Buyer* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node_Buyer* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }


    // print
    void print() {
        Node_Buyer* current = head;
        while (current != NULL) {
            cout << "Details of buyer: " << current->buyerName << ", " << current->buyerID << ", " << current->buyerStorage << std::endl;
            current = current->next;
        }
    }

};


