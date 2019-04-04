#include "Truck.hpp"

Truck::Truck(int X, int Y):Facility(X,Y){
    cooldown = 5;
}

void Truck::minCD(){
    if (cooldown>0){
        cooldown--;
    }
}

void Truck::use(LinkedList<Product*> LP,int &money, int &water, string masukan){
    if (cooldown == 0){
        while(!(LP.isEmpty())){
            Product * Pd;
            LP.remove(Pd);
            money+=Pd->getHarga();
        }
    }
}