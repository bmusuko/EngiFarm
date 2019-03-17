#ifndef __PRODUCT_H__
#define __PRODUCT_H__
//#include <iostream>
using namespace std;

class Product {
    protected:
        int harga; //harga nya product bisa beda-beda



    public:
        //ctor
        Product();

        //ctor with parameter
        //Product();

        //cctor
        //Product();
        
        //dtor
        //~Product();

        //method
        int getHarga() const;
        void setHarga(int harga);
};





#endif