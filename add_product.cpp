#include <iostream>
#include "functions.h"
#include "CProduct.h"
#include <string>
#include "string.h"
#include <limits>
using namespace std;

void addproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    //unsigned int input_id_code;
    char input_name[100];
    char input_brand[50];
    char input_type[50];
    double input_price;

    cout << "Add New Product:\n" << endl;
    //product code is going to be generated so this isnt needed anymore
/*    cout << "Enter the product code: ";
    while( !(cin >> input_id_code) || productlist.id_exists(input_id_code) ) {//if the id code already exists because id code is unique
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or a product with this ID code already exists." << endl;
        cout << "Enter the product code: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
*/

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

    cout << "Enter the product type: ";
    while(!(cin.get(input_type, 50))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the type of the product. Max: 50 characters." << endl;
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

    cout << "\nAdding new product:\n";
    //cout << "Product ID: " << input_id_code << endl;
    cout << "Name: " << input_name << endl;
    cout << "Brand: " << input_brand << endl;
    cout << "Type: " << input_type << endl;
    cout << "Selling price: " << input_price << endl;

    char confirmation = 0;
    cout << "\nDo you confirm?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
        case 'y' : case 'Y': {
            //creates an instance of the struct
            sProduct addedproduct;
            //addedproduct.id_code = input_id_code;
            strcpy(addedproduct.product_name, input_name);
            strcpy(addedproduct.product_brand, input_brand);
            strcpy(addedproduct.product_type, input_type);
            addedproduct.product_price = input_price;
            productlist.insertproduct(addedproduct);
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
