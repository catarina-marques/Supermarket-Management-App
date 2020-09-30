#include <iostream>
#include "CProduct.h"
#include "CItems_Sale.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

CProduct::CProduct(void) {
    start = NULL;
    end = NULL;
}

CProduct::~CProduct(void){
    CNodeProduct *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}


void CProduct::insertproduct(sProduct addedproduct){
    CNodeProduct *newnode = new CNodeProduct;
    CNodeProduct *current;
    CNodeProduct *previous;

    newnode -> product = addedproduct;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
        newnode->product.product_id = 1;
    }else{
        previous = NULL;
        current=start;
        while(current->next!=NULL){
            previous = current;
            current=current->next;
        }
        previous = current;
        current->next=newnode;
        newnode->product.product_id = (previous->product.product_id)+1;
    }

}
void CProduct::editproduct(sProduct editedproduct, unsigned int id){//override previous struct

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                current->product = editedproduct;
            }
            current = current->next;
        }
    }

}

void CProduct::deleteproduct(unsigned int id){//override previous struct
    CNodeProduct *current=start;
    CNodeProduct *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->product.product_id == id ){
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

void CProduct::showsproduct(int index) const{
    if ( start == NULL )
        cout << "List of products is empty." << endl;
    else {
        int idx = 1;
        CNodeProduct * current = start;
        while( current != NULL ) {
            if ( idx == index ){
                cout << "*****" << endl;
                cout << "Product ID: " << current->product.product_id << endl;
                cout << "Name: " << current->product.product_name << endl;
                cout << "Brand: " << current->product.product_brand << endl;
                cout << "Type: " << current->product.product_type << endl;
                cout << "Price: " << current->product.market_price << endl;
                cout << "Min Stock: " << current->product.product_min_stock << endl;
                cout << "Max Stock: " << current->product.product_max_stock << endl;
                cout << "Stock: " << current->product.product_stock << endl;
            }
            idx++;
            current = current->next;
        }
    }
}

void CProduct::showsproduct_byid(unsigned int id) const{
    if (start == NULL) return;
    else {
        CNodeProduct * current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                cout << "*****" << endl;
                cout << "Product ID: " << current->product.product_id << endl;
                cout << "Name: " << current->product.product_name << endl;
                cout << "Brand: " << current->product.product_brand << endl;
                cout << "Type: " << current->product.product_type << endl;
                cout << "Price: " << current->product.market_price << endl;
                cout << "Min Stock: " << current->product.product_min_stock << endl;
                cout << "Max Stock: " << current->product.product_max_stock << endl;
                cout << "Stock: " << current->product.product_stock << endl;
            }
            current = current->next;
        }
    }
}

void CProduct::showsproduct_byname(char soughtname[]) const{
    if ( start == NULL )
        cout << "List of products is empty." << endl;
    else {
        CNodeProduct * current = start;
        int occurrences = 0;
        string stringsoughtname;
        stringsoughtname = soughtname;
        transform(stringsoughtname.begin(), stringsoughtname.end(), stringsoughtname.begin(), ::tolower);

        while( current != NULL ) {
            bool found = false;
            char * pointer;
            string stringname;

            stringname = current->product.product_name;
            transform(stringname.begin(), stringname.end(), stringname.begin(), ::tolower);

            pointer = strstr(stringname.c_str(), stringsoughtname.c_str());

            if(pointer != NULL){
                found = true;
                occurrences++;}

            if ( found ){
                cout << "*****" << endl;
                cout << "Product ID: " << current->product.product_id << endl;
                cout << "Name: " << current->product.product_name << endl;
                cout << "Brand: " << current->product.product_brand << endl;
                cout << "Type: " << current->product.product_type << endl;
                cout << "Price: " << current->product.market_price << endl;
                cout << "Min Stock: " << current->product.product_min_stock << endl;
                cout << "Max Stock: " << current->product.product_max_stock << endl;
                cout << "Stock: " << current->product.product_stock << endl;
            }
            current = current->next;
        }
        if(occurrences == 0) cout << "\nNo product with that name was found." << endl;
        else cout << "\n" << occurrences << " result(s) were found." << endl;
    }

}


