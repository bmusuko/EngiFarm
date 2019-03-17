#ifndef __CHICKEN_HPP__
#define __CHICKEN_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

class Chicken : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int ChickenAlive;
    public:
        void suara(); //cout
        void respondInteract(); // call tambah egg
        void respondKill(); //ChickenAlive-1
        static int getChickenAlive(); //return ChickenAlive
};
#endif