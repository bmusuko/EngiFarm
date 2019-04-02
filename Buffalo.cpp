#include"Buffalo.hpp"
#include "BufalloMeat.hpp"
#include <iostream>
using namespace std;

int Buffalo::BuffaloAlive = 0;
Buffalo::Buffalo(){
	BuffaloAlive++;
}
Buffalo::~Buffalo(){
	BuffaloAlive--;
}
void Buffalo::suara(){
	cout<<"pukpuk"<<endl;
} //cout "pukpuk"
FarmProduct Buffalo::respondKill(){
	~Buffalo();
	BuffaloMeat B();
	return B;
} //BuffaloAlive-1
int Buffalo::getBuffaloAlive(){
	return BuffaloAlive;
} //return BuffaloAlive