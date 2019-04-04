#ifndef __MeatProducingFarmAnimal_HPP__
#define __MeatProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;
#include "FarmProduct.hpp"

class MeatProducingFarmAnimal: virtual public FarmAnimal{
    public:
        //buat kill hewan dan buat objek meat
        MeatProducingFarmAnimal();
		virtual FarmProduct* respondKill() = 0;
};

#endif
