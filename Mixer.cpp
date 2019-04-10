#include "Mixer.hpp"
#include <iostream>
#include <typeinfo>
using namespace std;

Mixer::Mixer(int X, int Y) : Facility(X,Y) {}

void Mixer::use(LinkedList<Product*> &LP,int &money, int &water, string masukan) {
    int choose;
    bool isInventAvail;

    cout<<"Bahan yang ingin dibuat : 1. Martabak"<<endl; 
    cout<<"                          2. Cheese"<<endl;
    cout<<"                          3. Beef Rolade"<<endl;
    cout<<"Masukan pilihan anda : ";
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

void Mixer::isInventAvailable(LinkedList<Product*> &LP,bool *isAvail, Product* P1, Product* P2) {
    bool foundP1 = false, foundP2 = false;
    int idx1, idx2;
    for (int i = 0;i<LP.size;i++){
        if (!foundP1){
            if ((LP.get(i)->getCode()) == P1->getCode()){
                foundP1 = true;
                idx1 = i;
            }
        }
        if (!foundP2){
            if ((LP.get(i)->getCode()) == P2->getCode()){
                foundP2 = true;
                idx2 = i;
            }
        }
    }
    *isAvail = foundP1&&foundP2;
    if (*isAvail) {
        LP.remove(LP.get(idx1));
        LP.remove(LP.get(idx2));
    }
}

void Mixer::createMartabak(LinkedList<Product*>& LP){
    LP.add(new Martabak);
}
        
void Mixer::createCheese(LinkedList<Product*>& LP){
    LP.add(new Cheese);
}
        
void Mixer::createBeefRolade(LinkedList<Product*>& LP){
    LP.add(new BeefRolade);
}
