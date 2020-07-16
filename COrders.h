#ifndef CORDERS_H
#define CORDERS_H


class COrders;

struct sOrders{
    unsigned int order_id;
    unsigned int supplier_id;
    char date_order[100];
    int n_items;
    double total_cost;
    bool received;
    char date_reception[100];
};

class CNodeOrders{
    struct sOrders order;
    CNodeOrders *next;
    friend class COrders;
};

class COrders{
private:
    CNodeOrders *start, *end;
public:
    COrders(void);
    ~COrders(void);
    bool supplier_order(unsigned int supplier_id_search) const;
    bool id_exists(unsigned int order_id_search) const;
    void show_order(unsigned int order_id_search) const;
    void show_order_pending()const;
    void updatestatus(unsigned int order_id_search);
    void createorder(sOrders);
    unsigned int getlastid(void) const;
    void updateorder(sOrders neworder,unsigned int neworder_id);
};
#endif // CORDERS_H
