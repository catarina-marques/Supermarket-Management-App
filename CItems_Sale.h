#ifndef CITEMS_SALE_H
#define CITEMS_SALE_H
#include "CItems_Sale.h"
#include "CProduct.h"
#include "CProduct_Type.h"
#include <vector>

class CItems_Sale;

class CProduct;
class CProduct_Type;

struct sItems_Sale{
    unsigned int id_sale;
    unsigned int id_product; // code of the product
    int quantity;//amount of items with same code
    double products_cost; //cost of that item times the amount
};

class CNodeItems_Sale{
    struct sItems_Sale item_Sale;
    CNodeItems_Sale *next;
    friend class CItems_Sale;
};

class CItems_Sale{
private:
    CNodeItems_Sale *start, *end;
public:
    CItems_Sale(void);
    ~CItems_Sale(void);
    void add_to_sale(sItems_Sale);
    void showitemsinbasket(unsigned int);
    int n_of_items(unsigned int);
    double sum_cost_items(unsigned int);
    void deleteitemssale(unsigned int);
    void salebyproduct(unsigned int)const;
    void salebyproducttype(unsigned int product_type_id, CProduct productlist);
    bool productsold(unsigned int)const;
    std::vector<sItems_Sale> getlistitems_sale(unsigned int);
    void salerevenue_byproduct(unsigned int input_product_id, CProduct_Type typeslist, CProduct productlist);
    void salerevenue_byproducttype(unsigned int input_product_type_id, CProduct_Type typeslist, CProduct productlist);
    void salerevenue_total(CProduct_Type typeslist, CProduct productlist);
};

#endif // CITEMS_SALE_H
