#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

//#include "Product.hpp"
//#include "LinkedList.hpp"

class Player{
    private:
        int posisiX; //Sementara, gua gatau posisi enaknya taro di player apa di cell
        int posisiY;
        int wadahAir;
        //LinkedList<Produk> tas;
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
        void setWadahAir(int wadahAir);
        void setTas(int idx /*, Product P*/);

        //Method Lainnya
        void talk();
        void interact();
        void kill();
        void grow();

        void move(int arah);
        //Method move buat gerak, arah 1 = atas, 2= kanan, 3 = bawah, 4 = kiri
};

#endif