#include <iostream>
#include "functions.h"
#include "CProduct.h"
#include "CSale.h"
#include "CItems_Sale.h"
#include "CProduct_Type.h"
#include "CSuppliers.h"

using namespace std;

void home(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nMenu:\n1-Type of Products | 2-Products | 3-Sale | 4-Suppliers | 5-Automatic Restocking "
            "| 6-Reception of Orders | 7-Inventory | 8-Sales Stats | 9-Exit" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :
        typeproductoptions(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '2' :
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '3' :
        initiatesale(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '4' :
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '5' :
        automatic_restocking(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '6' :
        orderreception(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '7' :
        inventory(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '8' :
        sales_stats(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '9' :
        exit(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"\nInvalid Option. Try again.";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
