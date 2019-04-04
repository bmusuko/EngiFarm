#include "Truck.hpp"

Truck::Truck(int X, int Y):Facility(X,Y){}

void Truck::use(LinkedList<Product> LP,int &money, int &water, string masukan){
    while(!(LP.isEmpty())){
        Product * Pd;
        LP.remove(*Pd);
        money+=Pd->getHarga();
    }
}