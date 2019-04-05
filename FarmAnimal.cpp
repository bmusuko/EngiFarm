using namespace std;
#include"FarmAnimal.hpp"
#include <cstdlib>

#include <ctime>

FarmAnimal::FarmAnimal(){}

FarmAnimal::FarmAnimal(int x,int y,int lapar_max){
	hasilProduct = false;
	this-> x = x;
	this-> y = y;
	this-> lapar_max = lapar_max;
	this->lapar = lapar_max;
}

void FarmAnimal::TryMove(int &x,int &y){
	srand(time(NULL));
	int random = rand()%4;
	if(random == 0){
		x -= 1;
	} else if (random == 1){
		x += 1;
	} else if (random == 2){
		y += 1;
	} else if (random == 3){
		y -=1;
	}
}
void FarmAnimal::move(int x,int y){
	this->x = x;
	this->y = y;
}

void FarmAnimal::eat(){
	lapar = lapar_max;
	hasilProduct = true;

}

int FarmAnimal::getLapar() const{
    return lapar;
}
bool FarmAnimal::getHasilProduct() const{
    return hasilProduct;
}
void FarmAnimal::setLapar(int lapar){
    this->lapar = lapar;
}
void FarmAnimal::setHasilProduct(bool hasilProduct){
    this->hasilProduct = hasilProduct;
}

int FarmAnimal::getX() const{
	return this->x;
}

int FarmAnimal::getY() const{
	return this->y;
}

bool FarmAnimal::isLapar() const{
	return lapar <= 0;
}