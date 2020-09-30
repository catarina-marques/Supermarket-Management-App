#include <iostream>
#include "CProduct_Type.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;

CProduct_Type::CProduct_Type(void) {
    start = NULL;
    end = NULL;
}

CProduct_Type::~CProduct_Type(void){
    CNodeProduct_Type *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}


void CProduct_Type::addtype(sProduct_Type addedtype){
    CNodeProduct_Type *newnode = new CNodeProduct_Type;
    CNodeProduct_Type *current;
    CNodeProduct_Type *previous;

    newnode -> type = addedtype;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
        newnode->type.type_id =1;
    }else{
        previous = NULL;
        current=start;
        while(current->next!=NULL){
            previous = current;
            current=current->next;
        }
        previous = current;
        current->next=newnode;
        newnode->type.type_id = (previous->type.type_id)+1;
    }
}
void CProduct_Type::edittype(sProduct_Type editedtype, int index){//override previous struct

    if(start==NULL)return;
    else{
        int idx = 1;
        CNodeProduct_Type *current = start;
        while( current != NULL ) {
            if ( idx == index ){
                current->type = editedtype;
            }
            idx++;
            current = current->next;
        }
    }

}

void CProduct_Type::deletetype(unsigned int id){//override previous struct
    CNodeProduct_Type *current=start;
    CNodeProduct_Type *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->type.type_id == id){
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

void CProduct_Type::showsproducttype(unsigned int id) const{
    if (start == NULL) return;
    else {
        CNodeProduct_Type * current = start;
        while( current != NULL ) {
            if (current->type.type_id == id){
                cout << "Category: " << current->type.product_type_name << endl;
                cout << "VAT: " << current->type.product_type_VAT << " %" << endl;
            }
            current = current->next;
        }
    }
}

void CProduct_Type::all_producttypes(void) const{

    CNodeProduct_Type *current = start;

    if(start==NULL)
        cout << "List is empty..." << endl;
    else{
        while(current!=NULL){
            cout << "*****" << endl;
            cout << "Type ID: " << current->type.type_id << endl;
            cout << "Name: " << current->type.product_type_name << endl;
            cout << "VAT: " << current->type.product_type_VAT << "%" << endl;
            current=current->next;
        }
    }
/*
    fstream file_type("typesfile.txt", ios::in|ios::out|ios::binary);
    if (!file_type.is_open()){
        cout << "Could not open file to read. ";
    }
    sProduct_Type readtype;
    while(file_type.read((char*)(&readtype), sizeof(readtype))){
        printf ("ID: %d Type: %s VAT: %d\n", readtype.type_id, readtype.product_type_name, readtype.product_type_VAT);
    }
    file_type.close();
*/
}

bool CProduct_Type::id_exists(unsigned int id) const{
    CNodeProduct_Type *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->type.type_id == id){
                return true;
        }
        current = current->next;
    }
    return false;
}

void CProduct_Type::showsproducttype_byname(char soughtname[]) const{
    if ( start == NULL )
        cout << "List of product types is empty." << endl;
    else {
        CNodeProduct_Type * current = start;
        int occurrences = 0;
        string stringsoughtname;
        stringsoughtname = soughtname;
        transform(stringsoughtname.begin(), stringsoughtname.end(), stringsoughtname.begin(), ::tolower);

        while( current != NULL ) {
            bool found = false;
            char * pointer;
            string stringname;

            stringname = current->type.product_type_name ;
            transform(stringname.begin(), stringname.end(), stringname.begin(), ::tolower);

            pointer = strstr(stringname.c_str(), stringsoughtname.c_str());

            if(pointer != NULL){
                found = true;
                occurrences++;}

            if ( found ){
                cout << "*****" << endl;
                cout << "Type ID: " << current->type.type_id << endl;
                cout << "Name: " << current->type.product_type_name << endl;
                cout << "VAT: " << current->type.product_type_VAT << endl;
            }
            current = current->next;
        }
        if(occurrences == 0) cout << "No product type with that name was found." << endl;
        else cout << occurrences << " result(s) were found." << endl;
    }

}

int CProduct_Type::seek_index(unsigned int soughtid)const{//returns the index of its position on the list
    CNodeProduct_Type *current = start;
    int idx = 1;
    while(current!=NULL){
        if(current->type.type_id == soughtid ){
            return (idx);//return index
        }
        idx++;
        current = current -> next;
    }
    return NULL; //didnt find
}

int CProduct_Type::get_VAT(unsigned int type_product_to_search)const{
    CNodeProduct_Type *current = start;

    while(current!=NULL){
        if(current->type.type_id == type_product_to_search ){
            return (current->type.product_type_VAT);
        }
        current = current -> next;
    }
    return NULL; //didnt find
}

void CProduct_Type::get_product_type_name(unsigned int soughttype_id)const{
    CNodeProduct_Type *current = start;

    char type_name[100];
    while(current!=NULL){
        if(current->type.type_id == soughttype_id ){
            strcpy(current->type.product_type_name, type_name);
            cout << "\nType: " << type_name;
        }

        current = current -> next;
    }

}

void CProduct_Type::loadfromfile(CProduct_Type &typeslist){

    fstream file_type("typesfile.txt", ios::in|ios::out|ios::binary);
    if (!file_type.is_open()){
        cout << "Error. Could not open file to load. ";
    }
    sProduct_Type loadtype;
    while(file_type.read((char*)(&loadtype), sizeof(loadtype))){
        sProduct_Type addtype;
        addtype.type_id = loadtype.type_id;
        strcpy(addtype.product_type_name, loadtype.product_type_name);
        addtype.product_type_VAT = loadtype.product_type_VAT;
        this->addtype(addtype);
        //typeslist.addtype(addtype);
    }
    file_type.close();

}

void CProduct_Type::loadfromlist(CProduct_Type typeslist){
    CNodeProduct_Type *current = start;

    if(start==NULL)
        cout << "List is empty..." << endl;
    else{
        while(current!=NULL){
            fstream file_type("typesfile.txt", ios::app|ios::in|ios::out|ios::binary);
            if(!file_type.is_open()){
                cout <<"Could not open file." << endl;
            }
            file_type.write((char *) current, sizeof(*current));
            file_type.close();
            current=current->next;
        }
    }



}
