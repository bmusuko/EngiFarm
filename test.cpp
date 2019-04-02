#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    int random_number = rand()%4; // rand() return a number between ​0​ and RAND_MAX
    std::cout << random_number;
    return 0;
}