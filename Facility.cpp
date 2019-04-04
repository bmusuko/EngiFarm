#include "Facility.hpp"

Facility::Facility(int X, int Y):Cell(X,Y){}

bool Facility::getIsGrassExist() const{
    return false;                        
}
bool Facility::getIsObjectExist () const{
    return false;
}