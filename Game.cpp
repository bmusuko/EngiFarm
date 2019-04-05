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
				// Coop C(i,j,false,false);
				peta[i][j] = new Coop(i,j,false,false);
			} else if(temp[j] == '*'){
				// Coop C(i,j,true,false);
				peta[i][j] = new Coop(i,j,true,false);
			} else if(temp[j] == '-'){
				// Grassland G(i,j,false,false);
				peta[i][j] = new Grassland(i,j,false,false);
			} else if (temp[j] == '#'){
				// Grassland G(i,j,true,false);
				peta[i][j] = new Grassland(i,j,true,false);
			} else if (temp[j] == 'x'){
				// Barn B(i,j,false,false);
				peta[i][j] = new Barn(i,j,false,false);
			} else if (temp[j] == '@'){
				// Barn B(i,j,true,false);
				peta[i][j] = new Barn(i,j,true,false);
			} else if (temp[j] == 'T'){
				// Truck T(i,j);
				peta[i][j] = new Truck(i,j);
			} else if (temp[j] == 'M'){
				// Mixer M(i,j);
				peta[i][j] = new Mixer(i,j);
			} else if (temp[j] == 'W'){
				// Well W(i,j);
				peta[i][j] = new Well(i,j);
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
			// Chicken C(x,y);
			ListFarmAnimal.add(new Chicken(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'D'){
			// Duck D(x,y);
			ListFarmAnimal.add(new Duck(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'B'){
			// Buffalo B(x,y);
			ListFarmAnimal.add(new Buffalo(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'S'){
			// Sheep S(x,y);
			ListFarmAnimal.add(new Sheep(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'C'){
			ListFarmAnimal.add(new Cow(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'G'){
			// Goat G(x,y);
			ListFarmAnimal.add(new Goat(x,y));
			peta[x][y]->setIsObjectExist(true);
		} else if (c == 'P'){
			peta[x][y]->setIsObjectExist(false);
			pemain.setX(x);
			pemain.setY(y);
		}
	}
}
void Game::play(){
	cout<<"Selamat datang di Engi's Farm"<<endl;
	printPeta();
	string input,input2;
	tutorial();
	cout<<"Masukkan inputan permainan :"<<endl;;
	getline(cin,input);
	bool found;
	int xtemp,ytemp,i;
	while(input != "exit"){
		if (input == "move up"){
			if(isInRange(pemain.getPosisiX()-1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()-1,pemain.getPosisiY())){
					if(!peta[pemain.getPosisiX()-1][pemain.getPosisiY()]->getIsObjectExist()){
						pemain.move(1);
					}
				}
			}
		}else if(input == "move left"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()-1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()-1)){
					if(!peta[pemain.getPosisiX()-1][pemain.getPosisiY()]->getIsObjectExist()){
						pemain.move(4);
					}
				}
			}
		}else if(input == "move down"){
			if(isInRange(pemain.getPosisiX()+1,pemain.getPosisiY())){
				if(isLand(pemain.getPosisiX()+1,pemain.getPosisiY())){
					if(!peta[pemain.getPosisiX()+1][pemain.getPosisiY()]->getIsObjectExist()){
						pemain.move(3);
					}				
				}
			}
		}else if(input == "move right"){
			if(isInRange(pemain.getPosisiX(),pemain.getPosisiY()+1)){
				if(isLand(pemain.getPosisiX(),pemain.getPosisiY()+1)){
					if(!peta[pemain.getPosisiX()][pemain.getPosisiY()+1]->getIsObjectExist()){
						pemain.move(2);
					}
				}
			}
		}else if(input == "talk up"){
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
                                if (EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((v->respondInteract()));
                                }else if(MilkProducingFarmAnimal* f = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((f->respondInteract()));
                                }
                                found = true;
							}
							i++;
						}
                    }
                }else if (typeid(Well) == typeid((Well*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()],"");
                }else if(typeid(Truck) == typeid((Truck*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()],"");
                }else if (typeid(Mixer) == typeid((Mixer*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()],"");
                }
            }

		} else if(input == "interract left"){
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
                                if (EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((v->respondInteract()));
                                }else if(MilkProducingFarmAnimal* f = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((f->respondInteract()));
                                }
                                found = true;
							}
							i++;
						}
                    }
                }else if (typeid(Well) == typeid((Well*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1],"");
                }else if(typeid(Truck) == typeid((Truck*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1],"");
                }else if (typeid(Mixer) == typeid((Mixer*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()-1],"");
                }
            }

		} else if(input == "interract down"){
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
                                if (EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((v->respondInteract()));
                                }else if(MilkProducingFarmAnimal* f = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((f->respondInteract()));
                                }
                                found = true;
							}
							i++;
						}
                    }
                }else if (typeid(Well) == typeid((Well*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()],"");
                }else if(typeid(Truck) == typeid((Truck*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()],"");
                }else if (typeid(Mixer) == typeid((Mixer*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()+1][pemain.getPosisiY()],"");
                }
            }

		} else if(input == "interract right"){
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
                                if (EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((v->respondInteract()));
                                }else if(MilkProducingFarmAnimal* f = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
                                    pemain.addElTas((f->respondInteract()));
                                }
                                found = true;
							}
							i++;
						}
                    }
                }else if (typeid(Well) == typeid((Well*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1],"");
                }else if(typeid(Truck) == typeid((Truck*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1],"");
                }else if (typeid(Mixer) == typeid((Mixer*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1])){
                    pemain.interact((Facility*)peta[pemain.getPosisiX()][pemain.getPosisiY()+1],"");
                }
            }

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
			pemain.grow((Land*)peta[pemain.getPosisiX()-1][pemain.getPosisiY()]);
		} else if(input == "status"){
			pemain.printPlayerStatus();
		}else if(input == "tutorial"){
			tutorial();
		} else if(input == "keterangan"){
			keterangan();
		} else if(input == "listCommand"){
			listCommand();
		} else{
			cout<<"input error"<<endl;
		}
		nextTick();
		printPeta();
		cout<<"Masukkan inputan permainan :"<<endl;;
		getline(cin,input);
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
			petaTemp[i][j] = '/';
		}
	}
	// cout<<"Tipe (Cell) : "<<typeid(Cell).name()<<endl;
	// cout<<"Tipe (Cell&) : "<<typeid(Cell&).name()<<endl;
	// cout<<"Tipe (Cell*) : "<<typeid(Cell*).name()<<endl;
	// cout<<"Tipe (Cell**) : "<<typeid(Cell**).name()<<endl;
	// cout<<"Tipe (Cell&&) : "<<typeid(Cell&&).name()<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// cout<<"Tipe pointer "<<i<<" "<<j<<" : "<<typeid(*peta[i][j]).name()<<endl;
			if(typeid(Grassland)==typeid(*peta[i][j])){
   				if(peta[i][j]->getIsGrassExist()){
   					petaTemp[i][j] = '#';
   				} else{
   					petaTemp[i][j] = '-';
   				}
			} else if(typeid(Barn)==typeid(*peta[i][j])){
				if(peta[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '@';
				} else{
					petaTemp[i][j] = 'x';
				}
			} else if(typeid(Coop)==typeid(*peta[i][j])){
				if(peta[i][j]->getIsGrassExist()){
					petaTemp[i][j] = '*';
				} else{
					petaTemp[i][j] = 'o';
				}
			} else if(typeid(Truck)==typeid(*peta[i][j])){
				petaTemp[i][j] = 'T';
			} else if(typeid(Mixer)==typeid(*peta[i][j])){
				petaTemp[i][j] = 'M';
			} else if(typeid(Well)==typeid(*peta[i][j])){
				petaTemp[i][j] = 'W';
			}
		}
	}
	// cout<<"Sampe"<<endl;
	FarmAnimal* AnimalTemp;
	int xtemp,ytemp;
	cout<<"i = "<<ListFarmAnimal.size<<endl;
	for(int i=0;i<ListFarmAnimal.size;i++){
		
		AnimalTemp = (ListFarmAnimal.get(i));
		xtemp = AnimalTemp->getX();
		ytemp = AnimalTemp->getY();

		// cout<<"i = "<<i<<" "<<typeid(AnimalTemp).name()<<"x = "<<xtemp<<" y = "<<ytemp<<endl;
		// cout<<"i = "<<i<<" "<<typeid(&AnimalTemp).name()<<"x = "<<xtemp<<" y = "<<ytemp<<endl;
		// cout<<"i = "<<i<<" "<<typeid(*AnimalTemp).name()<<"x = "<<xtemp<<" y = "<<ytemp<<endl;
		// cout<<"i = "<<typeid(Chicken).name()<<endl;
		
		if(typeid(Chicken)==typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'A';
		} else if (typeid(Duck) == typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'D';
		} else if(typeid(Buffalo) == typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'B';
		} else if(typeid(Sheep) == typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'S';
		} else if(typeid(Cow) == typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'C';
		} else if(typeid(Goat) == typeid(*AnimalTemp)){
			petaTemp[xtemp][ytemp] = 'G';
		}
		// cout<<"Samp "<<i<<endl;
	}
	// cout<<"Sampe 2"<<endl;
	petaTemp[pemain.getPosisiX()][pemain.getPosisiY()] = 'P';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<petaTemp[i][j]<<" ";
		}
		cout<<endl;
	}
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
		if (isInRange(xtemp,ytemp)){
				if(!peta[xtemp][ytemp]->getIsObjectExist()){
				cout<<"masuk object"<<endl;
				if(typeid(Barn)==typeid(*peta[xtemp][ytemp])){
					if(MeatProducingFarmAnimal* v = dynamic_cast<MeatProducingFarmAnimal*>(AnimalTemp)){
						// cout<<"masuk meat"<<endl;
						peta[AnimalTemp->getX()][AnimalTemp->getY()]->setIsObjectExist(false);
						AnimalTemp->move(xtemp,ytemp);
						peta[xtemp][ytemp]->setIsObjectExist(true);
					}		
				} else if(typeid(Grassland)==typeid(*peta[xtemp][ytemp])){
					if(MilkProducingFarmAnimal* v = dynamic_cast<MilkProducingFarmAnimal*>(AnimalTemp)){
						peta[AnimalTemp->getX()][AnimalTemp->getY()]->setIsObjectExist(false);
						AnimalTemp->move(xtemp,ytemp);
						peta[xtemp][ytemp]->setIsObjectExist(true);
					}
				} else if(typeid(Coop)==typeid(*peta[xtemp][ytemp])){
					if(EggProducingFarmAnimal* v = dynamic_cast<EggProducingFarmAnimal*>(AnimalTemp)){
						peta[AnimalTemp->getX()][AnimalTemp->getY()]->setIsObjectExist(false);
						AnimalTemp->move(xtemp,ytemp);
						peta[xtemp][ytemp]->setIsObjectExist(true);
					}
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
	return (typeid(Grassland)==typeid(*peta[x][y]) || typeid(Barn)==typeid(*peta[x][y]) || typeid(Coop)==typeid(*peta[x][y]) );
}