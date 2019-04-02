#include "Land.hpp"

Land::Land(int X, int Y, bool grass, bool object):Cell(X,Y){
    this->isObjectExist = object;
    this->isGrassExist = grass;
}

bool Land::getIsGrassExist() const{
    return isGrassExist;                        
}
bool Land::getIsObjectExist () const{
    return isObjectExist;
}
void Land::setIsGrassExist(bool grass){
    this->isGrassExist = grass;
}
void Land::setIsObjectExist(bool object){
    this->isObjectExist = object;
}