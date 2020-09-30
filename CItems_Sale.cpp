#include <iostream>
#include "CItems_Sale.h"
#include "CProduct.h"
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

CItems_Sale::CItems_Sale(void) {
    start = NULL;
    end = NULL;
}

CItems_Sale::~CItems_Sale(void){
    CNodeItems_Sale *current, *next;
    current = start;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    end = NULL;
}

void CItems_Sale::add_to_sale(sItems_Sale newitem){
    CNodeItems_Sale *newnode = new CNodeItems_Sale;
    CNodeItems_Sale *current;

    newnode->item_Sale = newitem;
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

void CItems_Sale::showitemsinbasket(unsigned int sale_id){
    CNodeItems_Sale *current = start;

    if (start == NULL) return ;
    while (current != NULL) {
        if (current->item_Sale.id_sale == sale_id){
            cout << "*****" << endl;
            cout << "Product ID: " << current->item_Sale.id_product<< endl;
            cout << "Product Name: " << "To show the name need to implement new function in CProduct."<< endl;
            cout << "Units: " << current->item_Sale.quantity << endl;
            cout << "Cost: " << current->item_Sale.products_cost << endl;
        }
        current = current->next;
    }

}
int CItems_Sale::n_of_items(unsigned int sale_id){
    CNodeItems_Sale *current = start;
    int num = 0;
    while(current!=NULL){
        if(current->item_Sale.id_sale == sale_id ){
            num++;
        }
        current = current -> next;
    }
    return num;
}
double CItems_Sale::sum_cost_items(unsigned int sale_id){
    CNodeItems_Sale *current = start;
    double total = 0;
    while(current!=NULL){
        if(current->item_Sale.id_sale == sale_id ){
            total += current->item_Sale.products_cost;
        }
        current = current -> next;
    }
    return total;
}
void CItems_Sale::deleteitemssale(unsigned int newsale_id){
    CNodeItems_Sale *current=start;
    CNodeItems_Sale *previous;

    if(start==NULL) return;
    else{
        previous=NULL;
        while(current!=NULL){
            if( current->item_Sale.id_sale == newsale_id ){
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

void CItems_Sale::salebyproduct(unsigned int product_id)const{
    CNodeItems_Sale *current = start;
    double total_sales = 0;
    int units = 0;
    if(start==NULL){
        cout << "This product has no sales." << endl;
        return;
    }
    while(current != NULL){
        if(current->item_Sale.id_product == product_id){
            total_sales += current->item_Sale.products_cost;
            units += current->item_Sale.quantity;
        }
        current = current->next;
    }

    cout << "Total Sales: " << total_sales << " euros" << endl;
    cout << "Units sold: " << units << endl;
}

void CItems_Sale::salebyproducttype(unsigned int product_type_id, CProduct productlist){

    CNodeItems_Sale *current = start;

    double total_sales = 0;
    int units = 0;
    unsigned int product_id;
    unsigned int type_id;
    if(start==NULL){
        cout << "This product has no sales." << endl;
        return;
    }
    while(current != NULL){
        product_id = current->item_Sale.id_product;
        type_id = productlist.product_type(product_id);
        if(type_id == product_type_id){
            total_sales += current->item_Sale.products_cost;
            units += current->item_Sale.quantity;
        }
        current = current->next;
    }

    cout << "Total Sales: " << total_sales << " euros" << endl;
    cout << "Units sold: " << units << endl;
}

bool CItems_Sale::productsold(unsigned int id) const{
    CNodeItems_Sale *current = start;

    if (start == NULL) return 0;
    while (current != NULL) {
        if (current->item_Sale.id_product == id) return true;
        current = current->next;
    }
    return false;
}

vector<sItems_Sale> CItems_Sale::getlistitems_sale(unsigned int sale_id){
    vector<sItems_Sale> returnList;

    CNodeItems_Sale *current = start;

    if(start==NULL) return returnList;
    while(current != NULL){
        if(current->item_Sale.id_sale == sale_id){
            returnList.push_back(current->item_Sale);
        }
        current = current->next;
    }
    return returnList;
}
void CItems_Sale::salerevenue_byproduct(unsigned int input_product_id, CProduct_Type typeslist, CProduct productlist){
    CNodeItems_Sale *current = start;

    if(start==NULL){
        cout << "No sales registered for this product." << endl;
        return;
    }
    else{
        double product_revenue = 0;
        double VAT_to_pay= 0;
        double p_price;
        int p_id, p_type;
        int vat;
        while(current!=NULL){
            if(current->item_Sale.id_product == input_product_id){

                p_id = current->item_Sale.id_product;
                p_type = productlist.product_type(p_id);
                vat = typeslist.get_VAT(p_type);

                p_price = current->item_Sale.products_cost;

                product_revenue += p_price / (((double)vat+100.0f)/100.0f);

                VAT_to_pay +=  (p_price  - (p_price / (((double)vat+100.0f)/100.0f)));
            }
            current=current->next;
        }
        cout << setprecision(2) << fixed << "\nTotal revenue with VAT: " << product_revenue + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Total revenue without VAT: " << product_revenue << " euros" << endl;
        cout << setprecision(2) << fixed << "Taxes(VAT): " << VAT_to_pay << " euros " << endl;

    }

}
void CItems_Sale::salerevenue_byproducttype(unsigned int input_product_type_id, CProduct_Type typeslist, CProduct productlist){
    CNodeItems_Sale *current = start;

    if(start==NULL)
        cout << "No sales registered for this type of product." << endl;
    else{
        double product_revenue = 0;
        double VAT_to_pay= 0;
        double p_price;
        unsigned int p_id, p_type;
        int vat;
        while(current!=NULL){

            p_id = current->item_Sale.id_product;
            p_type = productlist.product_type(p_id);

            if(p_type == input_product_type_id){

                vat = typeslist.get_VAT(p_type);

                p_price = current->item_Sale.products_cost;

                product_revenue += p_price / (((double)vat+100.0f)/100.0f);

                VAT_to_pay +=  (p_price  - (p_price / (((double)vat+100.0f)/100.0f)));
            }
            current=current->next;
        }
        cout << setprecision(2) << fixed << "\nTotal revenue with VAT: " << product_revenue + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Total revenue without VAT: " << product_revenue << " euros" << endl;
        cout << setprecision(2) << fixed << "Taxes(VAT): " << VAT_to_pay << " euros " << endl;

    }

}
void CItems_Sale::salerevenue_total(CProduct_Type typeslist, CProduct productlist){
    CNodeItems_Sale *current = start;

    if(start==NULL)
        cout << "There are no sales registered." << endl;
    else{
        double total_revenue = 0;
        double VAT_to_pay= 0;
        double p_price;
        unsigned int p_id, p_type;
        int vat;
        while(current!=NULL){

            p_id = current->item_Sale.id_product;//get product id
            p_type = productlist.product_type(p_id);//get product type
            vat = typeslist.get_VAT(p_type);//get VAT of product type
            p_price = current->item_Sale.products_cost;//get cost

            total_revenue += p_price / (((double)vat+100.0f)/100.0f);//calculate total revenue without VAT
            VAT_to_pay +=  (p_price  - (p_price / (((double)vat+100.0f)/100.0f)));// calcualte total VAT

            current=current->next;
        }

        cout << setprecision(2) << fixed << "\nTotal revenue with VAT: " << total_revenue + VAT_to_pay << " euros" << endl;
        cout << setprecision(2) << fixed << "Total revenue without VAT: " << total_revenue << " euros" << endl;
        cout << setprecision(2) << fixed << "Taxes(VAT): " << VAT_to_pay << " euros " << endl;

    }

}
