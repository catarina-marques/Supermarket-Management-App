#ifndef CSALE_H
#define CSALE_H
#include <iostream>
#include <ctime>

class CSale;

struct sSale{
    unsigned int id_sale;
    unsigned int n_items; // number of different products
    char date[100];
    double total_cost;//sum of every item in the list: products_cost   
};

class CNodeSale{
    struct sSale a_Sale;
    CNodeSale *next;
    friend class CSale;
};

class CSale{
private:
    CNodeSale *start, *end;
public:
    CSale(void);
    ~CSale(void);
    void createsale(sSale);
    void deletesale(sSale);
    void showsale(unsigned int) const;
    unsigned int getlastid(void) const;
    void updatesale(sSale, unsigned int);
    void allsalesstats(void)const;
    void salestimeinterval(char[11],char[11]);

};

#endif // CSALE_H
