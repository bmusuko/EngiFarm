#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include <iostream>
using namespace std;

class Product {
    protected:
        int harga; //harga nya product bisa beda-beda
        //int nProduct;
        string code;


    public:
        //ctor with parameter
        Product(int harga,string code);

        //method
        int getHarga() const;
        // int getnProduct() const;
        void setHarga(int h);
        //bool operator ==(Product product1, Product product2);
        string getCode();
        

};





#endif