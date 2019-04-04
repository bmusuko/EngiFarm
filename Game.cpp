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
	printPeta();
	string input;
	tutorial();
	cout<<"Masukkan inputan permainan :";
	cin>>input;
	boolean found;
	int xtemp,ytemp,i;
	while(input != "exit"){
		if(input == "talk up"){
			if(isInRange(P.getPosisiX()-1,P.getPosisiY())){
				if(isLand(x,y)){
					if(peta[x][y]->getIsObjectExist()){
						found = false;
						i = 0;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = &(ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==P.getPosisiX()-1 and ytemp==P.getPosisiY()){
								AnimalTemp->suara();
								found = true;
							}
						}
					}
				}
			}
		} else if(input == "talk left"){

		} else if(input == "talk down"){

		} else if(input == "talk right"){

		} else if(input == "interract up"){

		} else if(input == "interract left"){

		} else if(input == "interract down"){

		} else if(input == "interract right"){

		} else if(input == "kill up"){

		} else if(input == "kill left"){

		} else if(input == "kill down"){

		} else if(input == "kill right"){

		} else if(input == "grow"){

		} else if(input == "well up"){

		} else if(input == "well left"){

		} else if(input == "well down"){

		} else if(input == "well right"){

		} else if(input == "sell up"){

		} else if(input == "sell left"){

		} else if(input == "sell down"){

		} else if(input == "sell right"){

		} else if(input == "mix up"){

		} else if(input == "mix left"){

		} else if(input == "mix down"){

		} else if(input == "mix right"){

		} else if(input == "tutorial"){

		} else if(input == "keterangan"){

		} else if(input == "listCommand"){

		} else if(input == "exit"){

		} else{
			cout<<"input error"<<endl;
		}
		cin>>input;
	}
}
void Game::printPeta(){
	char**petaTemp;
	petaTemp = new char*[n];
	for(int i=0;i<n;i++){
		petaTemp[i] = new char[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(typeid(Grassland)==typeid(&peta[i][j])) {
   				if(peta[i][j]->getIsGrassExist()){
   					petaTemp[i][j] = '#';
   				} else{
   					petaTemp[i][j] = '-';
   				}
			} else if(typeid(Barn)==typeid(&peta[i][j])){
				if(peta[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '@';
				} else{
					petaTemp[i][j] = 'x';
				}
			} else if(typeid(Coop)==typeid(&peta[i][j])){
				if(peta[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '*';
				} else{
					petaTemp[i][j] = 'o';
				}
			} else if(typeid(Truck)==typeid(&peta[i][j])){
				petaTemp[i][j] = 'T';
			} else if(typeid(Mixer)==typeid(&peta[i][j])){
				petaTemp[i][j] = 'M';
			} else if(typeid(Well)==typeid(&peta[i][j])){
				petaTemp[i][j] = 'W';
			}
		}
	}
	FarmAnimal* AnimalTemp;
	int xtemp,ytemp;
	for(int i=0;i<ListFarmAnimal.size;i++){
		AnimalTemp = &(ListFarmAnimal.get(i));
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
	int xtemp,ytemp;
	for(int i=0;i<ListFarmAnimal.size;i++){
		AnimalTemp = &(ListFarmAnimal.get(i));
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();
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
			if(typeid(Barn)==typeid(&peta[i][j])){
				if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}		
			} else if(typeid(Grassland)==typeid(&peta[i][j])){
				if(MilkProducingFarmAnimal* v = dynamic_cast<MilkProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}
			} else if(typeid(Coop)==typeid(&peta[i][j])){
				if(EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(&FarmAnimal)){
					AnimalTemp->move(xtemp,ytemp);
				}
			}
		}
	}
}

void Game::tutorial(){
	cout<<"selamat datang di dalam tutorial"<<endl;
	keterangan();
	listCommand();
}

void Game::keterangan(){
	cout<<"Keterangan"<<endl;
	cout<<"A : Ayam"<<endl;
	cout<<"D : Bebek"<<endl;
	cout<<"B : Kerbau"<<endl;
	cout<<"S : Domba"<<endl;
	cout<<"C : Sapi"<<endl;
	cout<<"G : Kambing"<<endl;
	cout<<"P : Player"<<endl;
	cout<<"- : Grassland"<<endl;
	cout<<"x : Barn"<<endl;
	cout<<"o : Coop"<<endl;
	cout<<"*,@,# : Land dengan rumput"<<endl;
}


void Game::listCommand(){
	cout<<"talk"<<endl;
	cout<<"interract"<<endl;
	cout<<"kill"<<endl;
	cout<<"grow"<<endl;
	cout<<"well"<<endl;
	cout<<"sell"<<endl;
	cout<<"mix"<<endl;
	cout<<"tutorial"<<endl;
	cout<<"keterangan"<<endl;
	cout<<"listCommand"<<endl;
	cout<<"exit"<<endl;
}

void Game::isInRange(int x,int y){
	return ( (x>=0) && (x<n) &&  (y>=0) && (y<m) );
}

void Game::isLand(int x,int y){
	return (typeid(Grassland)==typeid(&peta[x][y]) || typeid(Barn)==typeid(&peta[x][y]) || typeid(Coop)==typeid(&peta[x][y]) );
}