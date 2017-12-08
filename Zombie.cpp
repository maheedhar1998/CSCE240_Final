#include <iostream>
#include <cstdlib>
using namespace std;
Zombie::Zombie()
{
    immunization = ((rand()%100)+1)/100;
    mutation = ((rand()%100)+1)/100;
}
Zombie::Zombie(double a, double b) : Human(Human& c)
{
    immunization = a;
    mutation = b;
}
Zombie::Zombie(Zombie& a)
{
    x = a.x;
    y = a.y;
    health = a.health;
    weapon = a.weapon;
    immunization = a.immunization;
    mutation = a.mutation;
}
Zombie::~Zombie(){}
double getImmunization()
{
    return immunization;
}
double getMutation()
{
    return mutation;
}
void setImmunization(double a)
{
    if(a>.5)
    {
        immunization = .5;
    }
    else if(a<=0)
    {
        immunization = .01;
    }
    else if(a>0 && a<=.5)
    {
        immunization = a;
    }
}
void setMutation(double a)
{
    if(a>.5)
    {
        mutation = .5;
    }
    else if(a<=0)
    {
        mutation = .01;
    }
    else if(a>0 && a<=.5)
    {
        mutation = a;
    }
}