int CProduct::seek_index(unsigned int soughtid)const{//returns the index of its position on the list
    CNodeProduct *current = start;
    int idx = 1;
    while(current!=NULL){
        if(current->product.product_id == soughtid ){
            return (idx);//return index
        }
        idx++;
        current = current -> next;
    }
    return NULL; //didnt find
}

void CProduct::all_products(void) const{
    CNodeProduct *current = start;

    if(start==NULL)
        cout << "List is empty..." << endl;
    else{
        while(current!=NULL){
            cout << "*****" << endl;
            cout << "Product ID: " << current->product.product_id << endl;
            cout << "Name: " << current->product.product_name << endl;
            cout << "Brand: " << current->product.product_brand << endl;
            cout << "Type ID: " << current->product.product_type << endl;
            //typeslist.get_product_type_name(current->product.product_type);
            cout << "Market price: " << current->product.market_price << endl;
            cout << setprecision(2) << fixed << "Basic Price: " << current->product.basic_price << endl;
            cout << "Min Stock: " << current->product.product_min_stock << endl;
            cout << "Max Stock: " << current->product.product_max_stock << endl;
            cout << "Stock: " << current->product.product_stock << endl;
            current=current->next;
        }
    }
}

bool CProduct::id_exists(unsigned int id) const{
    CNodeProduct *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->product.product_id == id){
                return true;
        }
        current = current->next;
    }
    return false;
}

double CProduct::get_price(unsigned int soughtid)const{//returns price of this product
    CNodeProduct *current = start;

    while(current!=NULL){
        if(current->product.product_id == soughtid ){
            //cout << "price: " << current->product.selling_price ;
            return (current->product.market_price);
        }
        current = current -> next;
    }
    return NULL; //didnt find
}

void CProduct::editproduct_name(char newname[], unsigned int id){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                strcpy(current->product.product_name, newname);
            }
            current = current->next;
        }
    }

}

void CProduct::editproduct_brand(char newbrand[], unsigned int id){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                strcpy(current->product.product_brand, newbrand);
            }
            current = current->next;
        }
    }

}

void CProduct::editproduct_type(unsigned int newtype, unsigned int id){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                current->product.product_type = newtype;
            }
            current = current->next;
        }
    }

}

void CProduct::editproduct_price(double newprice, unsigned int id){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                current->product.market_price = newprice;
            }
            current = current->next;
        }
    }

}

void CProduct::editproduct_min_max_stock(int newmin, int newmax, unsigned int id){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            if (current->product.product_id == id){
                current->product.product_min_stock = newmin;
                current->product.product_max_stock = newmax;
            }
            current = current->next;
        }
    }

}

bool CProduct::typeassociated(unsigned int id) const{
    CNodeProduct *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->product.product_type == id){
                return true;
        }
        current = current->next;
    }
    return false;
}

void CProduct::showproducts_bytype(unsigned int id) const{
    if (start == NULL) return;
    else {
        CNodeProduct * current = start;
        while( current != NULL ) {
            if (current->product.product_type == id){
                cout << "*****" << endl;
                cout << "Product ID: " << current->product.product_id << endl;
                cout << "Name: " << current->product.product_name << endl;
                cout << "Brand: " << current->product.product_brand << endl;
                cout << setprecision(2) << fixed << "Market Price: " << current->product.market_price << endl;
                cout << setprecision(2) << fixed << "Basic Price" << current->product.basic_price << endl;
                cout << "Stock: " << current->product.product_stock << endl;
            }
            current = current->next;
        }
    }
}

int CProduct::get_stock(unsigned int id)const{//returns price of this product
    CNodeProduct *current = start;

    while(current!=NULL){
        if(current->product.product_id == id ){
            return (current->product.product_stock);
        }
        current = current -> next;
    }
    return NULL; //didnt find
}

