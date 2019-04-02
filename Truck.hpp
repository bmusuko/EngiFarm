#ifndef __TRUCK_HPP__
#define __TRUCK_HPP__

#include "Facility.hpp"

class Truck : public Facility{
    private:
        
    public:
        //Konstuktor
        Truck(int X, int Y);

        void use(Player * P);
};

#endif