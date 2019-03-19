#ifndef __BARN_HPP__
#define __BARN_HPP__

#include "Land.hpp"

class Barn : public Land{
    private:
        
    public:
        //Konstruktor
        Barn(int X, int Y, bool grass, bool object) : Land (X,Y,grass,object,3) {};
};

#endif