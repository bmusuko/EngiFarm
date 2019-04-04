#include "Goat.hpp"
#include "GoatMilk.hpp"
#include "GoatMeat.hpp"
#include <iostream>
using namespace std;

int Goat::GoatAlive = 0;

Goat::Goat(int x,int y):FarmAnimal(x,y,14) {
    GoatAlive++;
}
Goat::~Goat() {
    GoatAlive--;
}
void Goat::suara() {
    cout<<"mbee mbee"<<endl;
}
FarmProduct* Goat::respondInteract() {
    setHasilProduct(false);
    static GoatMilk G;
    return &G;
}
FarmProduct* Goat::respondKill() {
    delete this;
    static GoatMeat C;
    return &C;
}
int Goat::getGoatAlive() {
    return GoatAlive;
}