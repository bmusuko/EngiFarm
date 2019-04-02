#include"Sheep.hpp"
#include "SheepMeat.hpp"
#include <iostream>
using namespace std;

int Sheep::SheepAlive = 0;
Sheep::Sheep(){
	SheepAlive++;
}
Sheep::~Sheep(){
	SheepAlive--;
}
void Sheep::suara(){
	cout<<"pukpuk"<<endl;
} //cout "pukpuk"
FarmProduct Sheep::respondKill(){
	~Sheep();
	SheepMeat B();
	return B;
} //SheepAlive-1
string Sheep::getTipeFarmAnimal(){
	string s = "Sheep";
	return s;
}
int Sheep::getSheepAlive(){
	return SheepAlive;
} //return SheepAlive