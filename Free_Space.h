#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class freeSpace : public Human
{
    public:
        freeSpace(bool x) : Human(int x, int y)
        {
            if(x)
            {
                spot = "None";
                setWeapon(spot,0);
            }
            else
            {
                spot = "Food";
                setWeapon(spot,0);
            }
        }
    private:
        string spot;
};
