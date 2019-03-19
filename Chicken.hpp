#ifndef __CHICKEN_HPP__
#define __CHICKEN_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

class Chicken : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int ChickenAlive;
    public:
    	Chicken();
    	~Chicken();
        void suara(); //cout "ptok ptok"
        void respondInteract(); // call tambah ChickenEgg
        void respondKill(); //ChickenAlive-1
        string getTipeFarmAnimal();
        static int getChickenAlive(); //return ChickenAlive
};
#endif