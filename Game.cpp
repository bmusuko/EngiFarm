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
	for(int i=0;i<n;i++){
		peta[i] = new Cell*[m];
	}
	string temp;
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
			} else if (temp[j] == 'x'){
				Barn B(i,j,false,false);
				peta[i][j] = &B;
			} else if (temp[j] == '@'){
				Barn B(i,j,true,false);
				peta[i][j] == &B;
			} else if (temp[j] == 'T'){
				Truck T(i,j);
				peta[i][j] = &T;
			} else if (temp[j] == 'M'){
				Mixer M(i,j);
				peta[i][j] = &M;
			} else if (temp[j] == 'W'){
				Well W(i,j);
				peta[i][j] = &W;
			}
		}
	}
	ifstream dllInput;
	dllInput.open("dll.txt");
	char c;
	int x,y;
	while(!dllInput.eof()){
		dllInput>>c;
		dllInput>>x;
		dllInput>>y;
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
	bool found;
	int xtemp,ytemp,i;
	while(input != "exit"){
		if(input == "talk up"){
			if(isInRange(pemain.getPosisiX()-1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()-1,pemain.getPosisiY())){
					if(peta[pemain.getPosisiX()-1][pemain.getPosisiY()]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX()-1 and ytemp==pemain.getPosisiY()){
								AnimalTemp->suara();
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "talk left"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()-1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()-1)){
					if(peta[pemain.getPosisiX()][pemain.getPosisiY()-1]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX() and ytemp==pemain.getPosisiY()-1){
								AnimalTemp->suara();
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "talk down"){
			if(isInRange(pemain.getPosisiX()+1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()+1,pemain.getPosisiY())){
					if(peta[pemain.getPosisiX()+1][pemain.getPosisiY()]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX()+1 and ytemp==pemain.getPosisiY()){
								AnimalTemp->suara();
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "talk right"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()+1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()+1)){
					if(peta[pemain.getPosisiX()][pemain.getPosisiY()+1]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX() and ytemp==pemain.getPosisiY()+1){
								AnimalTemp->suara();
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "interract up"){

		} else if(input == "interract left"){

		} else if(input == "interract down"){

		} else if(input == "interract right"){

		} else if(input == "kill up"){
			if(isInRange(pemain.getPosisiX()-1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()-1,pemain.getPosisiY())){
					if(peta[pemain.getPosisiX()-1][pemain.getPosisiY()]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX()-1 and ytemp==pemain.getPosisiY()){
								if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
									FarmProduct* temp = v->respondKill();
									pemain.addElTas(temp);
								}
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "kill left"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()-1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()-1)){
					if(peta[pemain.getPosisiX()][pemain.getPosisiY()-1]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX() and ytemp==pemain.getPosisiY()-1){
								if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
									FarmProduct* temp = v->respondKill();
									pemain.addElTas(temp);
								}
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "kill down"){
			if(isInRange(pemain.getPosisiX()+1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()+1,pemain.getPosisiY())){
					if(peta[pemain.getPosisiX()+1][pemain.getPosisiY()]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX()+1 and ytemp==pemain.getPosisiY()){
								if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
									FarmProduct* temp = v->respondKill();
									pemain.addElTas(temp);
								}
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "kill right"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()+1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()+1)){
					if(peta[pemain.getPosisiX()][pemain.getPosisiY()+1]->getIsObjectExist()){
						found = false;
						i = 0;
						FarmAnimal* AnimalTemp;
						while(!found and i <ListFarmAnimal.size){
							AnimalTemp = (ListFarmAnimal.get(i));
							xtemp = AnimalTemp->getX();
							ytemp = AnimalTemp->getY();
							if(xtemp==pemain.getPosisiX() and ytemp==pemain.getPosisiY()+1){
								if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
									FarmProduct* temp = v->respondKill();
									pemain.addElTas(temp);
								}
								found = true;
							}
							i++;
						}
					}
				}
			}
		} else if(input == "grow"){

		} else if(input == "tutorial"){
			tutorial();
		} else if(input == "keterangan"){
			keterangan();
		} else if(input == "listCommand"){
			listCommand();
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
		AnimalTemp = (ListFarmAnimal.get(i));
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();
		if(typeid(Chicken)==typeid(&AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'A';
		} else if (typeid(Duck) == typeid(&AnimalTemp)){
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
		
void Game::nextTick(){
	FarmAnimal* AnimalTemp;
	int xtemp,ytemp;
	for(int i=0;i<ListFarmAnimal.size;i++){
		AnimalTemp = (ListFarmAnimal.get(i));
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();
		AnimalTemp->setLapar((AnimalTemp->getLapar())-1);
		if(AnimalTemp->isLapar()){
			if(peta[xtemp][ytemp]->getIsGrassExist()){
				AnimalTemp->eat();
				peta[xtemp][ytemp]->setIsGrassExist(false);
			}
		}
		AnimalTemp->TryMove(xtemp,ytemp);
		if(!peta[xtemp][ytemp]->getIsObjectExist()){
			if(typeid(Barn)==typeid(&peta[xtemp][ytemp])){
				if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
					AnimalTemp->move(xtemp,ytemp);
				}		
			} else if(typeid(Grassland)==typeid(&peta[xtemp][ytemp])){
				if(MilkProducingFarmAnimal* v = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
					AnimalTemp->move(xtemp,ytemp);
				}
			} else if(typeid(Coop)==typeid(&peta[xtemp][ytemp])){
				if(EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
					AnimalTemp->move(xtemp,ytemp);
				}
			}
		}
		if(AnimalTemp->getLapar()<=-5){
			ListFarmAnimal.remove(AnimalTemp);
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

int Game::isInRange(int x,int y){
	return ( (x>=0) && (x<n) &&  (y>=0) && (y<m) );
}

int Game::isLand(int x,int y){
	return (typeid(Grassland)==typeid(&peta[x][y]) || typeid(Barn)==typeid(&peta[x][y]) || typeid(Coop)==typeid(&peta[x][y]) );
}