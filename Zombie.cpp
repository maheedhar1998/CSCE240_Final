#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Zombie.h"
using namespace std;
Zombie::Zombie() : Human()
{
    setType('Z');
    imm = 0;
    mut = 0;
    ver2 = false;
    immunization = 0;
    mutation = 0;
}
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
Zombie& Zombie::operator=(Zombie* rhs)
{
    setX(rhs->getX());
    setY(rhs->getY());
    setHealth(rhs->getHealth());
    setType(rhs->getType());
    setMoved(rhs->getMoved());
    setWeapon(rhs->getWeapon().getName(), rhs->getWeapon().getDamage());
    immunization = rhs->immunization;
    imm = rhs->imm;
    mutation = rhs->mutation;
    mut = rhs->mut;
    ver2 = rhs->ver2;
    return *this;
}
string Zombie::toString()
{
    ostringstream ss;
    ss << getX() << " " << getY();
    string coord = ss.str();
    ostringstream ss1;
    ss1 << getHealth();
    string hlth = ss1.str();
    ostringstream ss2;
    ss2 << immunization << "\nImmunity: " << imm << "\nRate of Mutation: " << mutation << "\nMutation: " << mut;
    string v2 = "no";
    if(ver2)
        v2 = "yes";
    return "Zombie\nCoordinates: "+coord+"\nHealth: "+hlth+"Weapon\n"+getWeapon().toString()+"Rate of Immunization: "+ss2.str()+"\nVersion 2.0: "+v2;
}
#endif
