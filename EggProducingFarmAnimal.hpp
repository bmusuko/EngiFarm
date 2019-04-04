#ifndef __EggProducingFarmAnimal_HPP__
#define __EggProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;
#include "FarmProduct.hpp"

class EggProducingFarmAnimal: public FarmAnimal{
    public: 
        //ctor buat set IsEggProducing = true;
        //buat kill hewan dan buat objek egg
        EggProducingFarmAnimal(int x,int y,int lapar);
	    virtual FarmProduct* respondInteract() = 0;
};

#endif