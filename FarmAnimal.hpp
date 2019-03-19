using namespace std;

#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__


class FarmAnimal{
	protected:
		
		int lapar; //mati saat lapar = -5
		bool hasilProduct;
		
	public:
		FarmAnimal();
		
		virtual void suara() = 0;
		virtual void move() = 0;
		virtual string getTipeProducingAnimal() = 0;
		virtual string getTipeFarmAnimal() = 0;


		void eat();
		int getLapar() const;
		bool getHasilProduct() const;
		void setLapar(int lapar);
		void setHasilProduct(bool hasilProduct);
		void gerakFarmAnimal();
};

#endif