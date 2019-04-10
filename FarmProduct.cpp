#include "FarmProduct.hpp"
#include "Product.hpp"
#include <iostream>
using namespace std;

FarmProduct::FarmProduct():Product(0,"XXX"){}
FarmProduct::FarmProduct(int harga,string code):Product(harga,code){

}
