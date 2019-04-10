#ifndef __GOAT_HPP__
#define __GOAT_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"
class Goat : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int GoatAlive;
    public:
    	Goat(int x,int y);
    	~Goat();
        void suara(); //cout "mbee mbee"
        FarmProduct* respondInteract(); // call tambah GoatMilk
        FarmProduct* respondKill(); //GoatAlive-1
        static int getGoatAlive(); //return GoatAlive

};
#endif