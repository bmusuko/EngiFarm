#include "Truck.hpp"

Truck::Truck(int X, int Y):Facility(X,Y){
    cooldown = 0;
}

void Truck::minCD(){
    if (cooldown>0){
        cooldown--;
    }
}

void Truck::use(LinkedList<Product*>& LP,int &money, int &water, string masukan){
    cout<<"Masuk"<<endl;
    if (cooldown == 0){
        cout<<"Masuk 2"<<endl;
        while(!(LP.isEmpty())){
            money = money+ (LP.get(LP.size-1))->getHarga();
            LP.remove(LP.get(LP.size-1));
        }
    }
}