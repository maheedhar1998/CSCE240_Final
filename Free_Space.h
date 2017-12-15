#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class freeSpace : public Human
{
    public:
        freeSpace(bool,int,int);
        freeSpace& operator=(freeSpace*);
    private:
        string spot;
};
