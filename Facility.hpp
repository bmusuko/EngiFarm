#ifndef __FACILITY_HPP__
#define __FACILITY_HPP__

#include "Cell.hpp"
#include "Player.hpp"

class Facility: public Cell{
    public:
        //Konstruktor
        Facility(int X, int Y);


        //Fungsi virtual
        virtual void use(Player * P) = 0;

};

#endif