#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Free_Space.h"
freeSpace::freeSpace(bool c, int a, int b) : Human(a, b)
{
    if(c)
    {
        //cout << "Empty\n";
        spot = "None";
        setType('E');
        setWeapon(spot,0);
        setHealth(0);
    }
    else
    {
        //cout << "Food\n";
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
string freeSpace::toString()
{
    ostringstream ss;
    ss << getX() << " " << getY();
    string coord = ss.str();
    ostringstream ss1;
    ss1 << getHealth();
    return spot+"\nCoordinates: "+coord+"\nHealth: "+ss1.str();
}
