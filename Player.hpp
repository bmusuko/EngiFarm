#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Product.hpp"
#include "LinkedList.hpp"
#include "Cell.hpp"
#include "Land.hpp"
#include "Facility.hpp"
#include "FarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"
#include "MilkProducingFarmAnimal.hpp"
#include "EggProducingFarmAnimal.hpp"

class Player{
    private:
        int posisiX; //Sementara, gua gatau posisi enaknya taro di player apa di cell
        int posisiY;
        int wadahAir;
        int money;
        LinkedList<Product> tas;
    public:
        //Konstruktor  
        Player();

        //CCTor
        Player(const Player&);

        //Dtor
        //~Player();

        //Operator Assignment
        Player& operator= (const Player&);

        //Setter Getter
        int getWadahAir() const;
        Product getTas(int idx) const;
        int getMoney() const;
        static int getTick();
        int getPosisiX() const;
        int getPosisiY() const;

        void setWadahAir(int wadahAir);
        void addElTas(Product *P);
        void delElTas(Product *P);
        void setMoney(int money);

        //Method Lainnya
        void talk(FarmAnimal* hewan);
        void interact(MilkProducingFarmAnimal* hewan);
        void interact(EggProducingFarmAnimal* hewan);
        void interact(Facility* facility);
        void kill(MeatProducingFarmAnimal* hewan);
        void grow(Land* L);
        void move(int arah);
        //Method move buat gerak, arah 1 = atas, 2= kanan, 3 = bawah, 4 = kiri
};

#endif