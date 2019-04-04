#include "Mixer.hpp"
#include <iostream>
#include <typeinfo>
using namespace std;

Mixer::Mixer(int X, int Y) : Facility(X,Y) {}

void Mixer::use(LinkedList<Product*> LP,int &money, int &water, string masukan) {
    int choose;
    bool isInventAvail;

    cout<<"Bahan yang ingin dibuat : 1. Martabak"<<endl; 
    cout<<"                          2. Cheese"<<endl;
    cout<<"                          3. Beef Rolade"<<endl;
    cin>>choose;
    
    ChickenEgg CE;
    DuckEgg DE;
    CowMilk CMi;
    GoatMilk GM;
    CowMeat CMe;
    
    if (choose==1) {  //Martabak
        isInventAvailable(LP, &isInventAvail,&CE,&DE);
        if (isInventAvail) {
            createMartabak(LP);
        }
    }
    else if (choose==2)  {//Cheese
    
        isInventAvailable(LP, &isInventAvail,&CMi, &GM);
        if (isInventAvail) {
            createCheese(LP);
        }
    }
    else { //Beef Rolade
        isInventAvailable(LP, &isInventAvail,&CMe,&CE);
        if (isInventAvail) {
            createBeefRolade(LP);
        }
    }
}

void Mixer::isInventAvailable(LinkedList<Product*> LP,bool *isAvail, Product* P1, Product* P2) {
    bool foundP1 = false, foundP2 = false;
    *isAvail = false;
    for (int i=0;i<LP.size;i++) {
        if (!foundP1) {
            if (typeid(LP.get(i)) == typeid(*P1)) {
                foundP1 = true; continue;
            }
        }
        if (!foundP2) {
            if (typeid(LP.get(i)) == typeid(*P2)) {
                foundP2 = true;
            }
        }
        if (foundP1 && foundP2) {
            *isAvail = true; break;
        }
    }
    if (*isAvail) {
        LP.remove(P1);
        LP.remove(P2);
    }
}

void Mixer::createMartabak(LinkedList<Product*> LP){
    Martabak M;
    LP.add(&M);
}
        
void Mixer::createCheese(LinkedList<Product*> LP){
    Cheese C;
    LP.add(&C);
}
        
void Mixer::createBeefRolade(LinkedList<Product*> LP){
    BeefRolade BR;
    LP.add(&BR);
}
