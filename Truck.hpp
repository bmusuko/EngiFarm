#ifndef __TRUCK_HPP__
#define __TRUCK_HPP__

#include "Facility.hpp"

class Truck : public Facility{
    private:
        
    public:
        //Konstuktor
        Truck(int X, int Y): Facility(X,Y,3) {};

        void use();
};

#endif