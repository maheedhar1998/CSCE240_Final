#include <iostream>
#include <cstdlib>
#include <string>
#include "Free_Space.h"
freeSpace::freeSpace(bool c, int a, int b) : Human(a, b, 'F')
{
    if(c)
    {
        cout << "Empty\n";
        spot = "None";
        setType('E');
        setWeapon(spot,0);
        setHealth(0);
    }
    else
    {
        cout << "Food\n";
        spot = "Food";
        setType('F');
        setWeapon(spot,0);
    }
}
freeSpace& freeSpace::operator=(freeSpace* rhs)
{
    spot = rhs->spot;
    setType(rhs->getType());
    setWeapon(spot,0);
    if(rhs->getType()=='E')
        setHealth(0);
    return *this;
}