void CProduct::updatestocks(vector<sItems_Sale> saleList){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            for (int i=0 ; i<saleList.size() ; i++) {
                if(saleList[i].id_product ==  current->product.product_id){
                    current->product.product_stock = current->product.product_stock - saleList[i].quantity;
                }
                current = current->next;
            }

        }
    }

}
void CProduct::updatestocko(vector<sItems_Order> itemsinorderList){

    if(start==NULL){
        cout << "List of products is empty." << endl;
    }else{
        CNodeProduct *current = start;
        while( current != NULL ) {
            for (int i=0 ; i<itemsinorderList.size() ; i++) {
                if(itemsinorderList[i].product_id ==  current->product.product_id){
                    current->product.product_stock = current->product.product_stock + itemsinorderList[i].quantity;
                }
                current = current->next;
            }

        }
    }

}
vector<sProduct> CProduct::stock_below_min(){
    vector<sProduct> returnList;

    CNodeProduct *current = start;

    if(start==NULL) return returnList;
    while(current != NULL){
        if(current->product.product_stock < current->product.product_min_stock){
            returnList.push_back(current->product);
        }
        current = current->next;
    }
    return returnList;
}

vector<sProduct> CProduct::stock_below_min_type(unsigned int input_type_id){
    vector<sProduct> returnList;

    CNodeProduct *current = start;

    if(start==NULL) return returnList;
    while(current != NULL){
        if(current->product.product_stock < current->product.product_min_stock
                && current->product.product_type == input_type_id){
            returnList.push_back(current->product);
        }
        current = current->next;
    }
    return returnList;
}

unsigned int CProduct::product_type(unsigned int product_id_search) const{
    if (start == NULL) return 0;
    else {
        unsigned int type;
        CNodeProduct * current = start;
        while( current != NULL ) {
            if (current->product.product_type == product_id_search){
                type = current->product.product_type;
                return type;
            }
            current = current->next;
        }
    }

}

void CProduct::inventory_value_byname(char soughtname[], CProduct_Type typeslist) const{
    if ( start == NULL )
        cout << "List of products is empty." << endl;
    else {
        CNodeProduct * current = start;
        double value_whole_inventory_withoutVAT = 0;
        double VAT_to_pay= 0;
        double p_price;
        int p_stock;
        int vat;

        string stringsoughtname;
        stringsoughtname = soughtname;
        transform(stringsoughtname.begin(), stringsoughtname.end(), stringsoughtname.begin(), ::tolower);

        while( current != NULL ) {
            bool found = false;
            char * pointer;
            string stringname;

            stringname = current->product.product_name;
            transform(stringname.begin(), stringname.end(), stringname.begin(), ::tolower);

            pointer = strstr(stringname.c_str(), stringsoughtname.c_str());

            if(pointer != NULL){
                found = true;
            }
            if ( found ){
                /*cout << "Product ID: " << current->product.product_id << endl;;
                cout << "Type: " << current->product.product_type << endl;
                cout << "Price: " << current->product.product_price << endl;
                cout << "Stock: " << current->product.product_stock << endl;*/
                vat = typeslist.get_VAT(current->product.product_type);
                p_price = current->product.market_price;
                p_stock = current->product.product_stock;
                value_whole_inventory_withoutVAT += (p_price * p_stock) / (((double)vat+100.0f)/100.0f);
                VAT_to_pay +=  (p_price * p_stock) - (p_price * p_stock) / (((double)vat+100.0f)/100.0f) ;
                //cout << "vat to pay" << VAT_to_pay << endl;
            }
            current = current->next;
        }
        cout << setprecision(2) << fixed << "\nTotal: " << value_whole_inventory_withoutVAT + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Value of whole inventory: " << value_whole_inventory_withoutVAT << " euros" << endl;
        cout << setprecision(2) << fixed << "VAT: " << VAT_to_pay << " euros " << endl;


    }

}

