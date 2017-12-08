#include <iostream>
#include <cstdlib>
using namespace std;
class Zombie: public Human
{
    public:
        Zombie();
        Zombie(double,double) : Human(Human&);
        Zombie(Zombie&);
        ~Zombie();
        double getImmunization();
        double getMutation();
        void setImmunization(double);
        void setMutation(double);
    private:
        double immunization;
        double mutation;
};
