#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Weapon
{
    public:
        Weapon(string);
        Weapon(string,int);
        Weapon(Weapon&);
        string getName();
        int getDamage();
        void setName(string);
        void setDamage(int);
        void print();
    private:
        string name;
        int damage;
};
