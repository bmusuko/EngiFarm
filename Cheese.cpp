#include <iostream>
#include "Cheese.hpp"
#include "CowMilk.hpp"
#include "GoatMilk.hpp"

using namespace std;

Cheese::Cheese() : SideProduct(20000,"Cheese") {
    harga = 20000;
}