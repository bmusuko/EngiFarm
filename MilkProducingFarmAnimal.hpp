#ifndef __MilkProducingFarmAnimal_HPP__
#define __MilkProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MilkProducingFarmAnimal: public FarmAnimal{
    public:
        //ctor buat set IsMilkProducing = true;
        MilkProducingFarmAnimal();
        //buat interact hewan dan buat objek milk
        virtual void respondInteract() = 0;
};

#endif
