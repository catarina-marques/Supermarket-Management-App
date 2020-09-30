#include <iostream>
#include "functions.h"
#include <limits>
#include <vector>
using namespace std;

void orderreception(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    cout << "Pending reception: " << endl;
    orderslist.show_order_pending();

    unsigned int order_id_search;
    cout << "Insert order ID: ";
    while(!(cin >> order_id_search) || !orderslist.id_exists(order_id_search) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or an order with that ID does not exist." << endl;
        cout << "Insert order ID: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    itemsorderslist.show_items_order(order_id_search);
    orderslist.show_order(order_id_search);

    cout << "Update status: " << endl;
    char confirmation = 0;
    cout << "\nConfirm reception?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y': {
        orderslist.updatestatus(order_id_search);
        vector<sItems_Order> itemsinorderList = itemsorderslist.getlistitems_order(order_id_search);
        productlist.updatestocko( itemsinorderList );
        cout << "\nReception status updated! Return to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case 'n' : case 'N':
        cout << "Reception status stays the same. Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        orderreception(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
