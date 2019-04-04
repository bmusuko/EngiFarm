#ifndef __PRODUCT_H__
#define __PRODUCT_H__
//#include <iostream>
using namespace std;

class Product {
    protected:
        int harga; //harga nya product bisa beda-beda
        //int nProduct;


    public:
        //ctor with parameter
        Product(int harga);

        //method
        int getHarga() const;
        // int getnProduct() const;
        void setHarga(int h);
        //bool operator ==(Product product1, Product product2);
        

};





#endif