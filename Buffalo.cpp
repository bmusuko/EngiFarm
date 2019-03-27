#include"Buffalo.hpp"

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
FarmAnimal Buffalo::respondKill(){
	~Buffalo();
	B BuffaloMeat();
	return B;
} //BuffaloAlive-1
string Buffalo::getTipeFarmAnimal(){
	string s = "Buffalo";
	return s;
}
int Buffalo::getBuffaloAlive(){
	return BuffaloAlive;
} //return BuffaloAlive