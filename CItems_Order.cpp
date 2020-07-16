#include <iostream>
#include "CItems_Order.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

CItems_Order::CItems_Order(void) {
    start = NULL;
    end = NULL;
}

CItems_Order::~CItems_Order(void){
    CNodeItems_Order *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

bool CItems_Order::product_order(unsigned int product_id_search) const{
    CNodeItems_Order *current = start;
    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->item_order.product_id== product_id_search) return true;
        current = current->next;
    }
    return false;
}
void CItems_Order::show_items_order(unsigned int order_id_search) const{
    CNodeItems_Order *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->item_order.order_id == order_id_search){
            cout << "*****" << endl;
            cout << "Product ID: " << current->item_order.product_id << endl;
            cout << "Product Name: " << "To show the name need to implement new function in CProduct."<< endl;
            cout << "Units: " << current->item_order.quantity << endl;
            cout << "Cost: " << current->item_order.total_cost_afterVAT << endl;
        }
        current = current->next;
    }

}

vector<sItems_Order> CItems_Order::getlistitems_order(unsigned int order_id_search){
    vector<sItems_Order> returnList;

    CNodeItems_Order *current = start;

    if(start==NULL) return returnList;
    while(current != NULL){
        if(current->item_order.order_id == order_id_search){
            returnList.push_back(current->item_order);
        }
        current = current->next;
    }
    return returnList;
}

void CItems_Order::add_to_order(sItems_Order newitemorder){
    CNodeItems_Order *newnode = new CNodeItems_Order;
    CNodeItems_Order *current;

    newnode->item_order = newitemorder;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
    }else{
        current=start;
        while(current->next!=NULL)
            current=current->next;
        current->next=newnode;
    }
}

void CItems_Order::show_items_order_details(unsigned int order_id_search, unsigned int product_id_to_order, double total_cost_item_beforeVAT_afterDiscount , int VAT) const{
    CNodeItems_Order *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->item_order.order_id == order_id_search
                && current->item_order.product_id == product_id_to_order){
            cout << "*****" << endl;
            cout << "Product ID: " << current->item_order.product_id << endl;
            //cout << "Product Name: " << "To show the name need to implement new function in CProduct."<< endl;
            cout << "Quantity: " << current->item_order.quantity << " units" << endl;
            cout << "Discount: " << current->item_order.discount_beforeVAT << " euros" << endl;
            cout << "Cost without VAT, with discount: " << setprecision(2) << fixed << total_cost_item_beforeVAT_afterDiscount << " euros" <<endl ;
            cout << "VAT: " << VAT << "%" << endl;
            cout << "Subtotal(with VAT, with discount): " << setprecision(2) << fixed << current->item_order.total_cost_afterVAT << " euros" << endl;
        }
        current = current->next;
    }

}
