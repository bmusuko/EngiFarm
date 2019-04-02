#include"Game.hpp"
#include<iostream>
#include<fstream>
using namespace std;



Game::Game(){
    ifstream petaInput;  
    petaInput.open("peta.txt");
	int n;
	int m;
	petaInput>>n;
	petaInput>>m;
	peta = new Cell**[n];
	for(int i=0;i<n;i++){
		peta[i] = new Cell*[m];
	}
	for(int i=0;i<n;i++){
		petaInput>>temp;
		for(int j=0;j<m;j++){
			if(temp[j] == 'o'){
				Coop C(i,j,false,false);
				peta[i][j] = &C;
			} else if(temp[j] == '*'){
				Coop C(i,j,true,false);
				peta[i][j] = &C;
			} else if(temp[j] == '-'){
				Grassland G(i,j,false,false);
				peta[i][j] = &G;
			} else if (temp[j] == '#'){
				Grassland G(i,j,true,false);
				peta[i][j] = &G;
			} else if (temp == 'x'){
				Barn B(i,j,false,false);
				peta[i][j] = &B;
			} else if (temp == '@'){
				Barn B(i,j,true,false);
				peta[i][j] == &B;
			} else if (temp == 'T'){
				Truck T(i,j);
				peta[i][j] = &T;
			} else if (temp == 'M'){
				Mixer M(i,j);
				peta[i][j] = &M;
			} else if (temp == 'W'){
				Well W(i,j);
				peta[i][j] = &W;
			}
		}
	}
	ListFarmAnimal = new LinkedList<FarmAnimal*>;
	ifstream dllInput;
	dllInput.open("dll.txt");
	while(!dll.eof()){
		dll>>c;
		dll>>x;
		dll>>y;
		if(c == 'A'){
			Chicken C(x,y);
			ListFarmAnimal.add(&C);
		} else if (c == 'D'){
			Duck D(x,y);
			ListFarmAnimal.add(&D);
		} else if (c == 'B'){
			Buffalo B(x,y);
			ListFarmAnimal.add(&B);
		} else if (c == 'S'){
			Sheep S(x,y);
			ListFarmAnimal.add(&S);
		} else if (c == 'C'){
			Cow C(x,y);
			ListFarmAnimal.add(&C);
		} else if (c == 'G'){
			Goat G(x,y);
			ListFarmAnimal.add(&G);
		}
		
	}
}

Game::play(){

}




Game::tick(){

}