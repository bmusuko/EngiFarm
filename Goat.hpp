#ifndef __GOAT_HPP__
#define __GOAT_HPP__

#include "MilkProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
class Goat : public MilkProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int GoatAlive;
    public:
    	Goat();
    	~Goat();
        void suara(); //cout "mbee mbee"
        void respondInteract(); // call tambah GoatMilk
        void respondKill(); //GoatAlive-1
        string getTipeFarmAnimal();
        static int getGoatAlive(); //return GoatAlive

};
#endif