#ifndef __SIDEPRODUCT_H__
#define __SIDEPRODUCT_H__
#include "Product.hpp"
#include "FarmProduct.hpp"

class SideProduct : public Product {
    private:
        FarmProduct *dataFarm;
        int size;
    
    public:
        // ctor
        SideProduct();
        // ctor parameter
        SideProduct(FarmProduct *arrFarm, int size);


};

#endif