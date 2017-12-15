#ifndef FREE_SPACE_H
#define FREE_SPACE_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class freeSpace : public Human
{
    public:
        freeSpace(bool,int,int);
        freeSpace& operator=(freeSpace*);
        string toString();
    private:
        string spot;
};
#endif
