#ifndef __MeatProducingFarmAnimal_HPP__
#define __MeatProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MeatProducingFarmAnimal: public FarmAnimal{
    public:
        //ctor buat set IsMeatProducing = true;
        MeatProducingFarmAnimal();
        //buat kill hewan dan buat objek meat
        virtual void respondKill() = 0;
};

#endif
