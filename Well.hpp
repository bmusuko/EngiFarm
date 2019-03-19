#ifndef __WELL_HPP__
#define __WELL_HPP__

#include "Facility.hpp"

class Well : public Facility{
    private:
        
    public:
        //Konstuktor
        Well(int X, int Y): Facility(X,Y,1) {};


        void use();
};

#endif