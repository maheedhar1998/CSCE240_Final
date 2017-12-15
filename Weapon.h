#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Weapon
{
    public:
        Weapon();
        Weapon(string);
        Weapon(string,int);
        Weapon(Weapon&);
        string getName();
        int getDamage();
        void setName(string);
        void setDamage(int);
        string toString();
    private:
        string name;
        int damage;
};
#endif
