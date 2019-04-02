#include "Cow.hpp"
#include "CowMilk.hpp"
#include "CowMeat.hpp"
#include <iostream>
using namespace std;

int Cow::CowAlive = 0;

Cow::Cow() {
    CowAlive++;
}
Cow::~Cow() {
    CowAlive--;
}
void Cow::suara() {
    cout<<"moo moo"<<endl;
}
FarmProduct Cow::respondInteract() {
    if (getHasilProduct()) {
        setHasilProduct(false);
        CowMilk G;
        return G;
    }
    else {
        //throw something
        throw new exception();
    }
}
FarmProduct Cow::respondKill() {
    ~Cow();
    CowMeat C;
    return C;
}
int Cow::getCowAlive() {
    return CowAlive;
}