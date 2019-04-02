#include <iostream>
#include "FarmProduct.hpp"
#include "SideProduct.hpp"
using namespace std;

SideProduct::SideProduct() : Product(harga){
    this->size = 0;
    this->dataFarm = new FarmProduct[size];
}

SideProduct::SideProduct(FarmProduct *arrFarm, int size) : Product(harga){
    this->size = size;
    this->dataFarm = new FarmProduct[size];

    for (int i = 0; i < size; i++) {
        this->dataFarm[i] = arrFarm[i];
    }
}


