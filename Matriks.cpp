#include "Matriks.hpp"

Matriks::Matriks(int size){
    matriks = new Cell*[size];
    for (int i = 0;i<size;i++){
        matriks[i] = new Cell[size];
    }

    for (int i = 0;i<size;i++){
        for (int j = 0;j<size;j++){
            matriks[i][j].setX(j);
            matriks[i][j].setY(i);
        }
    }
}

Cell Matriks::getCell(int x, int y){
    return matriks[y][x];
}