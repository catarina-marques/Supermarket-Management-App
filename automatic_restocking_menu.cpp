#include <iostream>
#include "functions.h"
#include "CProduct.h"
#include <limits>
#include <ctime>
#include "string.h"
#include <iomanip>
using namespace std;

void partialrestocking(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);
void totalrestocking(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist);

void automatic_restocking(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){
//generates orders for all products whose stock is below minimum stock allowed
//check if it's cost efficient (minimum quantity to order to obtain discount)
    char option = 0;
    cout << "\nAutomatic Restocking:\n1-Partial | 2-Total | 3-Back" << endl;
    cout << "Enter option: ";
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    switch(option){
        case '1' :
            partialrestocking(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '2':
            totalrestocking(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        case '3':
            cout << "\nGoing back..." << endl;
            home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
        default :
            cout<<"\nInvalid Option. Try again.";
            automatic_restocking(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
            break;
    }

}

void partialrestocking(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    cout << "Enter the ID of the type of product to restock: ";
    unsigned int input_type_id;
    while(!(cin >> input_type_id) || !typeslist.id_exists(input_type_id)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Invalid input or type does not exist." << endl;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    vector<sProduct> lowstockList = productlist.stock_below_min_type(input_type_id);

    if (lowstockList.size() == 0){
        cout << "There are no products of this type that need to be restocked at the moment." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }
    unsigned int neworder_id;
    //gera encomenda
    sOrders neworder;
    orderslist.createorder(neworder);

    neworder_id = orderslist.getlastid(); //need to get the order id generated

    //declare data used for each item in an order
    unsigned int product_id_to_order;
    unsigned int supplier_id_to_order_from;
    int quantity_to_order;
    int VAT;
    int discount;
    double discount_value;
    double total_cost_item_afterVAT_afterDiscount;
    int nofitems = 0;
    double total_c = 0; // with VAT
    double total_cost_item_beforeVAT_afterDiscount;
    double unit_cost_withoutVAT;

    cout << "Restocking all products of type " << input_type_id << "." <<endl;
    cout << "Order details: " << endl;
    for (int i = 0 ; i < lowstockList.size() ; i++){

        //apurar dados a introduzir em cada item da encomenda
        product_id_to_order = lowstockList[i].product_id;
        //cout << "product id to order: " << product_id_to_order << endl;
        supplier_id_to_order_from = suppliersproductslist.get_best_supplier(product_id_to_order);
        //cout << "supplier id to order from: " << supplier_id_to_order_from << endl;
        quantity_to_order = lowstockList[i].product_max_stock - lowstockList[i].product_stock;
        //cout << "quantitu to order " << quantity_to_order << endl;
        VAT = typeslist.get_VAT(lowstockList[i].product_type);
        //cout << "vat" << VAT << endl;
        discount = suppliersproductslist.get_discount(supplier_id_to_order_from,product_id_to_order, quantity_to_order);
        //cout << "discount " << discount << endl;

        unit_cost_withoutVAT = suppliersproductslist.get_cost_without_VAT(supplier_id_to_order_from, product_id_to_order);
        //cout << "unit cost without vat " << unit_cost_withoutVAT << endl;

        discount_value = ( unit_cost_withoutVAT * quantity_to_order ) * ((double)discount/100.0f);
        //cout << "discount value" << discount_value << endl;

        total_cost_item_beforeVAT_afterDiscount = (( unit_cost_withoutVAT * quantity_to_order ) - discount_value );
        //cout << "total cost item before vat after discount" << total_cost_item_beforeVAT_afterDiscount << endl;

        total_cost_item_afterVAT_afterDiscount = total_cost_item_beforeVAT_afterDiscount * (((double)VAT+100.0f)/100.0f);

        //cout << setprecision(2) << fixed << "total cost item after vat after discount" << total_cost_item_afterVAT_afterDiscount << endl;



        //gerar um item da encomenda
        sItems_Order newitemorder;
        newitemorder.order_id = neworder_id;
        newitemorder.product_id = lowstockList[i].product_id;
        newitemorder.quantity = quantity_to_order;
        newitemorder.discount_beforeVAT = discount_value ;
        newitemorder.total_cost_afterVAT = total_cost_item_afterVAT_afterDiscount;


        itemsorderslist.add_to_order(newitemorder);

        nofitems ++;

        total_c = total_c +  total_cost_item_afterVAT_afterDiscount;

        itemsorderslist.show_items_order_details(neworder_id,product_id_to_order,total_cost_item_beforeVAT_afterDiscount, VAT);

    }

    time_t now;
    struct tm *info;
    char date[80];
    time( &now );
    info = localtime( &now);
    strftime(date,80,"%x - %I:%M%p", info);

    strcpy(neworder.date_order, date);
    neworder.n_items = nofitems;
    neworder.total_cost = total_c;
    neworder.received = false;

    orderslist.updateorder(neworder, neworder_id);

    cout << setprecision(2) << fixed << "Total cost: " << total_c << " euros" << endl;
    cout << "Order Number: " << neworder_id << " was placed. Returning to main menu." << endl;

    home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);

}

void totalrestocking(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist){

    vector<sProduct> lowstockList = productlist.stock_below_min();//list of products whose stock needs to be restocked
    //vector<sSuppliers_Products> suppliers_productsList = suppliersproductslist.checkcostefficiency(lowstockList);//list of supplier_product with better deal
    if (lowstockList.size() == 0){
        cout << "There are no products needing to be restocked at the moment." << endl;
        cout << "Returning to main menu." << endl;
        home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);
    }

    unsigned int neworder_id;
    //gera encomenda
    sOrders neworder;
    orderslist.createorder(neworder);

    neworder_id = orderslist.getlastid(); //need to get the order id generated

    //declare data used for each item in an order
    unsigned int product_id_to_order;
    unsigned int supplier_id_to_order_from;
    int quantity_to_order;
    int VAT;
    int discount;
    double discount_value;
    double total_cost_item_afterVAT_afterDiscount;
    int nofitems = 0;
    double total_c = 0; // with VAT
    double total_cost_item_beforeVAT_afterDiscount;
    double unit_cost_withoutVAT;

     cout << "Restocking all products." << endl;
    cout << "Order details: " << endl;
    for (int i = 0 ; i < lowstockList.size() ; i++){

        //apurar dados a introduzir em cada item da encomenda
        product_id_to_order = lowstockList[i].product_id;
        //cout << "product id to order: " << product_id_to_order << endl;
        supplier_id_to_order_from = suppliersproductslist.get_best_supplier(product_id_to_order);
        //cout << "supplier id to order from: " << supplier_id_to_order_from << endl;
        quantity_to_order = lowstockList[i].product_max_stock - lowstockList[i].product_stock;
        //cout << "quantitu to order " << quantity_to_order << endl;
        VAT = typeslist.get_VAT(lowstockList[i].product_type);
        //cout << "vat" << VAT << endl;
        discount = suppliersproductslist.get_discount(supplier_id_to_order_from,product_id_to_order, quantity_to_order);
        //cout << "discount " << discount << endl;

        unit_cost_withoutVAT = suppliersproductslist.get_cost_without_VAT(supplier_id_to_order_from, product_id_to_order);
        //cout << "unit cost without vat " << unit_cost_withoutVAT << endl;

        discount_value = ( unit_cost_withoutVAT * quantity_to_order ) * ((double)discount/100.0f);
        //cout << "discount value" << discount_value << endl;

        total_cost_item_beforeVAT_afterDiscount = (( unit_cost_withoutVAT * quantity_to_order ) - discount_value );
        //cout << "total cost item before vat after discount" << total_cost_item_beforeVAT_afterDiscount << endl;

        total_cost_item_afterVAT_afterDiscount = total_cost_item_beforeVAT_afterDiscount * (((double)VAT+100.0f)/100.0f);

        //cout << setprecision(2) << fixed << "total cost item after vat after discount" << total_cost_item_afterVAT_afterDiscount << endl;



        //gerar um item da encomenda
        sItems_Order newitemorder;
        newitemorder.order_id = neworder_id;
        newitemorder.product_id = lowstockList[i].product_id;
        newitemorder.quantity = quantity_to_order;
        newitemorder.discount_beforeVAT = discount_value ;
        newitemorder.total_cost_afterVAT = total_cost_item_afterVAT_afterDiscount;


        itemsorderslist.add_to_order(newitemorder);

        nofitems ++;

        total_c = total_c +  total_cost_item_afterVAT_afterDiscount;

        itemsorderslist.show_items_order_details(neworder_id,product_id_to_order,total_cost_item_beforeVAT_afterDiscount, VAT);

    }

    time_t now;
    struct tm *info;
    char date[80];
    time( &now );
    info = localtime( &now);
    strftime(date,80,"%x - %I:%M%p", info);

    strcpy(neworder.date_order, date);
    neworder.n_items = nofitems;
    neworder.total_cost = total_c;
    neworder.received = false;

    orderslist.updateorder(neworder, neworder_id);

    cout << setprecision(2) << fixed << "Total cost: " << total_c << " euros" << endl;
    cout << "Order Number: " << neworder_id << " was placed. Returning to main menu." << endl;

    home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);

}
