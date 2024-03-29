#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;
class Zombie: public Human
{
    public:
        Zombie();
        Zombie(int,int); //: Human(a,b);
        Zombie(double,double,Human&);//: Human(Human&);
        Zombie(Zombie&);
        ~Zombie();
        double getImmunization();
        double getMutation();
        double getImm();
        double getMut();
        bool getVer2();
        void setImmunization(double);
        void setMutation(double);
        void setImm(double);
        void setMut(double);
        void setVer2(bool);
        bool isValidMove(char);
        Zombie& operator=(Zombie*);
        string toString();
    private:
        double immunization;
        double mutation;
        double imm;
        double mut;
        bool ver2;
};
#endif
