#include <iostream>
#include "CSuppliers_Products.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>


using namespace std;

CSuppliers_Products::CSuppliers_Products(void) {
    start = NULL;
    end = NULL;
}

CSuppliers_Products::~CSuppliers_Products(void){
    CNodeSuppliers_Products *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

void CSuppliers_Products::insertsupplier_product(sSuppliers_Products newsupplier_product){
    CNodeSuppliers_Products *newnode = new CNodeSuppliers_Products;
    CNodeSuppliers_Products *current;

    newnode -> supplier_product = newsupplier_product;
    newnode->next = NULL;

    if(start == NULL){
        start=newnode;
    }else{
        current=start;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void CSuppliers_Products::all_products_supplier(unsigned int supplier_id_search) const{
    if (start == NULL) return;
    else {
        CNodeSuppliers_Products * current = start;
        while( current != NULL ) {
            if (current->supplier_product.supplier_id == supplier_id_search){
                cout << "*****" << endl;
                cout << "Product ID: " << current->supplier_product.product_id << endl;
                cout << "Cost per unit (without VAT): " << current->supplier_product.unit_cost_withoutVAT << endl;
                cout << "Discount: " << current->supplier_product.discount << endl;
                cout << "Min units to get discount: " << current->supplier_product.min_order_discount << endl;

            }
            current = current->next;
        }
    }
}

bool CSuppliers_Products::productordered(unsigned int supplier_id_search) const{
    CNodeSuppliers_Products *current = start;
    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->supplier_product.supplier_id == supplier_id_search) return true;
        current = current->next;
    }
    return false;
}

void CSuppliers_Products::editsupplier_product_supplier(unsigned int new_supplier_id, unsigned int supplier_id_search){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers_Products *current = start;
        while( current != NULL ) {
            if (current->supplier_product.supplier_id == supplier_id_search){
                current->supplier_product.supplier_id = new_supplier_id;
            }
            current = current->next;
        }
    }
}
void CSuppliers_Products::editsupplier_product_unitcost(double new_unit_cost, unsigned int supplier_id_search){
    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers_Products *current = start;
        while( current != NULL ) {
            if (current->supplier_product.supplier_id == supplier_id_search){
                current->supplier_product.unit_cost_withoutVAT = new_unit_cost;
            }
            current = current->next;
        }
    }
}
void CSuppliers_Products::editsupplier_product_min_order(int new_min_order, unsigned int supplier_id_search){
    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers_Products *current = start;
        while( current != NULL ) {
            if (current->supplier_product.supplier_id == supplier_id_search){
                current->supplier_product.min_order_discount = new_min_order;
            }
            current = current->next;
        }
    }
}
void CSuppliers_Products::editsupplier_product_discount(int new_discount, unsigned int supplier_id_search){
    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers_Products *current = start;
        while( current != NULL ) {
            if (current->supplier_product.supplier_id == supplier_id_search){
                current->supplier_product.discount = new_discount;
            }
            current = current->next;
        }
    }
}

void CSuppliers_Products::showssupplier_product(unsigned int supplier_id_search) const{
    CNodeSuppliers_Products *current = start;

    if (start == NULL) return;
    while( current != NULL ) {
        if (current->supplier_product.supplier_id == supplier_id_search){
            cout << "*****" << endl;
            cout << "Product ID: " << current->supplier_product.product_id<< endl;
            cout << "Supplier ID: " << current->supplier_product.supplier_id << endl;
            cout << "Unit Cost: " << current->supplier_product.unit_cost_withoutVAT << endl;
            cout << "Discount: " << current->supplier_product.discount << endl;
            cout << "Min Order to get discount: " << current->supplier_product.min_order_discount << endl;
        }
        current = current->next;
    }


}
void CSuppliers_Products::deletesupplier_product(unsigned int supplier_id_search){
    CNodeSuppliers_Products *current=start;
    CNodeSuppliers_Products *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->supplier_product.supplier_id == supplier_id_search ){
                if(previous==NULL)
                    start = current->next;
                else
                    previous->next=current->next;
                delete(current);
                return;
            }
            previous=current;
            current=current->next;
        }
    }

}

bool CSuppliers_Products::id_exists(unsigned int product_id_search) const{
    CNodeSuppliers_Products *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->supplier_product.supplier_id == product_id_search){
                return true;
        }
        current = current->next;
    }
    return false;
}

vector<sSuppliers_Products> CSuppliers_Products::checkcostefficiency(vector<sProduct> lowstockList){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers_Products *current = start;
        double cost = 0;
        vector<sSuppliers_Products> suppliers_productsList;
        for (int i=0 ; i < lowstockList.size() ; i++) {
            while( current != NULL ) {//goes through the supplier_product list to determine which supplier has better deal
                if(lowstockList[i].product_id == current->supplier_product.product_id){
                    cost = current ->supplier_product.unit_cost_withoutVAT;
                    if( cost < current->supplier_product.unit_cost_withoutVAT ){
                        cost = current ->supplier_product.unit_cost_withoutVAT;
                    }

                }
                current = current->next;
            }
            suppliers_productsList.push_back(current->supplier_product);
        }

    }

}

unsigned int CSuppliers_Products::get_best_supplier( unsigned int product_id_to_order){
    CNodeSuppliers_Products *current = start;

    if(start==NULL) return 0;
    else{
        double cost = 0;
        unsigned int ideal_supplier_id;
        while( current != NULL ) {
            if( current->supplier_product.product_id == product_id_to_order ){
                cost = current ->supplier_product.unit_cost_withoutVAT;
                ideal_supplier_id = current->supplier_product.supplier_id;
                if( cost < current->supplier_product.unit_cost_withoutVAT ){
                    cost = current ->supplier_product.unit_cost_withoutVAT;
                    ideal_supplier_id = current->supplier_product.supplier_id;
                }

            }
            current = current->next;
        }
        return ideal_supplier_id;
    }
}

int CSuppliers_Products::get_discount(unsigned int supplier_id_to_order_from, unsigned int product_id_to_order, int quantity_to_order){
    CNodeSuppliers_Products *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->supplier_product.supplier_id == supplier_id_to_order_from
                && current->supplier_product.product_id == product_id_to_order){

           if(current->supplier_product.min_order_discount > quantity_to_order) return 0;// n ha desconto
           else return (current->supplier_product.discount);

        }
        current = current->next;
    }


}

double CSuppliers_Products::get_cost_without_VAT(unsigned int supplier_id_to_order_from, unsigned int product_id_to_order) const{
    CNodeSuppliers_Products *current = start;

    if (start == NULL) return 0;
    double unit_cost_without_VAT;
    while (current != NULL) {
        if (current->supplier_product.supplier_id == supplier_id_to_order_from
                && current->supplier_product.product_id == product_id_to_order){
           unit_cost_without_VAT = current->supplier_product.unit_cost_withoutVAT;
           return (unit_cost_without_VAT);

        }
        current = current->next;
    }

}
