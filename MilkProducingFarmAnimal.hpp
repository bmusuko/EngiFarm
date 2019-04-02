#ifndef __MilkProducingFarmAnimal_HPP__
#define __MilkProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MilkProducingFarmAnimal: public FarmAnimal{
    public:
        //buat interact hewan dan buat objek milk
        virtual FarmProduct* respondInteract() = 0;
};

#endif
