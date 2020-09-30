#ifndef CSUPPLIERS_H
#define CSUPPLIERS_H

class CSuppliers;

struct sSuppliers{
    unsigned int supplier_id;
    char supplier_name[100];
    char supplier_address[100];
    int supplier_contact;
};

class CNodeSuppliers{
    struct sSuppliers supplier;
    CNodeSuppliers *next;
    friend class CSuppliers;
};

class CSuppliers{
private:
    CNodeSuppliers *start, *end;
public:
    CSuppliers(void);
    ~CSuppliers(void);
    void insertsupplier(sSuppliers);
    bool id_exists(unsigned int) const;
    void showssupplier(unsigned int) const;
    void editsupplier_name(char [], unsigned int);
    void editsupplier_address(char [], unsigned int);
    void editsupplier_contact(unsigned int , unsigned int);
    void all_suppliers(void) const;
    void deletesupplier(unsigned int);
};

#endif // CSUPPLIERS_H
