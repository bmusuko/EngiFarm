#ifndef __DUCK_HPP__
#define __DUCK_HPP__

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

class Duck : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    protected:
        static int DuckAlive;
    public:
    	Duck();
    	~Duck();
        void suara(); //cout "kwek kwek"
        void respondInteract(); // call tambah DuckEgg
        void getTipeFarmAnimal();
        string respondKill(); //DuckAlive-1
        static int getDuckAlive(); //return DuckAlive
};
#endif