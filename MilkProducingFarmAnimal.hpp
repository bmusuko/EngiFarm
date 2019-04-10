#ifndef __MilkProducingFarmAnimal_HPP__
#define __MilkProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MilkProducingFarmAnimal: virtual public FarmAnimal{
    public:
        //buat interact hewan dan buat objek milk
        MilkProducingFarmAnimal();
        virtual FarmProduct* respondInteract() = 0;
};

#endif
