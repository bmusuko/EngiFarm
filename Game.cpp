#include"Game.hpp"
#include<iostream>
#include<type_traits>
#include<typeinfo>
#include<fstream>
using namespace std;



Game::Game(){
    ifstream petaInput;  
    petaInput.open("peta.txt");
	petaInput>>n;
	petaInput>>m;
	peta = new Cell**[n];
	pemain = new Player();
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
		} else if (c == 'P'){
			pemain.setX(x);
			pemain.setY(y);
		}
		
	}
}

void Game::play(){
	cout<<"Selamat datang di Engi's Farm"<<endl;
}


void Game::printPeta(){
	char**petaTemp;
	petaTemp = new char*[n];
	for(int i=0;i<n;i++){
		petaTemp[i] = new char[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(typeid(Grassland)==typeid(&Cell[i][j])) {
   				if(Cell[i][j]->getIsGrassExist()){
   					petaTemp[i][j] = '#';
   				} else{
   					petaTemp[i][j] = '-';
   				}
			} else if(typeid(Barn)==typeid(&Cell[i][j])){
				if(Cell[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '@';
				} else{
					petaTemp[i][j] = 'x';
				}
			} else if(typeid(Coop)==typeid(&Cell[i][j])){
				if(Cell[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '*';
				} else{
					petaTemp[i][j] = 'o';
				}
			} else if(typeid(Truck)==typeid(&Cell[i][j])){
				petaTemp[i][j] = 'T';
			} else if(typeid(Mixer)==typeid(&Cell[i][j])){
				petaTemp[i][j] = 'M';
			} else if(typeid(Well)==typeid(&Cell[i][j])){
				petaTemp[i][j] = 'W';
			}
		}
	}
	FarmAnimal* AnimalTemp;
	Node *P = ListFarmAnimal;
	int xtemp,ytemp;
	while(P != NULL){
		AnimalTemp = &(P->x);
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();
		if(typeid(Ayam)==typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'A';
		} else if (typeid(Duck) == (&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'D';
		} else if(typeid(Buffalo) == typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'B';
		} else if(typeid(Sheep) == typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'S';
		} else if(typeid(Cow) == typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'C';
		} else if(typeid(Goat) == typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'G';
		}
	}
	petaTemp[pemain.getPosisiX()][pemain.getPosisiY()] = 'P';
}
		
void Game::tick(){
	FarmAnimal* AnimalTemp;
	Node *P = ListFarmAnimal;
	int xtemp,ytemp,xtemp2,ytemp2;
	while(P){
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();
		// xtemp2 = xtemp;
		// ytemp2 = ytemp;
		AnimalTemp = &(P->x);
		AnimalTemp->setLapar((AnimalTemp->getLapar())-1);
		if(AnimalTemp->isLapar()){
			if(peta[xtemp][ytemp].getIsGrassExist()){
				AnimalTemp->eat();
				peta[xtemp][ytemp].setIsGrassExist(false);
			}
		}
		AnimalTemp->TryMove(xtemp,ytemp);
		if(!peta[xtemp][ytemp]->getIsObjectExist()){
			if(Barn* v = dynamic_cast<Barn*>(&peta[xtemp][ytemp])){
				if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}		
			} else if(Grassland* v = dynamic_cast<Grassland*>(&peta[xtemp][ytemp])){
				if(MilkProducingFarmAnimal* v = dynamic_cast<MilkProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}
			} else if(Coop* v = dynamic_cast<Coop*>(&peta[xtemp][ytemp])){
				if(EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}
			}
		}
	}
}
