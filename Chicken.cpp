#include "Chicken.hpp"
#include "ChickenEgg.hpp"
#include "ChickenMeat.hpp"
#include <iostream>
using namespace std;

int Chicken::ChickenAlive = 0;

Chicken::Chicken(int x,int y):EggProducingFarmAnimal(x,y,5){
    FarmAnimal::lapar_max =5;
    ChickenAlive++;
}
Chicken::~Chicken() {
    ChickenAlive--;
}
void Chicken::suara() {
    cout<<"ptok ptok"<<endl;
}
FarmProduct* Chicken::respondInteract() {
    FarmAnimal::setHasilProduct(false);
    ChickenEgg G;
    return &G;
FarmProduct* Chicken::respondKill() {
    ~Chicken();
    ChickenMeat C;
    return &C;
}
int Chicken::getChickenAlive() {
    return ChickenAlive;
}