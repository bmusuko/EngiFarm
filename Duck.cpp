#include "Duck.hpp"
#include "DuckEgg.hpp"
#include "DuckMeat.hpp"
#include <iostream>
using namespace std;

int Duck::DuckAlive = 0;

Duck::Duck() {
    DuckAlive++;
}
Duck::~Duck() {
    DuckAlive--;
}
void Duck::suara() {
    cout<<"ptok ptok"<<endl;
}
FarmProduct Duck::respondInteract() {
    if (getHasilProduct()) {
        setHasilProduct(false);
        DuckEgg G ;
        return G;
    }
    else {
        //throw something
        return null;
    }
}
FarmProduct Duck::respondKill() {
    ~Duck();
    DuckMeat C;
    return C;
}
int Duck::getDuckAlive() {
    return DuckAlive;
}