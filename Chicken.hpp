#ifndef __CHICKEN_HPP__
#define __CHICKEN_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"

class Chicken : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int ChickenAlive;
    public:
    	Chicken();
    	~Chicken();
        void suara(); //cout "ptok ptok"
        FarmProduct respondInteract(); // call tambah ChickenEgg
        FarmProduct respondKill(); //ChickenAlive-1
        string getTipeFarmAnimal();
        static int getChickenAlive(); //return ChickenAlive
};
#endif