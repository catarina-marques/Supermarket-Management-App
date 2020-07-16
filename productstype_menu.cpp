#include <iostream>
#include "CProduct_Type.h"
#include "functions.h"
#include <limits>
#include <string>
#include "string.h"
using namespace std;

void addproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void editingproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int idcodesearch );
void editproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void deleteproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);

void typeproductoptions(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nProducts:\n1-Add a type | 2-Edit a type | 3-Delete a type | 4-List of types | 5-Back\n" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :
        addproducttype(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '2' :
        editproducttype(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '3' :
        deleteproducttype(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '4' :
        cout << "List all. FOR TESTING PURPOSES." << endl;
        typeslist.all_producttypes();
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '5' :
        cout << "\nGoing back..." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"\nInvalid Option. Try again.";
        typeproductoptions(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
void addproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char input_name[100];
    int input_VAT;

    cout << "Add New Type of Product:\n" << endl;

    cout << "Enter type name: ";
    while(!( cin.get(input_name, 100))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the type of the product. Max: 50 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the VAT for this type of product: ";
    while(!(cin >>input_VAT) || input_VAT < 0 || input_VAT > 50  ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter VAT. Program expects an integer between 0 and 50." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\nEditing new type:\n";
    cout << "Name: " << input_name << endl;
    cout << "VAT: " << input_VAT << endl;


    char confirmation = 0;
    cout << "\nDo you confirm?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y': {
        //creates an instance of the struct
        sProduct_Type newtype;
        strcpy(newtype.product_type_name,input_name);
        newtype.product_type_VAT = input_VAT;
        typeslist.addtype(newtype);
        cout << "\nType edited!" << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case 'n' : case 'N':
        typeproductoptions(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
void editproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int idcodesearch;
    cout << "Insert the code of the type of product to edit: ";
    while(!(cin >> idcodesearch) || !typeslist.id_exists(idcodesearch)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or type ID does not exist." << endl;
        cout << "Introduce the type ID you wish to delete: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    char confirmation = 0;
    cout << "\nIs this the type you want to edit?(Y/N)\nPress any other letter to go back." << endl;
    typeslist.showsproducttype(idcodesearch);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');

    switch(confirmation){
    case 'y' : case 'Y':
        editingproducttype(typeslist, productlist, salelist, itemssalelist, supplierslist,suppliersproductslist,orderslist, itemsorderslist, idcodesearch);
        break;
    case 'n' : case 'N':
        editproducttype(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
void editingproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int idcodesearch){

    char input_name[100];
    int input_VAT;

    cout << "Enter new type name: ";
    while(!( cin.get(input_name, 100))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the type of the product. Max: 50 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the new VAT for this type of product: ";
    while(!(cin >>input_VAT)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter VAT. Program expects an integer." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    sProduct_Type editedtype;
    editedtype.type_id = idcodesearch;
    strcpy(editedtype.product_type_name,input_name);
    editedtype.product_type_VAT = input_VAT;

    typeslist.edittype(editedtype,idcodesearch);

    cout << "Returning to main menu." << endl;
    home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
}


void deleteproducttype(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int idcodesearch;
    cout << "Insert the ID of the type to delete." << endl;
    while(!(cin >> idcodesearch) || !typeslist.id_exists(idcodesearch)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or type does not exist." << endl;
        cout << "Insert the ID of the type to delete.";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    //check if there is a product associated with this type
    if(productlist.typeassociated(idcodesearch)){
        cout << "This type is associated with one or more products, which means you cannot delete it." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }

    char confirmation = 0;
    cout << "\nAre you sure you want to delete this type?(Y/N)\n" << endl;
    typeslist.showsproducttype(idcodesearch);

    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');

    switch(confirmation){
    case 'y' : case 'Y':
        typeslist.deletetype(idcodesearch);
        cout << "Type deleted." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case 'n' : case 'N':
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        typeproductoptions(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
