using namespace std;
#include"FarmAnimal.hpp"

FarmAnimal::FarmAnimal(){
	hasilProduct = false;
	MeatProducing = false;
	MilkProducing = false;
	EggProducing = false;
}
void move();
void eat(){
	
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
bool FarmAnimal::isMeatProducing() const{
	return MeatProducing;
}

bool FarmAnimal::isMilkProducing() const{
	return MilkProducing;
}

void FarmAnimal::isEggProducing() const{
	return EggProducing;
}