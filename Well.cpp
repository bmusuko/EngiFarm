#include "Well.hpp"

Well::Well(int X, int Y):Facility(X,Y){};

void Well::use(LinkedList<Product*> &LP,int &money, int &water, string masukan){
    cout<<"Masuk well di cpp"<<endl;
    water = 10;
}

void Well::use(int & waiter){
    waiter = 10;
}
