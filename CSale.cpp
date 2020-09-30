#include <iostream>
#include "CSale.h"
#include <ctime>

using namespace std;

CSale::CSale(void) {
    start = NULL;
    end = NULL;
}

CSale::~CSale(void){
    CNodeSale *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

void CSale::createsale(sSale createdsale){
    CNodeSale *newnode = new CNodeSale;
    CNodeSale *current;
    CNodeSale *previous;

    newnode -> a_Sale = createdsale;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;
        newnode->a_Sale.id_sale=1;
    }else{
        previous = NULL;
        current=start;
        while(current->next!=NULL){
            previous = current;
            current=current->next;
        }
        previous = current;
        current->next=newnode;
        newnode->a_Sale.id_sale = (previous->a_Sale.id_sale)+1;//incremeenta o id da sale
        //cout << "id:" << newnode->a_Sale.id_sale << endl;
    }
}

void CSale::deletesale(sSale createdsale){
    CNodeSale *current=start;
    CNodeSale *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->a_Sale.id_sale == createdsale.id_sale ){
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

unsigned int CSale::getlastid(void) const{
    CNodeSale *current = start;
    if(start==NULL) return 0;
    while(current-> next != NULL){
        current=current->next;
    }
    return(current->a_Sale.id_sale);

}

void CSale::showsale(unsigned int sale_id) const{
    CNodeSale *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->a_Sale.id_sale == sale_id){
            cout << "Sale ID: " << current->a_Sale.id_sale << endl;
            cout << "Date: " << current->a_Sale.date << endl;
            cout << "Number of different items: " << current->a_Sale.n_items << endl;
            cout << "Total Cost: " << current->a_Sale.total_cost << endl;
        }
        current = current->next;
    }

}

void CSale::updatesale(sSale createdsale,unsigned int newsale_id){
    if(start==NULL){ return;
    }else{
        CNodeSale *current = start;
        while( current != NULL ) {
            if ( current->a_Sale.id_sale == newsale_id ){
                current->a_Sale = createdsale;
            }
            current = current->next;
        }
    }
}

void CSale::allsalesstats(void)const{
    CNodeSale *current = start;
    double total_sales = 0;

    if(start==NULL){
        cout << "No sales registered." << endl;
        return;
    }
    while(current != NULL){
        total_sales += current->a_Sale.total_cost;
        current = current->next;
    }
    cout << "Total sales: " << total_sales << " euros" << endl;

}

void CSale::salestimeinterval(char start_date[11], char end_date[11]){
    CNodeSale *current = start;
    double total_sales = 0;

    if(start==NULL){
        cout << "No sales registered." << endl;
        return;
    }
    while(current != NULL){
        if(current->a_Sale.date > start_date && current->a_Sale.date < end_date ){
            total_sales += current->a_Sale.total_cost;
        }
        current = current->next;
    }
    if(total_sales==0) cout << "No sale was made in that time interval. " << endl;
    else cout << "From " << start_date << " to " << end_date << "the total of sales was " << total_sales << " euros." << endl;


}

