#include "Goat.hpp"
#include "GoatMilk.hpp"
#include "GoatMeat.hpp"
#include <iostream>
using namespace std;

int Goat::GoatAlive = 0;

Goat::Goat() {
    GoatAlive++;
}
Goat::~Goat() {
    GoatAlive--;
}
void Goat::suara() {
    cout<<"mbee mbee"<<endl;
}
FarmProduct Goat::respondInteract() {
    if (getHasilProduct()) {
        setHasilProduct(false);
        GoatMilk G;
        return G;
    }
    else {
        //throw something
        throw new exception();
    }
}
FarmProduct Goat::respondKill() {
    ~Goat();
    GoatMeat C;
    return C;
}
int Goat::getGoatAlive() {
    return GoatAlive;
}