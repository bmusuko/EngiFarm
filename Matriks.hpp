#include "Mixer.hpp"
#include "Truck.hpp"
#include "Well.hpp"
#include "Grassland.hpp"
#include "Barn.hpp"
#include "Coop.hpp"
#include "Cell.hpp"
#include "Land.hpp"
#include "Facility.hpp"

class Matriks{
    private:
        int size;
        Cell **matriks;
    
    public:
        Matriks(int size);
        Cell getCell(int x,  int y);
}