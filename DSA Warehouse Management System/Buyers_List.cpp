#include "Buyers_List.h"

using namespace std;

Buyers_Linked_List buyer_list;

void print_buyer_name() {

    Node_Buyer* current = buyer_list.getHead();
    while (current != NULL) {
        cout << " Buyer ID : " << current->buyerID << "   Buyer Name : " << current->buyerName   << endl;
        current = current->next;
    }
}