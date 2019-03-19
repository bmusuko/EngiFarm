#ifndef __FACILITY_HPP__
#define __FACILITY_HPP__

#include "Cell.hpp"
#include "Player.hpp"

class Facility: public Cell{
    protected:
        int facilityType;   //1 untuk well, 2 untuk mixer, 3 untuk truck
    public:
        //Konstruktor
        Facility(int X, int Y,int type): Cell(X,Y) {};
        
        //Getter karena tidak bisa di set
        int getFacilityType() const;

        //Fungsi virtual
        virtual void use() = 0;

};

#endif