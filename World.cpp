#include <iostream>
#include <cstdlib>
#include <string>
#include "World.h"
using namespace std;
World::World()
{
    day = 0;
    for(int i=0; i<16; i++)
    {
        Human humans[i] = *(new Human());
        Zombie zombies[i] = *(new Zombie());
    }
    int humansI = 0;
    int zombiesI = 0;
    int humanL = 16;
    int zombieL = 16;
    int h(0),z(0),f(0),e(0);
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            //cout << i << " " << j;
            int opt = rand()%4;
            char options[4] = {'E','F','H','Z'};
            char choice = options[opt];
            if(choice=='H' && humansI<humanL)
            {
                // cout << "humans\n";
                humans[humansI] = new Human(j+1,i+1);
                grid [i][j] = humans[humansI];
                humansI++;
                h++;
            }
            else if(choice=='Z' && zombiesI<zombieL)
            {
                // cout << "zombies\n";
                zombies[zombiesI] = new Zombie(j+1,i+1);
                grid [i][j] = zombies[zombiesI];
                zombiesI++;
                z++;
            }
            else if(choice=='F')
            {
                // cout << "food\n";
                grid[i][j] = new freeSpace(false,j+1,i+1);
                f++;
            }
            else if(choice=='E')
            {
                // cout << "empty\n";
                grid[i][j] = new freeSpace(true,j+1,i+1);
                e++;
            }
        }
    }
    cout << "H: " << h << "\nZ: " << z << "\nF: " << f << "\nE: " << e << endl;
}
World::~World(){}
int World::getDay()
{
    return day;
}
Human* World::getHumans()
{
    return humans;
}
Zombie* World::getZombies()
{
    return zombies;
}
/*Human* World::getGrid()
{
    return grid;
}*/
void World::setDay(int x)
{
    day = x;
}
void World::setHumans(Human h[16])
{
    for(int i=0; i<16; i++)
    {
        humans[i] = h[i];
    }
}
void World::setZombies(Zombie z[16])
{
    for(int i=0; i<16; i++)
    {
        zombies[i] = z[i];
    }
}
void World::setGrid(Human grd[8][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            grid[i][j] = grd[i][j];
        }
    }
}
void World::updateGrid()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            Human curr = grid[i][j];
            char typ = curr.getType();
            Human a;
            bool b;
            if(typ == 'F' || typ == 'E')
            {
                continue;
            }
            else if(typ == 'H')
            {
                curr.move();
                a = grid[curr.getX()-1][curr.getY()-1];
                b = curr.isValidMove(a.getType());
                if(b)
                {
                    if(a.getType()=='Z')
                    {
                        a.decreaseHealth(curr.getWeapon().getDamage());
                        if(a.getHealth()<=0)
                        {
                            grid[curr.getX()-1][curr.getY()-1] = curr;
                            grid[i][j] = new freeSpace(true,j+1,i+1);
                        }
                        else
                        {
                            curr.decreaseHealth(a.getWeapon().getDamage());
                            if(curr.getHealth()<=0)
                            {
                                grid[i][j] = new Zombie(j+1,i+1);
                            }
                            else
                            {
                                curr.setX(j+1);
                                curr.setY(i+1);
                                grid[i][j] = curr;
                            }
                        }
                    }
                    else if(a.getType()=='F')
                    {
                        curr.increaseHealth(a.getHealth());
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,j+1,i+1);
                    }
                    else if(a.getType()=='E')
                    {
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,j+1,i+1);
                    }
                }
                else if(!b)
                {
                    grid[i][j].setX(j+1);
                    grid[i][j].setY(i+1);
                }
            }
            else if(typ == 'Z')
            {
                curr.move();
                a = grid[curr.getX()-1][curr.getY()-1];
                b = curr.isValidMove(a.getType());
                if(b)
                {
                    if(a.getType()=='H')
                    {
                        a.decreaseHealth(curr.getWeapon().getDamage());
                        if(a.getHealth()<=0)
                        {
                            grid[curr.getX()-1][curr.getY()-1] = new Zombie(j+1,i+1);
                            curr.setX(j+1);
                            curr.setY(i+1);
                            grid[i][j] = curr;
                        }
                        else
                        {
                            curr.decreaseHealth(a.getWeapon().getDamage());
                            if(curr.getHealth()<=0)
                            {
                                grid[i][j] = new freeSpace(true,j+1,i+1);
                            }
                            else
                            {
                                curr.setX(j+1);
                                curr.setY(i+1);
                                grid[i][j] = curr;
                            }
                        }
                    }
                    else if(a.getType()=='E' || a.getType()=='F')
                    {
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,j+1,i+1);
                    }
                }
                else if(!b)
                {
                    grid[i][j].setX(j);
                    grid[i][j].setY(i);
                }
            }
        }
    }
    ++day;
}
void World::printLn()
{
    for(int i=0; i<33; i++)
    {
        cout << "-";
    }
    cout << endl;
}
void World::printGrid()
{
    cout << "Days: " << day << endl;
    printLn();
    for(int i=0; i<8; i++)
    {
        cout << "|";
        for(int j=0; j<8; j++)
        {
            char temp = grid[i][j].getType();
            if(temp == 'E' || temp == 'F')
            {
                temp = ' ';
            }
            cout << " " << temp << " |";
        }
        cout << endl;
        printLn();
    }
}
