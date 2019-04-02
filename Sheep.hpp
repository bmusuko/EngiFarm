#ifndef __SHEEP_HPP__
#define __SHEEP_HPP__

#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"
class Sheep : public MeatProducingFarmAnimal {
    protected:
        static int SheepAlive;
    public:
    	Sheep();
    	~Sheep();
        void suara(); //cout "mbee mbee"
        FarmProduct respondKill(); //SheepAlive-1
        string getTipeFarmAnimal();
        static int getSheepAlive(); //return SheepAlive

};
#endif