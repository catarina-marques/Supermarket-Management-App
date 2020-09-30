#include <iostream>
#include "functions.h"
#include "CProduct.h"
#include <limits>

using namespace std;

void inventory(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nInventory:\n1-List by name | 2-List by type | 3-List ALL | 4-Back" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :{
        cout << "\nSearch by name..." << endl;
        char soughtname[100];
        cout << "Insert the name of the product you are looking for: ";
        while(!(cin.get(soughtname, 100))){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new name of the product. Max: 100 characters." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        productlist.showsproduct_byname(soughtname);
        productlist.inventory_value_byname(soughtname,typeslist);
        inventory(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist); //volta para o inventory menu???
        break;
    }
    case '2':{
        cout << "\nSearch by type..." << endl;
        unsigned int soughttype;
        cout << "Insert the type ID of the product you are looking for: ";
        while(!(cin >> soughttype) || !typeslist.id_exists(soughttype)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input or type does not exist." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        typeslist.get_product_type_name(soughttype);
        productlist.showproducts_bytype(soughttype);
        productlist.inventory_value_bytype(soughttype,typeslist);
        inventory(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist); //volta para o inventory menu???
        break;
    }
    case '3':
        cout << "Listing all products..." << endl;
        productlist.all_products();
        productlist.inventory_value(typeslist);
        inventory(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '4':
        cout << "\nGoing back..." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"\nInvalid Option. Try again.";
        inventory(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
