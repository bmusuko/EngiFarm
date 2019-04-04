#include "Product.hpp"
#include "FarmProduct.hpp"
#include "CowMilk.hpp"
#include <iostream>

using namespace std;

CowMilk::CowMilk() : FarmProduct(){
    harga = 20000;
}