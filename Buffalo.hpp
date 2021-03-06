#ifndef __BUFFALO_HPP__
#define __BUFFALO_HPP__

#include "MeatProducingFarmAnimal.hpp"
#include "FarmProduct.hpp"

class Buffalo : public MeatProducingFarmAnimal{
	protected:
		static int BuffaloAlive;
	public:
		Buffalo(int x,int y);
		~Buffalo();
		void suara(); //cout "pukpuk"
		FarmProduct* respondKill(); //BuffaloAlive-1
		string getTipeFarmAnimal();
		static int getBuffaloAlive(); //return BuffaloAlive
};

#endif