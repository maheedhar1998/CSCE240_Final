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
	    ~Human();
        int getX();
        int getY();
        int getHealth();
        Weapon getWeapon();
        char getType();
        void setX(int);
        void setY(int);
        void setHealth(int);
        void increaseHealth(int);
        void decreaseHealth(int);
        void setWeapon();
        void setWeapon(string,int);
        void setType(char);
        void move();
        bool isValidMove(char);




    private:
        int x;
        int y;
        int health;
        char type;
	    string weaponArr[14] = {"Machine Gun","Baseball Bat","Machete","Katana","Axe","Zanpakto","Trench Knife","Crowbar","Crossbow","Bow & Arrow","Mace","Grenades","Shot Gun","Assault Rifle"};
        Weapon weapon;
        char moveArr[4] = {'U','D','R','L'};
};
