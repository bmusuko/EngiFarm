#ifndef __MIXER_HPP__
#define __MIXER_HPP__

#include "Facility.hpp"

class Mixer : public Facility{
    private:
        
    public:
        //Konstuktor
        Mixer(int X, int Y);

        void use(LinkedList<Product> LP,int &money, int &water, string masukan);
    
};

#endif