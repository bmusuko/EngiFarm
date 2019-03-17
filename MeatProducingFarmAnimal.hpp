#ifndef __MeatProducingFarmAnimal_HPP__
#define __MeatProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MeatProducingFarmAnimal: public FarmAnimal{
    public:
        void move();
        virtual void respondKill() = 0;
};

#endif
