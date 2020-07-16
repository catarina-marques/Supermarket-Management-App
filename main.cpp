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

using namespace std;

int main(){
    cout << "Welcome to the SuperMarket App." << endl;
    cout << "Developed by : Catarina Marques 2020." << endl;

    CProduct_Type typeslist;
    CProduct productlist;  
    CSale salelist;
    CItems_Sale itemssalelist;
    CSuppliers supplierslist;
    CSuppliers_Products suppliersproductslist;
    COrders orderslist;
    CItems_Order itemsorderslist;

 //(CProduct_Type typeslist, CProduct productlist, CSale salelist, CItems_Sale itemssalelist, CSuppliers supplierslist, CSuppliers_Products suppliersproductslist,COrders orderslist, CItems_Order itemsorderslist)

    sProduct addtest1,addtest2;

    addtest1.product_id = 1 ;
    strcpy(addtest1.product_name, "Iogurte Natural");
    strcpy(addtest1.product_brand, "Danone");
    addtest1.product_type = 1;
    addtest1.product_price = 1.48;
    addtest1.product_stock = 40;
    addtest1.product_min_stock = 50;
    addtest1.product_max_stock = 150;
    productlist.insertproduct(addtest1);

    addtest2.product_id = 2 ;
    strcpy(addtest2.product_name, "Iogurte Grego Morango");
    strcpy(addtest2.product_brand, "Mimosa");
    addtest2.product_type = 1;
    addtest2.product_price = 2.69;
    addtest2.product_stock = 10;
    addtest2.product_min_stock = 30;
    addtest2.product_max_stock = 150;
    productlist.insertproduct(addtest2);
    cout << "Here's some products to test." << endl;
    productlist.all_products();

    sProduct_Type type1,type2;

    type1.type_id = 1;
    strcpy(type1.product_type_name, "Milk and Dairy");
    type1.product_type_VAT = 6;
    typeslist.addtype(type1);

    type2.type_id = 2;
    strcpy(type2.product_type_name, "Canned Goods");
    type2.product_type_VAT = 13;
    typeslist.addtype(type2);
    cout << "Here's some types of products to test." << endl;
    typeslist.all_producttypes();

    sSuppliers supplier1,supplier2;

    supplier1.supplier_id = 1;
    strcpy(supplier1.supplier_name, "THE DAIRY HOUSE LTD");
    strcpy(supplier1.supplier_address, "Whitehill Park Industrial Estate, Weobley HR4 8QE, Reino Unido");
    supplier1.supplier_contact = 544318815;
    supplierslist.insertsupplier(supplier1);

    supplier2.supplier_id = 2;
    strcpy(supplier2.supplier_name, "Sonegave");
    strcpy(supplier2.supplier_address, "Rua da Garagem, 10, 2794-022 Carnaxide");
    supplier2.supplier_contact = 210420000;
    supplierslist.insertsupplier(supplier2);


    sSuppliers_Products supplier_product1,supplier_product2;

    supplier_product1.supplier_id = 2;
    supplier_product1.product_id = 1;
    supplier_product1.unit_cost_withoutVAT = 0.50;
    supplier_product1.discount = 15;
    supplier_product1.min_order_discount = 50;
    suppliersproductslist.insertsupplier_product(supplier_product1);

    supplier_product2.supplier_id = 2;
    supplier_product2.product_id = 2;
    supplier_product2.unit_cost_withoutVAT = 0.80;
    supplier_product2.discount = 20;
    supplier_product2.min_order_discount = 70;
    suppliersproductslist.insertsupplier_product(supplier_product2);

    home(typeslist,productlist,salelist,itemssalelist,supplierslist,suppliersproductslist,orderslist,itemsorderslist);

    return 0;
}










