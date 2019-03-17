#ifndef __COW_HPP__
#define __COW_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
class Cow : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int CowAlive;
    public:
        void suara(); //cout "pukpuk"
        void respondInteract(); // call tambah milk
        void respondKill(); //CowAlive-1
        static int getCowAlive(); //return CowAlive

};
#endif