using namespace std;

#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__


class FarmAnimal{
	protected:
		
		int lapar; //mati saat lapar = -5
		bool hasilProduct;
		bool isMeatProducing = false;
		bool isMilkProducing = false;
		bool isEggProcducing = false;
		
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
		void gerakFarmAnimal();
};

#endif