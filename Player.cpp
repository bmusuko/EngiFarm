#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player(){
    posisiX = 0;
    posisiY = 0;
    wadahAir = 0;
    money = 0;
}

Player::Player(const Player& P){
    posisiX = P.posisiX;
    posisiY = P.posisiY;
    wadahAir = P.wadahAir;
    money = P.money;
    tas = P.tas;
}

Player& Player::operator= (const Player& P){
    posisiX = P.posisiX;
    posisiY = P.posisiY;
    wadahAir = P.wadahAir;
    money = P.money;
    tas = P.tas;
}

int Player::getWadahAir() const{
    return wadahAir;
}

Product Player::getIsiTas(int idx) const{
    return tas.get(idx);
}

LinkedList<Product> Player::getTas() const{
    return this->tas;
}

int Player::getMoney() const{
    return money;
}

int Player::getPosisiX() const{
    return posisiX;
}

int Player::getPosisiY() const{
    return posisiY;
}

void Player::setX(int x){
    posisiX = x;
}
void Player::setY(int y){
    posisiY = y;
}
void Player::setWadahAir(int wadahAir){
    this->wadahAir = wadahAir;
}

void Player::addElTas(Product *P){
    this->tas.add(*P);
}

void Player::delElTas(Product *P){
    this->tas.remove(*P);
}

void Player::setMoney(int money){
    this->money = money;
}

void Player::talk(FarmAnimal* hewan){
    hewan->suara();
}

void Player::interact(MilkProducingFarmAnimal* hewan){
    this->addElTas(hewan->respondInteract()); //keknya udah bener
}
void Player::interact(EggProducingFarmAnimal* hewan){
    this->addElTas(hewan->respondInteract()); //keknya udah bener
}
void Player::interact(Facility* facility, string masukan){
    facility->use(this->tas,this->money,this->wadahAir,masukan);    //keknya udah bener
}

void Player::kill(MeatProducingFarmAnimal* hewan){
    this->addElTas(hewan->respondKill()); //keknya udah bener
}

void Player::grow(Land* L){
    L->setIsGrassExist(true);
}

void Player::move(int arah){
    if (arah == 1){
        posisiY++;
    }else if (arah == 2){
        posisiX++;
    }else if(arah == 3){
        posisiY--;
    }else if (arah == 4){
        posisiX--;
    }
}



