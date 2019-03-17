#ifndef __FACILITY_HPP__
#define __FACILITY_HPP__

#include "Cell.hpp"

class Facility: public Cell{
    protected:
    public:
        virtual void use() = 0;

};

#endif