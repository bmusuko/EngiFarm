#ifndef __LAND_HPP__
#define __LAND_HPP__
#include "Cell.hpp"

class Land: public Cell{
    protected:
        bool isObjectExist; //Boolean untuk mengecek apakah ada player atau objek lainnya pada petak tersebut
        bool isGrassExist;  //Boolean untuk mengecek apakah ada rumput atau tidak
        bool coop;   //1 coop, 2 grassland, 3 barn
        bool grassland;
        bool barn;
    public:
        //Konstruktor
        Land(int X, int Y, bool grass, bool object, bool coop,bool grassland,bool barn);
        //Setter & Getter
        bool getIsGrassExist() const;
        bool getIsObjectExist () const;
        int getLandType() const;
        void setIsGrassExist(bool grass);
        void setIsObjectExist(bool object);
        void isCoop() const;
        void isGrassLand() const;
        void isBarn() const;

};

#endif