#include <iostream>
#include <cstdlib>
#include <string>
#include "Zombie.h"
using namespace std;
Zombie::Zombie(int a, int b) : Human(a, b)
{
    setType('Z');
    setWeapon("Attack", getWeapon().getDamage());
    imm = 0;
    mut = 0;
    ver2 = false;
    immunization = ((rand()%100)+1)/100;
    mutation = ((rand()%100)+1)/100;
}
Zombie::Zombie(double a, double b, Human& c) : Human(c)
{
    setType('Z');
    setWeapon("Attack", c.getWeapon().getDamage());
    imm = 0;
    mut = 0;
    ver2 = false;
    immunization = a;
    mutation = b;
}
Zombie::Zombie(Zombie& a)
{
    setX(a.getX());
    setY(a.getY());
    setType(a.getType());
    setHealth(a.getHealth());
    setWeapon(a.getWeapon().getName(), a.getWeapon().getDamage());
    immunization = a.immunization;
    mutation = a.mutation;
    imm = a.imm;
    mut = a.mut;
    ver2 = a.ver2;
}
Zombie::~Zombie(){}
double Zombie::getImmunization()
{
    return immunization;
}
double Zombie::getMutation()
{
    return mutation;
}
double Zombie::getImm()
{
    return imm;
}
double Zombie::getMut()
{
    return mut;
}
bool Zombie::getVer2()
{
    return ver2;
}
void Zombie::setImmunization(double a)
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
void Zombie::setMutation(double a)
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
void Zombie::setImm(double a)
{
    imm = a;
}
void Zombie::setMut(double a)
{
    mut = a;
    if(mut >= 10)
    {
        ver2 = true;
    }
}
void Zombie::setVer2(bool a)
{
    ver2 = a;
}
bool Zombie::isValidMove(char a)
{
    if(a == 'Z')
    {
        return false;
    }
    return true;
}
