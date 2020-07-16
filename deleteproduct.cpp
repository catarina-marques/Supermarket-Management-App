#include <iostream>
#include "functions.h"
#include "CProduct_Type.h"
#include "CProduct.h"
#include "CSale.h"
#include "CItems_Sale.h"
#include "CSuppliers.h"
#include "CSuppliers_Products.h"
#include "COrders.h"
#include "CItems_Order.h"
#include <string>
#include "string.h"
#include <limits>
using namespace std;

void deleteproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int idcodesearch;
    cout << "Insert the code of the product to delete." << endl;
    while(!(cin >> idcodesearch) || !productlist.id_exists(idcodesearch)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or product ID does not exist." << endl;
        cout << "Introduce the product ID you wish to buy: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    int product_index;
    product_index = productlist.seek_index(idcodesearch);

    if(product_index != 0){
        char confirmation = 0;
        cout << "\nAre you sure you want to delete this product?(Y/N)\n" << endl;
        productlist.showsproduct(product_index);
        scanf(" %c", &confirmation);
        while ((getchar()) != '\n');
        switch(confirmation){
            case 'y' : case 'Y':
                productlist.deleteproduct(product_index);
                cout << "Product deleted." << endl;
                home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
                break;
            case 'n' : case 'N':
                cout << "Returning to main menu." << endl;
                products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
                break;
            default :
                cout<<"Invalid Option. Try again.\n";
                products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
                break;
        }
    }
}
