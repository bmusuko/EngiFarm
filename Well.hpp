#ifndef __WELL_HPP__
#define __WELL_HPP__

#include "Facility.hpp"

class Well : public Facility{
    private:
        
    public:
        //Konstuktor
        Well(int X, int Y);

        void use(LinkedList<Product*> &LP,int &money, int &water, string masukan);
        void use(int& waiter);
};

#endif