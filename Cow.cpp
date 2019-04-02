#include "Cow.hpp"
#include "CowMilk.hpp"
#include "CowMeat.hpp"
#include <iostream>
using namespace std;

int Cow::CowAlive = 0;

Cow::Cow(int x,int y):FarmAnimal(x,y,17) {
    lapar_max = 17;
    CowAlive++;
}
Cow::~Cow() {
    CowAlive--;
}
void Cow::suara() {
    cout<<"moo moo"<<endl;
}
FarmProduct* Cow::respondInteract() {
    setHasilProduct(false);
    CowMilk G;
    return &G;
}
FarmProduct* Cow::respondKill() {
    ~Cow();
    CowMeat C;
    return &C;
}
int Cow::getCowAlive() {
    return CowAlive;
}