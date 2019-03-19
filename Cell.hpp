#ifndef __CELL_HPP__
#define __CELL_HPP__

class Cell{
    protected:
        int X;
        int Y;
    public:
        //Konstruktor
        Cell(int X,int Y);

        //Getter
        int getX() const;
        int getY() const;
        
        //Setter
        void setX(int X);
        void setY(int Y);
};

#endif