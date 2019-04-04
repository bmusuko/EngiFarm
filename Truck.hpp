#ifndef __TRUCK_HPP__
#define __TRUCK_HPP__

#include "Facility.hpp"

class Truck : public Facility{
    private:
        int cooldown;
    public:
        //Konstuktor
        Truck(int X, int Y);

        void minCD();

        void use(LinkedList<Product> LP,int &money, int &water, string masukan);
};

#endif