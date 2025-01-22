#include <iostream>
#include "Buyers_List.h"
#include "login_page.h"
#include "second_page.h"
#include "3rd_a_page.h"
#include "3rd_page_buyers.h"
#include "buyer_info.h"

using namespace std;



void back(int num5) {
    if (num5 == 1) {
        secondPage();
    }
    else if(num5==0){
        cout << " " << endl;
        cout << "***  program ended ***" << endl;
    }
    else {

    }
}



int main()
{
    //buyerList();
    firstPage();
    secondPage();
   // back(num4);
    

    /*
    cout << "********************" << endl;

    // linked list object
    Buyers_Linked_List buyer_list;


    buyer_list.insertFirst("Cargills", 1 , 100.5);
    buyer_list.insertFirst("Keels", 2 , 200.5);
    buyer_list.insertFirst("Hemas", 3 , 150);

    // Display the elements in the linked list
    buyer_list.print();

    cout << "********************" << endl;

    buyer_list.deleteFirst();
    buyer_list.print();

    cout << "********************" << endl;

    Buyers_Linked_List* buyer_list2 = new Buyers_Linked_List;

    buyer_list2->deleteLast();
*/

    return 0;
}