void CProduct::inventory_value_bytype(unsigned int soughttype, CProduct_Type typeslist) const{
    if (start == NULL) return;
    else {
        double value_whole_inventory_withoutVAT = 0;
        double VAT_to_pay= 0;
        double p_price;
        int p_stock;
        int vat;
        CNodeProduct * current = start;
        while( current != NULL ) {
            if (current->product.product_type == soughttype){
                vat = typeslist.get_VAT(current->product.product_type);
                p_price = current->product.market_price;
                p_stock = current->product.product_stock;
                value_whole_inventory_withoutVAT += (p_price * p_stock) / (((double)vat+100.0f)/100.0f);
                VAT_to_pay +=  (p_price * p_stock) - (p_price * p_stock) / (((double)vat+100.0f)/100.0f) ;
            }
            current = current->next;
        }
        cout << setprecision(2) << fixed << "\nTotal: " << value_whole_inventory_withoutVAT + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Value of whole inventory: " << value_whole_inventory_withoutVAT << " euros" << endl;
        cout << setprecision(2) << fixed << "Taxes(VAT): " << VAT_to_pay << " euros " << endl;

    }
}

void CProduct::inventory_value(CProduct_Type typeslist) const{
    CNodeProduct *current = start;

    if(start==NULL)
        cout << "List is empty..." << endl;
    else{
        double value_whole_inventory_withoutVAT = 0;
        double VAT_to_pay= 0;
        double p_price;
        int p_stock;
        int vat;
        while(current!=NULL){

            vat = typeslist.get_VAT(current->product.product_type);
            p_price = current->product.market_price;
            p_stock = current->product.product_stock;
            value_whole_inventory_withoutVAT += (p_price * p_stock) / (((double)vat+100.0f)/100.0f);
            VAT_to_pay +=  (p_price * p_stock) - (p_price * p_stock) / (((double)vat+100.0f)/100.0f) ;

            current=current->next;
        }
        cout << setprecision(2) << fixed << "\nTotal: " << value_whole_inventory_withoutVAT + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Value of whole inventory: " << value_whole_inventory_withoutVAT << " euros" << endl;
        cout << setprecision(2) << fixed << "Taxes(VAT): " << VAT_to_pay << " euros " << endl;

    }
}

void CProduct::calc_basic_price(unsigned int sought_id, CProduct_Type typeslist){
    if (start == NULL) return;
    else {
        double basic_price = 0;
        CNodeProduct * current = start;
        while( current != NULL ) {
            if(current->product.product_id == sought_id){
                int VAT;
                int product_type;
                product_type = current->product.product_type;
                VAT = typeslist.get_VAT(product_type);
                basic_price = current->product.market_price / (((double)VAT+100.0f)/100.0f);
                current->product.basic_price = basic_price;//updates the basic price

                //cout << setprecision(2) << fixed << "Market price: " << current->product.market_price << endl;
                //cout << setprecision(2) << fixed << "Basic price calculated: " << basic_price << endl;
                //cout << setprecision(2) << fixed << "current->product.basic_price" << current->product.basic_price << endl;
            }
            current = current->next;
        }


    }
}
unsigned int CProduct::getlastid(void) const{
    CNodeProduct *current = start;
    if(start==NULL) return 0;
    while(current-> next != NULL){
        current=current->next;
    }
    return(current->product.product_id);

}
void CProduct::update_basic_price_VAT_changed(unsigned int type_to_edit, int new_VAT){
    if (start == NULL) return;
    else {
        double basic_price = 0;
        CNodeProduct * current = start;
        while( current != NULL ) {
            if(current->product.product_type == type_to_edit){
                basic_price = current->product.market_price / (((double)new_VAT+100.0f)/100.0f);
                //cout << setprecision(2) << fixed << "Market price: " << current->product.market_price << endl;
                //cout << setprecision(2) << fixed << "Basic price calculated: " << basic_price << endl;
                current->product.basic_price = basic_price;//updates the basic price
                //cout << setprecision(2) << fixed << "current->product.basic_price" << current->product.basic_price << endl;
            }
            current = current->next;
        }


    }
}
