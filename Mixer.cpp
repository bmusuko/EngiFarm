#include "Mixer.hpp"
#include "ChickenEgg.hpp"
#include "DuckEgg.hpp"
#include "CowMilk.hpp"
#include "CowMeat.hpp"
#include "GoatMilk.hpp"
#include <iostream>
#include <typeinfo>
using namespace std;

Mixer::Mixer(int X, int Y) : Facility(X,Y) {}

void Mixer::use(LinkedList<Product> LP) {
    int choose;
    bool isInventAvail;

    cout<<"Bahan yang ingin dibuat : 1. Martabak"<<endl; 
    cout<<"                          2. Cheese"<<endl;
    cout<<"                          3. Beef Rolade"<<endl;
    cin>>choose;
    
    switch(choose) {
        case 1 : //Martabak
            ChickenEgg CE();
            DuckEgg DE();
            isInventAvailable(LP, &isInventAvail,CE,DE);
            if (isInventAvail) {
                createMartabak(LP);
            }
            break;
        case 2 : //Cheese
            CowMilk CM();
            GoatMilk GM();
            isInventAvailable(LP, &isInventAvail,CM, GM);
            if (isInventAvail) {
                createCheese(LP);
            }
            break;
        default : //Beef Rolade
            CowMeat CM();
            ChickenEgg CE();
            isInventAvailable(LP, &isInventAvail,CM,CE);
            if (isInventAvail) {
                createBeefRolade(LP);
            }
    }
}

void Mixer::isInventAvailable(LinkedList<Product> LP,bool *isAvail, Product P1, Product P2){
    bool foundP1 = false, foundP2 = false;
    int i, idx1=0 , idx2 = 0;
    *isAvail = false;

    for (i=0;i<LP.size;i++) {
        if (!foundP1) {
            if (typeid(LP.get(i)) == typeid(P1)) {
                idx1 = i;
                foundP1 = true;
                continue;
            }
        }
        if (!foundP2) {
            if (typeid(LP.get(i)) == typeid(P2)) {
                idx2 = i;
                foundP2 = true;
            }
        }
        if (foundP1 && foundP2) {
            *isAvail = true;
            break;
        }
    }

    if (*isAvail) {
        LP.remove(&P1);
        LP.remove(&P2);
    }
}

void Mixer::createMartabak(LinkedList<Product> LP){
    Martabak M();
    LP.add(&M);
}
        
void Mixer::createCheese(LinkedList<Product> LP){
    Cheese C();
    LP.add(&C);
}
        
void Mixer::createBeefRolade(LinkedList<Product> LP){
    BeefRolade BR();
    LP.add(&BR);
}