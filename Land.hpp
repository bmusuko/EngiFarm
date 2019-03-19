#ifndef __LAND_HPP__
#define __LAND_HPP__
#include "Cell.hpp"

class Land: public Cell{
    protected:
        bool isObjectExist; //Boolean untuk mengecek apakah ada player atau objek lainnya pada petak tersebut
        bool isGrassExist;  //Boolean untuk mengecek apakah ada rumput atau tidak
        int landType;   //1 coop, 2 grassland, 3 barn
    public:
        //Konstruktor
        Land(int X, int Y, bool grass, bool object, int type) : Cell (X,Y) {};

        //Setter & Getter
        bool getIsGrassExist() const;
        bool getIsObjectExist () const;
        int getLandType() const;
        void setIsGrassExist(bool grass);
        void setIsObjectExist(bool object);

};

#endif