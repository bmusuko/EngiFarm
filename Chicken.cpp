#include "Chicken.hpp"
#include "ChickenEgg.hpp"
#include "ChickenMeat.hpp"
#include <iostream>
using namespace std;

int Chicken::ChickenAlive = 0;

Chicken::Chicken(int x,int y):FarmAnimal(x,y,5){
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
    static ChickenEgg G;
    return &G;
}
FarmProduct* Chicken::respondKill() {
    delete this;
    static ChickenMeat C;
    return &C;
}
int Chicken::getChickenAlive() {
    return ChickenAlive;
}