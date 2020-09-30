#include <iostream>
#include "CSuppliers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>


using namespace std;

CSuppliers::CSuppliers(void) {
    start = NULL;
    end = NULL;
}

CSuppliers::~CSuppliers(void){
    CNodeSuppliers *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

void CSuppliers::insertsupplier(sSuppliers newsupplier){
    CNodeSuppliers *newnode = new CNodeSuppliers;
    CNodeSuppliers *current;
    CNodeSuppliers *previous;

    newnode -> supplier = newsupplier;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
        newnode->supplier.supplier_id = 1;
    }else{
        previous = NULL;
        current=start;
        while(current->next!=NULL){
            previous = current;
            current=current->next;
        }
        previous = current;
        current->next=newnode;
        newnode->supplier.supplier_id = (previous->supplier.supplier_id)+1;
    }

}

bool CSuppliers::id_exists(unsigned int supplier_id_search) const{
    CNodeSuppliers *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->supplier.supplier_id == supplier_id_search){
                return true;
        }
        current = current->next;
    }
    return false;
}

void CSuppliers::showssupplier(unsigned int supplier_id_search) const{
    CNodeSuppliers *current = start;

    if (start == NULL) return;
    while( current != NULL ) {
        if (current->supplier.supplier_id == supplier_id_search){
            cout << "*****" << endl;
            cout << "Supplier: " << current->supplier.supplier_name << endl;
            cout << "Address: " << current->supplier.supplier_address << endl;
            cout << "Contact: " << current->supplier.supplier_contact << endl;
        }
        current = current->next;
    }

}
void CSuppliers::editsupplier_name(char newname[], unsigned int supplier_id_search){

    if(start==NULL){
        cout << "List of suppliers is empty." << endl;
    }else{
        CNodeSuppliers *current = start;
        while( current != NULL ) {
            if (current->supplier.supplier_id == supplier_id_search){
                strcpy(current->supplier.supplier_name, newname);
            }
            current = current->next;
        }
    }
}
void CSuppliers::editsupplier_address(char newaddress[], unsigned int supplier_id_search){
    if(start==NULL){
        cout << "List of suppliers is empty." << endl;
    }else{
        CNodeSuppliers *current = start;
        while( current != NULL ) {
            if (current->supplier.supplier_id == supplier_id_search){
                strcpy(current->supplier.supplier_address, newaddress);
            }
            current = current->next;
        }
    }
}
void CSuppliers::editsupplier_contact(unsigned int newcontact, unsigned int supplier_id_search){
    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeSuppliers *current = start;
        while( current != NULL ) {
            if (current->supplier.supplier_id == supplier_id_search){
                current->supplier.supplier_contact = newcontact;
            }
            current = current->next;
        }
    }
}

void CSuppliers::all_suppliers() const{
    CNodeSuppliers *current = start;

    if(start==NULL)
        cout << "List is empty..." << endl;
    else{
        while(current!=NULL){
            cout << "*****" << endl;
            cout << "Supplier ID: " << current->supplier.supplier_id << endl;
            cout << "Name: " << current->supplier.supplier_name << endl;
            cout << "Address " << current->supplier.supplier_address<< endl;
            cout << "Contact: " << current->supplier.supplier_contact << endl;
            current=current->next;
        }
    }
}

void CSuppliers::deletesupplier(unsigned int supplier_id_search){
    CNodeSuppliers *current=start;
    CNodeSuppliers *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->supplier.supplier_id == supplier_id_search ){
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
