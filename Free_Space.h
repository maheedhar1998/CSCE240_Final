#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class freeSpace : public Human
{
    public:
        freeSpace(bool x, int a, int b) : Human(a, b)
        {
            if(x)
            {
                spot = "None";
                setType('E');
                setWeapon(spot,0);
                setHealth(0);
            }
            else
            {
                spot = "Food";
                setType('F');
                setWeapon(spot,0);
            }
        }
        freeSpace& operator=(freeSpace* rhs)
        {
            bool a;
            if(rhs->getType()=='E')
                a = true;
            else if(rhs->getType()=='F')
                a = false;
            freeSpace retVal(a, rhs->getX(), rhs->getY());
            return retVal;
        }
    private:
        string spot;
};
