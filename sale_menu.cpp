#include <iostream>
#include "functions.h"
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <limits>
#include "CSale.h"
#include <ctime>
#include <string>
#include "string.h"
#include <vector>

using namespace std;

void basket(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int newsale_id, sSale createdsale);
void checkout(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int newsale_id, sSale createdsale);

void initiatesale(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    unsigned int newsale_id;
    cout << "New Sale:" << endl;
    sSale createdsale;
    salelist.createsale(createdsale);
    newsale_id = salelist.getlastid();//get the id of the sale that was created to pass to basket
    //salelist.showsale(newsale_id);
    basket(typeslist, productlist, salelist, itemssalelist, supplierslist, suppliersproductslist,orderslist,  itemsorderslist,  newsale_id,createdsale);//start adding stuff to "basket"

}

void basket(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int newsale_id, sSale createdsale){

    char option = 0;
    do{
        sItems_Sale newitem;
        unsigned int input_type_id;
        unsigned int input_product_id;
        int input_units; //how many units of a product

        cout << "Introduce the type ID of the product you wish to buy: ";
        while(!(cin >> input_type_id) || !typeslist.id_exists(input_type_id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input or type ID does not exist." << endl;
            cout << "Introduce the type ID of the product you wish to buy: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.showproducts_bytype(input_type_id);

        cout << "Introduce the product ID you wish to buy: ";
        while(!(cin >> input_product_id) || !productlist.id_exists(input_product_id) || productlist.get_stock(input_product_id) == 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input, product ID does not exist or there's none in stock." << endl;
            cout << "Introduce the product ID you wish to buy: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "How many units are of this product are your taking? ";
        while(!(cin >> input_units) || input_units < 0 || productlist.get_stock(input_product_id) < input_units ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR. Invalid input or there aren't that many units in stock." << endl;
            cout << "How many units are of this product are your taking? ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        double cost = input_units * productlist.get_price(input_product_id);

        newitem.id_sale = newsale_id;
        newitem.id_product = input_product_id;
        newitem.quantity = input_units;
        newitem.products_cost = cost;
        itemssalelist.add_to_sale(newitem);


        cout << "\n1-Add more to basket | Any other key to check out" << endl;
        scanf(" %c", &option);
        while ((getchar()) != '\n');
    } while( option == '1');

    //if we're here, user chose to checkout
    checkout( typeslist, productlist, salelist, itemssalelist, supplierslist, suppliersproductslist,orderslist,  itemsorderslist,  newsale_id, createdsale);
}

void checkout(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int newsale_id, sSale createdsale){

    itemssalelist.showitemsinbasket(newsale_id);
    //update stuff in the sale
    int nofitems;
    double total_c;
    nofitems = itemssalelist.n_of_items(newsale_id);
    total_c = itemssalelist.sum_cost_items(newsale_id);

    //get current time
    time_t now;
    struct tm *info;
    char date[80];
    time( &now );
    info = localtime( &now);
    strftime(date,80,"%x - %I:%M%p", info);

    //update sale with new data(number of items, date, total cost)
    createdsale.id_sale = newsale_id;
    strcpy(createdsale.date , date);
    createdsale.n_items= nofitems;
    createdsale.total_cost = total_c;
    //date[strcspn(date, "\n")] = 0;
    salelist.updatesale(createdsale, newsale_id);

    salelist.showsale(newsale_id);

    char option = 0;
    cout << "\nDo you want to finish sale?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case 'y' : case 'Y':{
        cout << "Stock updated." << endl;
        vector<sItems_Sale> salesList = itemssalelist.getlistitems_sale(newsale_id);
        productlist.updatestocks( salesList );
        //cout << "Adds data to binary file.Eventually." << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case 'n' : case 'N':
        cout << "Deletes the node for the sale, the nodes on the item sale list and put back stock" << endl ;
        salelist.deletesale(createdsale);
        itemssalelist.deleteitemssale(newsale_id);
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

    home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
}


