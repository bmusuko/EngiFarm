#include "Cell.hpp"

Cell::Cell(){
    this->X = 0;
    this->Y = 0;
}

Cell::Cell(int X,int Y){
    this->X = X;
    this->Y = Y;
}

int Cell::getX() const{
    return X;
}

int Cell::getY() const{
    return Y;
}

void Cell::setX(int X){
    this->X = X;
}

void Cell::setY(int Y){
    this->Y = Y;
}