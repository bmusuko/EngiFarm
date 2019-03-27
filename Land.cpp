#include "Land.hpp"

Land::Land(int X, int Y, bool grass, bool object, bool coop,bool grassland,bool barn):Cell(X,Y){
    this->isOBjectExist = object;
    this->isGrassExist = grass;
    this->coop = coop;
    this->grassland = grassland;
    this->barn = barn;
}

bool Land::getIsGrassExist() const{
    return isGrassExist;                        
}
bool Land::getIsObjectExist () const{
    return isOBjectExist;
}
void Land::setIsGrassExist(bool grass){
    this->grass = grass;
}
void Land::setIsObjectExist(bool object){
    this->isOBjectExist = object;
}
void Land::isCoop() const{
    return coop;
}
void Land::isGrassLand() const{
    return grassland;
}
void isBarn() const{
    return barn;
}