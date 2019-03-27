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