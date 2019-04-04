#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"

class Duck : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int DuckAlive;
    public:
    	Duck(int x,int y);
    	~Duck();
        void suara(); //cout "kwek kwek"
        FarmProduct* respondInteract(); // call tambah DuckEgg
        FarmProduct* respondKill();
        string getTipeFarmAnimal();
        static int getDuckAlive(); //return DuckAlive
};
#endif