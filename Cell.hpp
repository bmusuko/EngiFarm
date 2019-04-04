#ifndef __CELL_HPP__
#define __CELL_HPP__

class Cell{
    protected:
        int X;
        int Y;
    public:
        //Konstruktor
        Cell(); 
        Cell(int X,int Y);

        //Getter
        int getX() const;
        int getY() const;
        
        //Setter
        void setX(int X);
        void setY(int Y);

        virtual bool getIsGrassExist() const = 0;
        virtual bool getIsObjectExist () const = 0;
        virtual void setIsGrassExist(bool grass) = 0;
        virtual void setIsObjectExist(bool object) = 0;
};

#endif