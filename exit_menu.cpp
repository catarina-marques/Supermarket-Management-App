#include <iostream>
#include "functions.h"
#include <cstring>
using namespace std;

int exit(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "Do you want to exit?(Y/N)" << endl;
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case 'y' : case 'Y':
        typeslist.loadfromlist(typeslist);
        return 0;
        break;
    case 'n' : case 'N':
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"!Invalid Option. Try again.\n";
        exit(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
