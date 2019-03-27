#include "Player.hpp"
#include <iostream>

using namespace std;

int Player::tick = 0;
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

int Player::getWadahAir() const{return wadahAir;}
Product Player::getTas(int idx) const{return tas.get(idx);}
int Player::getMoney() const{return money;}
int Player::getTick(){return tick;}
int Player::getPosisiX() const{return posisiX;}
int Player::getPosisiY() const{return posisiY;}

void Player::setWadahAir(int wadahAir){
    this->wadahAir = wadahAir;
}

void Player::addElTas(Product P){
    this->tas.add(P);
}

void Player::delElTas(Product P){
    this->tas.remove(P);
}

void Player::setMoney(int money){
    this->money = money;
}



