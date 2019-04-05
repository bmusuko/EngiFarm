#include "SheepMeat.hpp"
#include "Product.hpp"
#include "FarmProduct.hpp"
#include <iostream>

using namespace std;

SheepMeat::SheepMeat() : FarmProduct(120000,"SheepMeat"){
    harga = 120000;
}