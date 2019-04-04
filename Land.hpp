#ifndef __LAND_HPP__
#define __LAND_HPP__
#include "Cell.hpp"

class Land: public Cell{
    protected:
        bool isObjectExist; //Boolean untuk mengecek apakah ada player atau objek lainnya pada petak tersebut
        bool isGrassExist;  //Boolean untuk mengecek apakah ada rumput atau tidak
    public:
        // Konstruktor
        Land(int X, int Y, bool grass, bool object);
        // Setter & Getter
        bool getIsGrassExist() const;
        bool getIsObjectExist () const;
        void setIsGrassExist(bool grass);
        void setIsObjectExist(bool object);
};

#endif