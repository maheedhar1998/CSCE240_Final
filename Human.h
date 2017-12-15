#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Weapon.cpp"
using namespace std;
class Human
{
    public:
        Human();
        Human(int,int);
        Human(int,int,char);
        Human(Human&);
	    ~Human();
        int getX();
        int getY();
        int getHealth();
        Weapon getWeapon();
        char getType();
        bool getMoved();
        void setX(int);
        void setY(int);
        void setHealth(int);
        void increaseHealth(int);
        void decreaseHealth(int);
        void setWeapon();
        void setWeapon(string,int);
        void setType(char);
        void setMoved(bool);
        void move();
        bool isValidMove(char);
        Human& operator=(Human*);
        string toString();

    private:
        int x;
        int y;
        int health;
        char type;
        bool moved;
	    string weaponArr[14] = {"Machine Gun","Baseball Bat","Machete","Katana","Axe","Zanpakto","Trench Knife","Crowbar","Crossbow","Bow & Arrow","Mace","Grenades","Shot Gun","Assault Rifle"};
        Weapon weapon;
        char moveArr[4] = {'U','D','R','L'};
};
#endif
