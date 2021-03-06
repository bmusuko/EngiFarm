#ifndef __FACILITY_HPP__
#define __FACILITY_HPP__

#include "Cell.hpp"
#include "LinkedList.hpp"
#include "Product.hpp"

class Facility: public Cell{
    public:
        //Konstruktor
        Facility(int X, int Y);

        //Fungsi virtual
        virtual void use(LinkedList<Product*> &LP,int &money, int &water, string masukan) = 0;
        bool getIsGrassExist() const;
        bool getIsObjectExist () const;
        void setIsGrassExist(bool grass);
        void setIsObjectExist(bool object);

};

#endif