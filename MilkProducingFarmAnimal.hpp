#ifndef __MilkProducingFarmAnimal_HPP__
#define __MilkProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MilkProducingFarmAnimal: public FarmAnimal{
    public:
        void move();
        virtual void respondInteract() = 0;
};

#endif
