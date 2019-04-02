#ifndef __EggProducingFarmAnimal_HPP__
#define __EggProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class EggProducingFarmAnimal: public FarmAnimal{
    public: 
        //ctor buat set IsEggProducing = true;
        //buat kill hewan dan buat objek egg
	    virtual FarmProduct respondInteract() = 0;
};

#endif