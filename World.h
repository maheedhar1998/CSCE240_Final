#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Human.cpp"
#include "Zombie.cpp"
#include "Free_Space.h"
using namespace std;
class World
{
    public:
        World();
        ~World();
        int getDay();
        vector<Human> getHumans();
        vector<Zombie> getZombies();
        Human[][] getGrid();
        void setDay(int);
        void setHumans(vector<Human>);
        void setZombies(vector<Zombie>);
        void setGrid(Human[][]);
        void updateGrid();
        void printLn();
        void printGrid();
    private:
        int day;
        std::vector<Human> humans;
        std::vector<Zombie> zombies;
        Human grid[8][8];
};
