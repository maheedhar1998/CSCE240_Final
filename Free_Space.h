#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class freeSpace : public Human
{
    public:
        freeSpace(bool x) : Human(int a, int b)
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
    private:
        string spot;
};
