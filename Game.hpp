#include"Mixer.hpp"
#include"Truck.hpp"
#include"Well.hpp"
#include"Barn.hpp"
#include"Coop.hpp"
#include"Grassland.hpp"
#include"Chicken.hpp"
#include"Duck.hpp"
#include"Buffalo.hpp"
#include"Sheep.hpp"
#include"Cow.hpp"
#include"Goat.hpp"
#include"LinkedList.hpp"
#include"Player.hpp"
#include"BuffaloMeat.hpp"
#include"ChickenEgg.hpp"
#include"ChickenMeat.hpp"
#include"CowMeat.hpp"
#include"CowMilk.hpp"
#include"DuckEgg.hpp"
#include"DuckMeat.hpp"
#include"GoatMeat.hpp"
#include"GoatMilk.hpp"
#include"SheepMeat.hpp"
#include"BeefRolade.hpp"
#include"Cheese.hpp"
#include"Martabak.hpp"


class Game{
	private :
		Cell ***peta;
		int tick;
		LinkedList<FarmAnimal*> ListFarmAnimal;
		int n;
		int m;
		Player pemain;
	public :
		Game();
		void play();
		void nextTick();
		void printPeta();
		void tutorial();
		void keterangan();
		void listCommand();
}