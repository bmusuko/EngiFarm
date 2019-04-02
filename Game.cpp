#include"Game.hpp"
#include<iostream>
#include<fstream>
using namespace std;



Game::Game(){
    ifstream input;
    input.open("peta.txt");
	int n;
	int m;
	input>>n;
	input>>m;
	peta = new Cell**[n];
	for(int i=0;i<n;i++){
		peta[i] = new Cell*[m];
	}
	for(int i=0;i<n;i++){
		input>>temp;
		for(int j=0;j<m;j++){
			if(input[j] == 'o'){
				Coop C(i,j,false,false);
				peta[i][j] = &C;
			} else if(input[j] == '*'){
				Coop C(i,j,true,false);
				peta[i][j] = &C;
			} else if(input[j] == '-'){
				Grassland G(i,j,false,false);
				peta[i][j] = &G;
			} else if (input[j] == '#'){
				Grassland G(i,j,true,false);
				peta[i][j] = &G;
			} else if (input == 'x'){
				Barn B(i,j,false,false);
				peta[i][j] = &B;
			} else if (input == '@'){
				Barn B(i,j,true,false);
				peta[i][j] == &B;
			} else if (input == 'T'){
				Truck T(i,j);
				peta[i][j] = &T;
			} else if (input == 'M'){
				Mixer M(i,j);
				peta[i][j] = &M;
			} else if (input == 'W'){
				Well W(i,j);
				peta[i][j] = &W;
			}
		}
	}
}

Game::play(){

}




Game::tick(){

}