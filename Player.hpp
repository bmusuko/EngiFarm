#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Product.hpp"
#include "LinkedList.hpp"

class Player{
    private:
        static int tick;  //Diinisialisasi dengan nilai 0
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
        ~Player();

        //Operator Assignment
        Player& operator= (const Player&);

        //Setter Getter
        int getWadahAir() const;
        int getTas(int idx) const;
        int getMoney() const;
        static int getTick();
        int getPosisiX() const;
        int getPosisiY() const;

        void setWadahAir(int wadahAir);
        void setTas(int idx , Product P);
        void setMoney(int money);

        //Method Lainnya
        void talk();
        void interact();
        void kill();
        void grow();
        void nextTick(); //Untuk melakukan inkremen pada atribut tick yang menandakan penambahan waktu

        void move(int arah);
        //Method move buat gerak, arah 1 = atas, 2= kanan, 3 = bawah, 4 = kiri
};

#endif