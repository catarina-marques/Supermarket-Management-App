#include <iostream>
#include "functions.h"
#include "CProduct.h"
#include <string>
#include "string.h"
#include <limits>
#include <stdio.h>
using namespace std;

void editingproduct(CProduct productlist, CSale salelist, unsigned int idcodesearch , int product_index, CItems_Sale itemssalelist){

    char input_name[100];
    char input_brand[50];
    char input_type[50];
    double input_selling_price;

    cout << "Enter the new name: ";
    while(!(cin.get(input_name, 100))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the new name of the product. Max: 100 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the new brand: ";
    while(!(cin.get(input_brand, 50))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the new brand of the product. Max: 50 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the new type: ";
    while(!(cin.get(input_type, 50))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the new type of the product. Max: 50 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the new price: ";
    while(!(cin >> input_selling_price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: the price should be entered in the correct format. (xx.xx)" << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    sProduct editedproduct;
    editedproduct.product_id = idcodesearch; //id_code stays the same
    strcpy(editedproduct.product_name, input_name);
    strcpy(editedproduct.product_brand, input_brand);
    strcpy(editedproduct.product_type, input_type);
    editedproduct.product_price = input_selling_price;

    productlist.editproduct(editedproduct,product_index);

    cout << "Returning to main menu." << endl;
    home(productlist, salelist, itemssalelist);
}
