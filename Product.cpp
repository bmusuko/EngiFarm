#include "Product.hpp"
using namespace std;

Product::Product(int harga) {
    this->harga = harga;
}

int Product::getHarga() const {
    return this->harga;
}

void Product::setHarga(int h) {
    this->harga = h;
}

