#include <iostream>
#include <cstdlib>
#include "Weapon.cpp"
using namespace std;
class Human
{
    public:
        Human();
        Human(int,int);
        Human(Human&);
        int getX();
        int getY();
        int getHealth();
        Weapon getWeapon();
        void setX(int);
        void setY(int);
        void setHealth(int);
        void increaseHealth(int);
        void decreaseHealth(int);
        void setWeapon();
    private:
        int x;
        int y;
        int health;
        Weapon weapon;
};
