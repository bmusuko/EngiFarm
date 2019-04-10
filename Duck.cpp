#include "Duck.hpp"
#include "DuckEgg.hpp"
#include "DuckMeat.hpp"
#include <iostream>
using namespace std;

int Duck::DuckAlive = 0;

Duck::Duck(int x,int y):FarmAnimal(x,y,6) {
    DuckAlive++;
}
Duck::~Duck() {
    DuckAlive--;
}
void Duck::suara() {
    cout<<"ptok ptok"<<endl;
}
FarmProduct* Duck::respondInteract() {
    setHasilProduct(false);
    static DuckEgg G ;
    return &G;
}
FarmProduct* Duck::respondKill() {
    delete this;
    static DuckMeat C;
    return &C;
}
int Duck::getDuckAlive() {
    return DuckAlive;
}