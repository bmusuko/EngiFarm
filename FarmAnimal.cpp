using namespace std;
#include"FarmAnimal.hpp"
#include <cstdlib>
#include <ctime>

FarmAnimal::FarmAnimal(){
	hasilProduct = false;
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
	lapar = 10;
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