#ifndef __EggProducingFarmAnimal_HPP__
#define __EggProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class EggProducingFarmAnimal: public FarmAnimal{
    public: 
       void move();
	   virtual void respondInteract() = 0;
};

#endif