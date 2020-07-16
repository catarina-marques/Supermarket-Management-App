#ifndef CPRODUCT_TYPE_H
#define CPRODUCT_TYPE_H

class CProduct_Type;

struct sProduct_Type{
    unsigned int type_id;
    char product_type_name[100];
    int product_type_VAT;
};

class CNodeProduct_Type{
    struct sProduct_Type type;
    CNodeProduct_Type *next;
    friend class CProduct_Type;
};

class CProduct_Type{
private:
    CNodeProduct_Type *start, *end;
public:
    CProduct_Type(void);
    ~CProduct_Type(void);
    void addtype(sProduct_Type addedproduct);
    void edittype(sProduct_Type editedproduct, int index);
    void deletetype(unsigned int );
    int seek_index(unsigned int)const;
    void showsproducttype(unsigned int) const;
    void all_producttypes(void) const;
    void showsproducttype_byname(char soughtname[]) const;
    bool id_exists(unsigned int)const;
    int get_VAT(unsigned int type_product_to_order)const;
    void get_product_type_name(unsigned int soughttype_id)const;
};

#endif // CPRODUCT_TYPE_H
