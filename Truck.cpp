#include "Truck.hpp"

Truck::Truck(int X, int Y):Facility(X,Y){}

void Truck::use(Player * P){
    while(!(P->getTas().isEmpty())){
        Product * Pd;
        P->getTas().remove(*Pd);
        P->setMoney(P->getMoney()+Pd->getHarga());
    }
}