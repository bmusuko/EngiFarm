using namespace std;

#ifndef __FARMANIMAL_HPP__
#define __FARMANIMAL_HPP__

class FarmAnimal{
	protected :
		int lapar;
		bool hasilProduct;
		int tickSebelumMati;
	public :
		FarmAnimal();
		~FarmAnimal();
		virtual void suara() = 0;
		void move();
		void eat();
		int getLapar() const;
		bool getHasilProduct() const;
		void setLapar(int lapar);
		void setHasilProduct(bool hasilProduct);
		void gerakFarmAnimal();
};

#endif