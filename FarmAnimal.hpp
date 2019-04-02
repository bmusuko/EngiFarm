using namespace std;
#include<iostream>
#include"Matriks.hpp"
#include"FarmProduct.hpp"


#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__


class FarmAnimal{
	protected:
		
		int lapar; //mati saat lapar = -5
		bool hasilProduct;
		int x;
		int y;
	public:
		FarmAnimal();
		
		virtual void suara() = 0;


		void TryMove(int &x,int &y);
		void move(int x,int y);
		void eat();
		int getLapar() const;
		bool getHasilProduct() const;
		void setLapar(int lapar);
		void setHasilProduct(bool hasilProduct);
};

