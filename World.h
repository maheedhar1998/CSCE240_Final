#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Human.cpp"
#include "Zombie.cpp"
#include "Free_Space.cpp"
using namespace std;
class World
{
    public:
        World();
        ~World();
        int getDay();
        Human* getHumans();
        Zombie* getZombies();
        //Human* getGrid();
        void setDay(int);
        void setHumans(Human[16]);
        void setZombies(Zombie[16]);
        void setGrid(Human[8][8]);
        void updateGrid();
        void printLn();
        void printGrid();
    private:
        int day;
        Human humans[16];
        Zombie zombies[16];
        Human grid[8][8];
};
