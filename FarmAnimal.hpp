using namespace std;
#include<iostream>
#include"FarmProduct.hpp"


#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__


class FarmAnimal{
	protected:
		int lapar; //mati saat lapar = -5
		bool hasilProduct;
		int x;
		int y;
		int lapar_max;
	public:
		FarmAnimal();
		FarmAnimal(int x,int y,int lapar);
		virtual void suara() = 0;

		void TryMove(int &x,int &y);
		void move(int x,int y);
		void eat();
		int getLapar() const;
		bool getHasilProduct() const;
		void setLapar(int lapar);
		void setHasilProduct(bool hasilProduct);
		int getX() const;
		int getY() const;
		bool isLapar() const;
};

#endif

