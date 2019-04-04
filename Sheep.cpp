#include"Sheep.hpp"
#include "SheepMeat.hpp"
#include <iostream>
using namespace std;

int Sheep::SheepAlive = 0;
Sheep::Sheep(int x,int y):FarmAnimal(x,y,12){
	SheepAlive++;
}
Sheep::~Sheep(){
	SheepAlive--;
}
void Sheep::suara(){
	cout<<"pukpuk"<<endl;
} //cout "pukpuk"
FarmProduct* Sheep::respondKill(){
	delete this;
	static SheepMeat B;
	return &B;
} //SheepAlive-1
int Sheep::getSheepAlive(){
	return SheepAlive;
} //return SheepAlive