#ifndef PRODUCT_H
#define PRODUCT_H
#include <vector>
#include "CItems_Sale.h"
#include "CItems_Order.h"
#include "CProduct_Type.h"

class CProduct;


struct sItems_Sale;

struct sProduct{
    unsigned int product_id;
    char product_name[100];
    char product_brand[50];
    unsigned int product_type;
    double product_price; //c/iva incluido 23%
    int product_stock, product_min_stock, product_max_stock;
};

class CNodeProduct{
//private:  // é indiferente estar ou não comentado
    struct sProduct product;
    CNodeProduct *next;
    friend class CProduct;
};

class CProduct{
private:
    CNodeProduct *start, *end;
public:
    CProduct(void);
    ~CProduct(void);
    void showsproduct(int) const;
    void insertproduct(sProduct );
    int seek_index(unsigned int)const;
    void all_products(void) const;
    void editproduct(sProduct , unsigned int);
    void deleteproduct(unsigned int);
    void showsproduct_byname(char soughtname[]) const;
    bool id_exists(unsigned int)const;
    double get_price(unsigned int )const;
    void showsproduct_byid(unsigned int ) const;
    void editproduct_name(char [], unsigned int);
    void editproduct_brand(char [], unsigned int);
    void editproduct_type(unsigned int , unsigned int);
    void editproduct_price(double newprice, unsigned int);
    void editproduct_min_max_stock(int , int , unsigned int );
    bool typeassociated(unsigned int) const;
    void showproducts_bytype(unsigned int) const;
    int get_stock(unsigned int)const;   
    void updatestocko(std::vector<sItems_Order> itemsinorderList );
    void updatestocks(std::vector<sItems_Sale> saleList );
    std::vector<sProduct> stock_below_min();
    std::vector<sProduct> stock_below_min_type(unsigned int input_type_id);
    unsigned int product_type(unsigned int product_id_search) const;
    void inventory_value_byname(char soughtname[], CProduct_Type typeslist) const;
    void inventory_value_bytype(unsigned int soughttype, CProduct_Type typeslist) const;
    void inventory_value(CProduct_Type typeslist) const;
};

#endif // PRODUCT_H
