#include <iostream>
#include <cstdlib>
#include <string>
#include "Weapon.h"
using namespace std;
Weapon::Weapon()
{
    name = "none";
    damage = 0
}
Weapon::Weapon(string x)
{
    name = x;
    damage = (rand()%50)+1;
}
Weapon::Weapon(string x, int y)
{
    name = x;
    damage = y;
}
Weapon::Weapon(Weapon& x)
{
    name = x.name;
    damage = x.damage;
}
string Weapon::getName()
{
    return name;
}
int Weapon::getDamage()
{
    return damage;
}
void Weapon::setName(string x)
{
    name = x;
}
void Weapon::setDamage(int x)
{
    if(x>50)
    {
        damage = 50;
    }
    else if(x<=50 or x>0)
    {
        damage = x;
    }
    else if(x<=0)
    {
        damage = 1;
    }
}
void Weapon::print()
{
    cout << "Name: " << name << "\nDamage: " << damage << endl;
}
