#ifndef __FARMPRODUCT_H__
#define __FARMPRODUCT_H__
#include "Product.hpp"

class FarmProduct : public Product {
    public:
    //     //ctor
    	FarmProduct();
        FarmProduct(int harga,string code);
};



#endif