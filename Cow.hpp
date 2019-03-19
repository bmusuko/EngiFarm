#ifndef __COW_HPP__
#define __COW_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
class Cow : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int CowAlive;
    public:
    	Cow();
    	~Cow();
        void suara(); //cout "mooo moo"
        void respondInteract(); // call tambah Cowmilk
        void respondKill(); //CowAlive-1
        string getTipeFarmAnimal();
        static int getCowAlive(); //return CowAlive

};
#endif