#ifndef __LAND_HPP__
#define __LAND_HPP__
#include "Cell.hpp"

class Land: public Cell{
    protected:
        bool isAnimalExist; //Boolean untuk mengecek apakah ada hewan atau tidak
        bool isPlayerExist; //Boolean untuk mengecek apakah ada player atau tidak
        bool isGrassExist;  //Boolean untuk mengecek apakah ada rumput atau tidak
    public:

};

#endif