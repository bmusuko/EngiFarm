#ifndef __SHEEP_HPP__
#define __SHEEP_HPP__

#include "MeatProducingFarmAnimal.hpp"
class Sheep : public MeatProducingFarmAnimal {
    protected:
        static int SheepAlive;
    public:
        void suara(); //cout "pukpuk"
        void respondKill(); //CowAlive-1
        static int getSheepAlive(); //return CowAlive

};
#endif