using namespace std;
#include<iostream>

#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__


class FarmAnimal{
	protected:
		
		int lapar; //mati saat lapar = -5
		bool hasilProduct;
		bool MeatProducing;
		bool MilkProducing;
		bool EggProcducing;
		int x;
		int y;
	public:
		FarmAnimal();
		
		virtual void suara() = 0;
		virtual string getTipeFarmAnimal() = 0;

		void move();
		void eat();
		int getLapar() const;
		bool getHasilProduct() const;
		void setLapar(int lapar);
		void setHasilProduct(bool hasilProduct);
		void isMeatProducing() const;
		void isMilkProducing() const;
		void isEggProducing() const;
};

#endif