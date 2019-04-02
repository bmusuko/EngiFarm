#include "Land.hpp"

Land::Land(int X, int Y, bool grass, bool object, bool coop,bool grassland,bool barn):Cell(X,Y){
    this->isObjectExist = object;
    this->isGrassExist = grass;
    this->coop = coop;
    this->grassland = grassland;
    this->barn = barn;
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