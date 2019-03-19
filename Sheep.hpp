#ifndef __SHEEP_HPP__
#define __SHEEP_HPP__

#include "MeatProducingFarmAnimal.hpp"
class Sheep : public MeatProducingFarmAnimal {
    protected:
        static int SheepAlive;
    public:
    	Sheep();
    	~Sheep();
        void suara(); //cout "mbee mbee"
        void respondKill(); //SheepAlive-1
        string getTipeFarmAnimal();
        static int getSheepAlive(); //return SheepAlive

};
#endif