#include <iostream>
#include "COrders.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

COrders::COrders(void) {
    start = NULL;
    end = NULL;
}

COrders::~COrders(void){
    CNodeOrders *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

bool COrders::supplier_order(unsigned int supplier_id_search) const{
    CNodeOrders *current = start;
    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->order.supplier_id == supplier_id_search) return true;
        current = current->next;
    }
    return false;
}

bool COrders::id_exists(unsigned int order_id_search) const{
    CNodeOrders *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->order.order_id == order_id_search){
                return true;
        }
        current = current->next;
    }
    return false;
}

void COrders::show_order(unsigned int order_id_search) const{
    CNodeOrders *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->order.order_id == order_id_search){
            cout << "Order ID: " << current->order.order_id << endl;
            cout << "Supplier ID: " << current->order.supplier_id << endl;
            cout << "Date: " << current->order.date_order << endl;
            cout << "Number of different items: " << current->order.n_items << endl;
            cout << "Total Cost: " << current->order.total_cost << endl;
        }
        current = current->next;
    }

}

void COrders::show_order_pending()const{
    CNodeOrders *current = start;

        if (start == NULL) return ;
        while (current != NULL) {
            if (current->order.received == false){
                cout << "*****" << endl;
                cout << "Order ID: " << current->order.order_id << endl;
                cout << "Supplier ID: " << current->order.supplier_id << endl;
                cout << "Date: " << current->order.date_order << endl;
                cout << "Number of different items: " << current->order.n_items << endl;
                cout << "Total Cost: " << current->order.total_cost << endl;
            }
            current = current->next;
        }
}

void COrders::updatestatus(unsigned int order_id_search){
    CNodeOrders *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->order.order_id == order_id_search){
            current->order.received = true;
            time_t now;
            struct tm *info;
            char date[80];
            time( &now );
            info = localtime( &now);
            strftime(date,80,"%x - %I:%M%p", info);
            strcpy(current->order.date_reception , date);
        }
        current = current->next;
    }

}

void COrders::createorder(sOrders neworder){
    CNodeOrders *newnode = new CNodeOrders;
    CNodeOrders *current;
    CNodeOrders *previous;

    newnode -> order = neworder;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
        newnode->order.order_id=1;
    }else{
        previous = NULL;
        current=start;
        while(current->next!=NULL){
            previous = current;
            current=current->next;
        }
        previous = current;
        current->next=newnode;
        newnode->order.order_id = (previous->order.order_id)+1;//incremeenta o id da sale
    }
}

unsigned int COrders::getlastid(void) const{
    CNodeOrders *current = start;
    if(start==NULL) return 0;
    while(current-> next != NULL){
        current=current->next;
    }
    return(current->order.order_id);

}

void COrders::updateorder(sOrders neworder,unsigned int neworder_id){
    if(start==NULL){ return;
    }else{
        CNodeOrders *current = start;
        while( current != NULL ) {
            if ( current->order.order_id == neworder_id ){
                current->order = neworder;
            }
            current = current->next;
        }
    }
}
