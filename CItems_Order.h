#ifndef CITEMS_ORDER_H
#define CITEMS_ORDER_H
#include <vector>

class CItems_Order;

struct sItems_Order{
    unsigned int order_id;
    unsigned int product_id;
    int quantity;
    double discount_beforeVAT;
    double total_cost_afterVAT;
};

class CNodeItems_Order{
    struct sItems_Order item_order;
    CNodeItems_Order *next;
    friend class CItems_Order;
};

class CItems_Order{
private:
    CNodeItems_Order *start, *end;
public:
    CItems_Order(void);
    ~CItems_Order(void);
    bool product_order(unsigned int product_id_search) const;
    void show_items_order(unsigned int order_id_search) const;
    std::vector<sItems_Order> getlistitems_order(unsigned int);
    void add_to_order(sItems_Order newitemorder);
    void show_items_order_details(unsigned int order_id_search, unsigned int product_id_to_order, double total_cost_item_beforeVAT_afterDiscount , int VAT) const;
};

#endif // CITEMS_ORDER_H
