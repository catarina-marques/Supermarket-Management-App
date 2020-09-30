#include <iostream>
#include "CSuppliers.h"
#include "CSuppliers_Products.h"
#include "functions.h"
#include <limits>
#include <string>
#include "string.h"
using namespace std;

void managesuppliers(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void manageproducts(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);

void suppliers(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nSuppliers:\n1-Manage suppliers | 2-Manage products | 3-Back" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
        case '1' :
            managesuppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '2':
            manageproducts(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '3':
            cout << "\nGoing back..." << endl;
            home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        default :
            cout << "\nInvalid Option. Try again.";
            suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
    }
}

void addsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void editsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void deletesupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);

void managesuppliers(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nSuppliers:\n1-Add | 2-Edit | 3-Delete | 4-Back" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :
        addsupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '2':
        editsupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '3':
        deletesupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '4':
        cout << "\nGoing back..." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"\nInvalid Option. Try again.";
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
void addsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    char input_supplier_name[100];
    char input_supplier_address[100];
    int input_supplier_contact;

    cout << "Add New Supplier:\n" << endl;

    cout << "Enter supplier's name: ";
    while( !(cin.get(input_supplier_name, 100)) ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the name of the supplier. Max: 100 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the supplier's address: ";
    while( !(cin.get(input_supplier_address, 100)) ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter the supplier's address. Max: 100 characters." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter supplier's countact: ";
    while(!(cin >> input_supplier_contact)) { // garantir que há 9 algarismos no max?
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\nAdding new supplier:\n";
    cout << "Name: " << input_supplier_name << endl;
    cout << "Brand: " << input_supplier_address << endl;
    cout << "Contact: " << input_supplier_contact;


    char confirmation = 0;
    cout << "\nDo you confirm?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y': {

        sSuppliers newsupplier;
        strcpy(newsupplier.supplier_name,input_supplier_name);
        strcpy(newsupplier.supplier_address,input_supplier_address);
        newsupplier.supplier_contact = input_supplier_contact;
        supplierslist.insertsupplier(newsupplier);
        cout << "\nSupplier added!" << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case 'n' : case 'N':
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}

void editingsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int supplier_id_search);

void editsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    supplierslist.all_suppliers();

    unsigned int supplier_id_search;
    cout << "Insert the code of the supplier to edit: ";
    while(!(cin >> supplier_id_search) || (!supplierslist.id_exists(supplier_id_search))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: invalid input or supplier does not exist.\nTry again: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    char confirmation = 0;
    cout << "\nIs this the supplier you want to edit?(Y/N)\nPress any other letter to go back." << endl;
    supplierslist.showssupplier(supplier_id_search);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':{
        editingsupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist,supplier_id_search);
        break;
    }
    case 'n' : case 'N':
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid input. Going back to products menu.\n";
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}

void editingsupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int supplier_id_search){

    cout << "Which field do you want to edit? " << endl;
    char editoption = 0;
    cout << "1-Name | 2-Address | 3-Contact | 4-Back" << endl;
    scanf(" %c", &editoption);
    while ((getchar()) != '\n');

    switch(editoption){
    case '1' : {
        char input_name[100];
        cout << "Enter new name: ";
        while(!(cin.get(input_name, 100))){ //need to add verification if name is already in use.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new supplier's name. Max: 100 characters." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        supplierslist.editsupplier_name(input_name,supplier_id_search);
        cout << "Supplier edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '2' :{
        char input_address[100];
        cout << "Enter the new address: ";
        while(!(cin.get(input_address, 100))){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new supplier's address. Max: 100 characters." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        supplierslist.editsupplier_address(input_address,supplier_id_search);
        cout << "Supplier edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '3' :{
        unsigned int input_contact;
        cout << "Enter the new contact: ";
        while(!(cin >> input_contact)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter the new supplier's contact." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        supplierslist.editsupplier_contact(input_contact,supplier_id_search);
        cout << "Supplier edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '4':
        cout << "Going back." << endl;
        managesuppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        editingsupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist,supplier_id_search);
        break;
    }


}

void deletesupplier(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){


    unsigned int supplier_id_search;
    cout << "Insert the ID of the suppplier you want to delete." << endl;
    while(!(cin >> supplier_id_search) || !supplierslist.id_exists(supplier_id_search) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or supplier ID does not exist." << endl;
        cout << "Introduce the supplier ID you wish to delete: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // check if it's part of a sale
    if (!orderslist.supplier_order(supplier_id_search)){
        cout << "One or more orders from this supplier have been made, which means you cannot delete it." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }

    suppliersproductslist.all_products_supplier(supplier_id_search);

    char confirmation = 0;
    cout << "\nAre you sure you want to delete this supplier?This will also delete all the products available from it.(Y/N)\n" << endl;
    supplierslist.showssupplier(supplier_id_search);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':
        supplierslist.deletesupplier(supplier_id_search);
        cout << "Supplier and its products were deleted." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case 'n' : case 'N':
        cout << "Returning to main menu." << endl;
        managesuppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        deletesupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}

void addsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void editsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void deletesupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);

void manageproducts(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
    char option = 0;
    cout << "\nSupplier's Products:\n1-Add | 2-Edit | 3-Delete | 4-Back" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
    case '1' :
        addsupplierproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '2':
        editsupplierproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '3':
        deletesupplierproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case '4':
        cout << "\nGoing back..." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"\nInvalid Option. Try again.";
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}
void addsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    unsigned int input_product_id;
    unsigned int input_supplier_id;
    double input_unit_cost_withoutVAT;
    int input_min_order_discount;
    int input_discount;

    cout << "Add New Product to Supplier:\n" << endl;

    cout << "Enter product ID (product must exist in the list of products for sale): ";
    while( !(cin >> input_product_id) || !productlist.id_exists(input_product_id) ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input or product does not exist in the list of products for sale." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter supplier's ID: ";
    while( !(cin >> input_supplier_id) ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input or supplier does ID does not exist." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the cost per unit (without VAT): ";
    while( !(cin>>input_unit_cost_withoutVAT) ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input. Use the correct format: XX.XX" << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the discount: ";
    while(!(cin >> input_discount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter the minimum amount in order to get discount: ";
    while(!(cin >> input_min_order_discount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\nAdding new product to supplier" << endl;
    cout << "Unit cost (without VAT): " << input_unit_cost_withoutVAT;
    cout << "Discount: " << input_discount;
    cout << "Minimum order to get discount: " << input_min_order_discount;

    char confirmation = 0;
    cout << "\nDo you confirm?(Y/N)\nPress any other letter to go back." << endl;
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y': {

        sSuppliers_Products newsupplier_product;
        newsupplier_product.product_id = input_product_id;
        newsupplier_product.supplier_id = input_supplier_id;
        newsupplier_product.unit_cost_withoutVAT = input_unit_cost_withoutVAT;
        newsupplier_product.discount = input_discount;
        newsupplier_product.min_order_discount = input_min_order_discount;
        suppliersproductslist.insertsupplier_product(newsupplier_product);
        cout << "\nProduct added to supplier!" << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case 'n' : case 'N':
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Returning to main menu.\n";
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}

void editingsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int supplier_id_search);

void editsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    supplierslist.all_suppliers();
    unsigned int supplier_id_search;
    cout << "Insert the code of the supplier to edit its product from: ";
    while(!(cin >> supplier_id_search) || (!supplierslist.id_exists(supplier_id_search))){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: invalid input or supplier does not exist.\nTry again: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    char confirmation = 0;
    cout << "\nIs the product you want to edit from this supplier?(Y/N)\nPress any other letter to go back." << endl;
    supplierslist.showssupplier(supplier_id_search);
    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':{
        editingsupplierproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist,supplier_id_search);
        break;
    }
    case 'n' : case 'N':
        suppliers(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid input. Going back to products menu.\n";
        products(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
}

void editingsupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist, unsigned int supplier_id_search){

    suppliersproductslist.all_products_supplier(supplier_id_search);
    cout << "Which field do you want to edit? " << endl;
    char editoption = 0;
    //não faz sentido mudar o id do produto...
    cout << "1-Supplier ID | 2-Unit Cost (without VAT) | 3-Minimum Order | 4-Discount | 5-Back" << endl;
    scanf(" %c", &editoption);
    while ((getchar()) != '\n');

    switch(editoption){
    case '1' : {
        unsigned int input_new_supplier_id;
        cout << "Enter new supplier ID: ";
        while(!(cin >> input_new_supplier_id) || !supplierslist.id_exists(input_new_supplier_id)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input or supplier ID does not exist." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        suppliersproductslist.editsupplier_product_supplier(input_new_supplier_id,supplier_id_search);
        cout << "Supplier for this product was edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '2' :{
        double new_unit_cost;
        cout << "Enter the new cost per unit (without VAT): ";
        while(!(cin >> new_unit_cost)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input. Use the correct format: XX.XX." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        suppliersproductslist.editsupplier_product_unitcost(new_unit_cost,supplier_id_search);
        cout << "Cost per unit edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '3' :{
        int new_discount;
        cout << "Enter the new discount: ";
        while(!(cin >> new_discount)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        suppliersproductslist.editsupplier_product_discount(new_discount,supplier_id_search);
        cout << "Discount edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '4':{
        int new_min_order;
        cout << "Enter the new minimum order amount to get discount: ";
        while(!(cin >> new_min_order)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Invalid input." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        suppliersproductslist.editsupplier_product_min_order(new_min_order,supplier_id_search);
        cout << "Minimum order for this product edited. Returning to main menu. " << endl;

        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }
    case '5':
        cout << "Going back." << endl;
        manageproducts(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        editingsupplier(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist,supplier_id_search);
        break;
    }


}

void deletesupplierproduct(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){


    unsigned int supplier_id_search;
    cout << "Insert the ID of the suppplier whose product you want to delete." << endl;
    while(!(cin >> supplier_id_search) || !supplierslist.id_exists(supplier_id_search) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or supplier ID does not exist." << endl;
        cout << "Introduce the ID of the suppplier whose product you want to delete: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    suppliersproductslist.showssupplier_product(supplier_id_search);

    unsigned int product_id_search;
    cout << "Insert the ID of the product you want to delete." << endl;
    while(!(cin >> product_id_search) || !suppliersproductslist.id_exists(product_id_search) ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR. Invalid input or product ID does not exist." << endl;
        cout << "Introduce the ID of the product you want to delete: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // check if an order has been made
    if (!itemsorderslist.product_order(product_id_search)){
        cout << "One or more orders of this product have been made, which means you cannot delete it." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }

    char confirmation = 0;
    cout << "\nAre you sure you want to delete this product from this supplier?(Y/N)\n" << endl;

    scanf(" %c", &confirmation);
    while ((getchar()) != '\n');
    switch(confirmation){
    case 'y' : case 'Y':
        suppliersproductslist.deletesupplier_product(supplier_id_search);
        cout << "Product was deleted from supplier. Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    case 'n' : case 'N':
        cout << "Returning to main menu." << endl;
        manageproducts(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    default :
        cout<<"Invalid Option. Try again.\n";
        deletesupplierproduct(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
        break;
    }

}
