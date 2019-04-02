#ifndef __COW_HPP__
#define __COW_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"
class Cow : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int CowAlive;
    public:
    	Cow(int x,int y);
    	~Cow();
        void suara(); //cout "mooo moo"
        FarmProduct* respondInteract(); // call tambah Cowmilk
        FarmProduct* respondKill(); //CowAlive-1
        string getTipeFarmAnimal();
        static int getCowAlive(); //return CowAlive

};
#endif