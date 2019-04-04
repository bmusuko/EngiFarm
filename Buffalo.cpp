#include"Buffalo.hpp"
#include "BuffaloMeat.hpp"
#include <iostream>
using namespace std;

int Buffalo::BuffaloAlive = 0;
Buffalo::Buffalo(int x,int y):FarmAnimal(x,y,15){
	BuffaloAlive++;
}
Buffalo::~Buffalo(){
	BuffaloAlive--;
}
void Buffalo::suara(){
	cout<<"pukpuk"<<endl;
} //cout "pukpuk"
FarmProduct* Buffalo::respondKill(){
	delete this;
	static BuffaloMeat B;
	return &B;
} //BuffaloAlive-1
int Buffalo::getBuffaloAlive(){
	return BuffaloAlive;
} //return BuffaloAlive