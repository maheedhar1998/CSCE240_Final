#ifndef WORLD_H
#define WORLD_H
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
        Human** getGrid();
        void setDay(int);
        void setGrid(Human**);
        void updateGrid();
        void printLn();
        void printGrid();
    private:
        int day;
        Human** grid;
};
#endif
