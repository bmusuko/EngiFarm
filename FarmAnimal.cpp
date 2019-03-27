using namespace std;
#include"FarmAnimal.hpp"

FarmAnimal::FarmAnimal(){
	hasilProduct = false;
    isMeatProducing = false;
    isMilkProducing = false;
	isEggProcducing = false;
}
void move();
void eat();
int getLapar() const{
    return lapar;
}
bool getHasilProduct() const{
    return hasilProduct;
}
void FarmAnimal::setLapar(int lapar){
    this->lapar = lapar;
}
void setHasilProduct(bool hasilProduct){
    this->hasilProduct = hasilProduct;
}