#include <iostream>
#include <fstream>
#include "functions.h"
#include "CProduct.h"
#include <string>
#include "string.h"
#include <limits>
using namespace std;

void addproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void editingproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int idcodesearch );
void editproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void deleteproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);


void products(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nProducts:\n1-Add product | 2-Edit product | 3-Delete product | 4-Back\n" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
        case '1' :
            addproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '2' :
            editproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '3' :
            deleteproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '4' :
            cout << "\nGoing back..." << endl;
            home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        default :
            cout<<"\nInvalid Option. Try again.";
            products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
    }

}

void addproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    char input_name[100];
    char input_brand[50];
    unsigned int input_type_id;
    double input_price;
    int input_stock, input_min_stock, input_max_stock;

    cout << "Add New Product:\n" << endl;

    cout << "Enter the product name: ";
    while(!( cin.get(input_name, 100))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the name of the product. Max: 100 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the product brand: ";
    while(!(cin.get(input_brand, 50))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the brand of the product. Max: 50 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the ID of the type of product: ";
    while(!(cin >> input_type_id) || !typeslist.id_exists(input_type_id)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input or type does not exist." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the product price (xx.xx) : ";
    while(!(cin >> input_price)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: the price should be entered in the correct format. (xx.xx)" << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the min stock : ";
    while(!(cin >> input_min_stock) || input_min_stock < 0 ) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: program expects an integer of zero or more." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout << "Enter the max stock : ";
    while(!(cin >> input_max_stock) || input_max_stock < input_min_stock ) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: program expects an integer. Max stock has to be higher than min stock. " << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the stock : ";
    while(!(cin >> input_stock) || input_min_stock >= input_stock || input_stock >= input_max_stock ){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error: program expects an integer. Consider the min and max stock allowed for this product." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\nAdding new product:\n";

    cout << "Name: " << input_name << endl;
    cout << "Brand: " << input_brand << endl;
    typeslist.showsproducttype(input_type_id);
    cout << "Price(VAT included): " << input_price << endl;
    cout << "Min Stock: " << input_min_stock << " Max Stock: " << input_max_stock << endl;
    cout << "Products currently in stock: " << input_stock << endl;

    char confirmation = 0;
    cout << "\nDo you confirm?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
        case 'y' : case 'Y': {
            //creates an instance of the struct
            sProduct addedproduct;
            strcpy(addedproduct.product_name, input_name);
            strcpy(addedproduct.product_brand, input_brand);
            addedproduct.product_type = input_type_id;
            addedproduct.market_price = input_price;
            addedproduct.product_min_stock = input_min_stock;
            addedproduct.product_max_stock = input_max_stock;
            addedproduct.product_stock = input_stock;
            productlist.insertproduct(addedproduct);
            unsigned int newproduct_id;
            newproduct_id =productlist.getlastid();
            productlist.calc_basic_price(newproduct_id,typeslist);
            //write to binary files
            ofstream file("products_list", ios::binary);
               if (!file.is_open()){
                   cout << "Could not open file to write";
                   return;
               }
            cout << "\nNew product added!" << endl;
            home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        }
    case 'n' : case 'N':
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }


}

void editproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int idcodesearch;
    cout << "Insert the code of the product to edit: ";
    while(!(cin >> idcodesearch) || (!productlist.id_exists(idcodesearch))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: invalid input or product does not exist.\nTry again: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    char confirmation = 0;
    cout << "\nIs this the product you want to edit?(Y/N)\nPress any other letter to go back." << endl;
    productlist.showsproduct_byid(idcodesearch);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':
        editingproduct(typeslist, productlist, salelist, itemssalelist, supplierslist,suppliersproductslist,orderslist, itemsorderslist, idcodesearch);
        break;
    case 'n' : case 'N':
        editproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid input. Going back to products menu.\n";
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}


void editingproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int idcodesearch ){

    cout << "Which field do you want to edit? " << endl;
    char editoption = 0;
    cout << "1-Name | 2-Brand | 3-Type | 4-Price | 5-Min/Max Stock | Press any other key to go back." << endl;
    scanf(" %c", &editoption);
    while ((getchar()) != '\n');

    switch(editoption){
    case '1' : {
        char input_name[100];
        cout << "Enter the new name: ";
        while(!(cin.get(input_name, 100))){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new name of the product. Max: 100 characters." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.editproduct_name(input_name,idcodesearch);
        cout << "Product edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '2' :{
        char input_brand[50];
        cout << "Enter the new brand: ";
        while(!(cin.get(input_brand, 50))){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new brand of the product. Max: 50 characters." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.editproduct_brand(input_brand,idcodesearch);
        cout << "Product edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '3' :{
        unsigned int input_type_id;
        cout << "Enter the ID of the type of product: ";
        while(!(cin >> input_type_id) || !typeslist.id_exists(input_type_id)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input or type does not exist." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.editproduct_type(input_type_id,idcodesearch);
        productlist.calc_basic_price(idcodesearch,typeslist);//VAT could change, this covers it.
        cout << "Product edited. Returning to main menu. " << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '4' : {
        double input_selling_price;
        cout << "Enter the new price: ";
        while(!(cin >> input_selling_price)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: the price should be entered in the correct format. (xx.xx)" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.editproduct_price(input_selling_price,idcodesearch);
        productlist.calc_basic_price(idcodesearch,typeslist);
        cout << "Product edited. Returning to main menu. " << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '5' :{

        int input_min_stock, input_max_stock;

        cout << "Enter the new min stock: ";
        while(!(cin >> input_min_stock) || input_min_stock < 0 ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: invalid input. Program expects an integer." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "Enter the new max stock: ";
        while(!(cin >> input_max_stock) || input_max_stock < input_min_stock ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: invalid input. Program expects an integer." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        productlist.editproduct_min_max_stock(input_min_stock,input_max_stock,idcodesearch);
        cout << "Product edited. Returning to main menu. " << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    default :
        cout<<"Invalid Option. Try again.\n";
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }


}

void deleteproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int idcodesearch;
    cout << "Insert the code of the product to delete." << endl;
    while(!(cin >> idcodesearch) || !productlist.id_exists(idcodesearch) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or product ID does not exist." << endl;
        cout << "Introduce the product ID you wish to delete: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // check if it's part of a sale
    if (itemssalelist.productsold(idcodesearch)){
        cout << "Sales of this product have been made, which means you cannot delete it." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }

    char confirmation = 0;
    cout << "\nAre you sure you want to delete this product?(Y/N)\n" << endl;
    productlist.showsproduct(idcodesearch);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':
        productlist.deleteproduct(idcodesearch);
        cout << "Product deleted." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case 'n' : case 'N':
        cout << "Returning to main menu." << endl;
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        deleteproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}

