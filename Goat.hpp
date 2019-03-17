#ifndef __GOAT_HPP__
#define __GOAT_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
class Goat : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int GoatAlive;
    public:
        void suara(); //cout "pukpuk"
        void respondInteract(); // call tambah milk
        void respondKill(); //CowAlive-1
        static int getGoatAlive(); //return CowAlive

};
#endif