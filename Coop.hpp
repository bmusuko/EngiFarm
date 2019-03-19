#ifndef __COOP_HPP__
#define __COOP_HPP__

#include "Land.hpp"

class Coop : public Land{
    private:
        
    public:
        //Konstruktor
        Coop(int X, int Y, bool grass, bool object) : Land (X,Y,grass,object,1) {};
};

#endif