#include "Chicken.hpp"
#include "ChickenEgg.hpp"
#include "ChickenMeat.hpp"
#include <iostream>
using namespace std;

int Chicken::ChickenAlive = 0;

Chicken::Chicken() {
    ChickenAlive++;
}
Chicken::~Chicken() {
    ChickenAlive--;
}
void Chicken::suara() {
    cout<<"ptok ptok"<<endl;
}
FarmProduct Chicken::respondInteract() {
    if (getHasilProduct()) {
        setHasilProduct(false);
        ChickenEgg C;
        return G;
    }
    else {
        //throw something
        throw new exception();
    }
}
FarmProduct Chicken::respondKill() {
    ~Chicken();
    ChickenMeat C;
    return C;
}
int Chicken::getChickenAlive() {
    return ChickenAlive;
}