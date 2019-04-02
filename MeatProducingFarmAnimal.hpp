#ifndef __MeatProducingFarmAnimal_HPP__
#define __MeatProducingFarmAnimal_HPP__

#include"FarmAnimal.hpp"
using namespace std;


class MeatProducingFarmAnimal: public FarmAnimal{
    public:
        //buat kill hewan dan buat objek meat
    	MeatProducingFarmAnimal(int x, int y,int lapar);
		virtual FarmProduct* respondKill() = 0;
};

#endif
