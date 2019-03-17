#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

class Duck : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int DuckAlive;
    public:
        void suara(); //cout
        void respondInteract(); // call tambah egg
        void respondKill(); //ChickenAlive-1
        static int getDuckAlive(); //return DuckAlive
};
#endif