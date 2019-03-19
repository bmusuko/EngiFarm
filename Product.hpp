#ifndef __PRODUCT_H__
#define __PRODUCT_H__
//#include <iostream>
using namespace std;

class Product {
    protected:
        int harga; //harga nya product bisa beda-beda
        int nProduct;


    public:
        //ctor
        //Product();

        //ctor with parameter
        Product(int harga);

        //cctor
        //Product();
        
        //dtor
        //~Product();

        //method
        void tambahProduk(); //n_product ++
        void kurangProduk(); //n_product --
        int getHarga() const;
        // int getnProduct() const;
        void setHarga(int harga);
        

};





#endif