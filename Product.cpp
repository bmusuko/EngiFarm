#include "Product.hpp"
using namespace std;

Product::Product(int harga,string code) {
    this->harga = harga;
    this->code = code;
}

int Product::getHarga() const {
    return this->harga;
}

void Product::setHarga(int h) {
    this->harga = h;
}

string Product::getCode(){
	return code;
}
// bool Product::operator==(Product &){
//     return (product1 == product2);
// }
    
