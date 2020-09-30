#ifndef CSUPPLIERS_PRODUCTS_H
#define CSUPPLIERS_PRODUCTS_H
#include <vector>
#include "CProduct.h"
class CSuppliers_Products;

struct sSuppliers_Products{
    unsigned int product_id;
    unsigned int supplier_id;
    double unit_cost_withoutVAT;
    int min_order_discount;
    int discount;
};

class CNodeSuppliers_Products{
    struct sSuppliers_Products supplier_product;
    CNodeSuppliers_Products *next;
    friend class CSuppliers_Products;
};

class CSuppliers_Products{
private:
    CNodeSuppliers_Products *start, *end;
public:
    CSuppliers_Products(void);
    ~CSuppliers_Products(void);
    void insertsupplier_product(sSuppliers_Products );
    void all_products_supplier(unsigned int) const;
    bool productordered(unsigned int ) const;
    void editsupplier_product_supplier(unsigned int, unsigned int);
    void editsupplier_product_unitcost(double, unsigned int);
    void editsupplier_product_min_order(int, unsigned int);
    void editsupplier_product_discount(int, unsigned int);
    void showssupplier_product(unsigned int) const;
    void deletesupplier_product(unsigned int supplier_id_search);
    bool id_exists(unsigned int product_id_search) const;
    std::vector<sSuppliers_Products> checkcostefficiency(std::vector<sProduct> lowstockList );
    unsigned int get_best_supplier( unsigned int product);
    int get_discount(unsigned int supplier_id_to_order_from, unsigned int product_id_to_order, int quantity_to_order);
    double get_cost_without_VAT(unsigned int supplier_id_to_order_from, unsigned int product_id_to_order) const;
};

#endif // CSUPPLIERS_PRODUCTS_H
