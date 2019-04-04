#ifndef __MIXER_HPP__
#define __MIXER_HPP__

#include "Facility.hpp"

class Mixer : public Facility{
    private:
        
    public:
        //Konstuktor
        Mixer(int X, int Y);

        void use(LinkedList<Product> LP);
        
        void isInventAvailable(LinkedList<Product> LP,bool *isAvail, Product P1, Product P2);
        
        void createMartabak(LinkedList<Product> LP);
        
        void createCheese(LinkedList<Product> LP);
        
        void createBeefRolade(LinkedList<Product> LP);
};

#endif