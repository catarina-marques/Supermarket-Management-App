#include <iostream>
#include "functions.h"
#include <limits>

using namespace std;

void sales_stats(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nSales Stats:\n1-By Product | 2-By Type of Product | 3-By Time Interval | 4-Global Sales Stats | 5-Back " << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :{
        cout << "List all sales of a product." << endl;
        unsigned int input_product_id;
        cout << "Introduce the product ID to search its sales: ";
        while(!(cin >> input_product_id) || !productlist.id_exists(input_product_id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input or product ID does not exist." << endl;
            cout << "Introduce the product ID to search its sales: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        itemssalelist.salebyproduct(input_product_id);
        itemssalelist.salerevenue_byproduct(input_product_id, typeslist, productlist);
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '2' :{
        cout << "List all sales of a type of product." << endl;
        unsigned int input_product_type_id;
        cout << "Introduce the type ID to search its sales: ";
        while(!(cin >> input_product_type_id) || !productlist.id_exists(input_product_type_id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input or product ID does not exist." << endl;
            cout << "Introduce the product ID to search its sales: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        typeslist.get_product_type_name(input_product_type_id);
        itemssalelist.salebyproducttype(input_product_type_id,productlist);
        itemssalelist.salerevenue_byproducttype(input_product_type_id, typeslist, productlist);
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '3' :{
        char startdate[11];
        char enddate[11];
        cout << "Insert starting point(DD/MM/YYYY): " ;
        while(!(cin >> startdate)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input. Make sure your input is in the correct format." << endl;
            cout << "Insert starting point(DD/MM/YYYY): ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "Insert ending point(DD/MM/YYYY): ";
        while(!(cin >> enddate)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input. Make sure your input is in the correct format." << endl;
            cout << "Insert ending point(DD/MM/YYYY): ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        salelist.salestimeinterval(startdate,enddate);
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '4' :
        cout << "List all Sales." << endl;
        salelist.allsalesstats();
        itemssalelist.salerevenue_total(typeslist,productlist);
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '5' :
        cout << "\nGoing back..." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;

    default :
        cout<<"\nInvalid Option. Try again.";
        sales_stats(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
