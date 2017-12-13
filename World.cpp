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
        humans.push_back(Human());
        zombies.push_back(Zombie(0,0));
    }
    int humansI = 0;
    int zombiesI = 0;
    int humanL = 16;
    int zombieL = 16;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int opt = rand()%4;
            char options[4] = {'E','F','H','Z'};
            char choice = options[opt];
            if(choice=='H' && humansI<humanL)
            {
                humans.at(humansI) = Human(i+1,j+1);
                grid [i][j] = humans.at(humansI);
                humansI++;
            }
            else if(choice=='Z' && zombiesI<zombieL)
            {
                zombies.at(zombiesI) = Zombie(i+1,j+1);
                grid [i][j] = zombies.at(zombiesI);
                zombiesI++;
            }
            else if(choice=='F')
            {
                grid [i][j] = freeSpace(false,i+1,j+1);
            }
            else if(choice=='E')
            {
                grid [i][j] = freeSpace(true,i+1,j+1);
            }
        }
    }
}
World::~World(){}
int World::getDay()
{
    return day;
}
vector<Human> World::getHumans()
{
    return humans;
}
vector<Zombie> World::getZombies()
{
    return zombies;
}
Human[][] World::getGrid()
{
    return grid;
}
void World::setDay(int x)
{
    day = x;
}
void World::setHumans(vector<Human> h)
{
    humans = h;
}
void World::setZombies(vector<Zombie> z)
{
    zombies = z;
}
void World::setGrid(Human[][] grd)
{
    grid = grd;
}
void World::updateGrid()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            Human curr = grid[i][j];
            char typ = curr.getType();
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
                            grid[i][j] = new freeSpace(true,i+1,j+1);
                        }
                        else
                        {
                            curr.decreaseHealth(a.getWeapon().getDamage());
                            if(curr.getHealth()<=0)
                            {
                                grid[i][j] = new Zombie(i+1,j+1);
                            }
                            else
                            {
                                curr.setX(i+1);
                                curr.setY(j+1);
                                grid[i][j] = curr;
                            }
                        }
                    }
                    else if(a.getType()=='F')
                    {
                        curr.increaseHealth(a.getHealth());
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,i+1,j+1);
                    }
                    else if(a.getType()=='E')
                    {
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,i+1,j+1);
                    }
                }
                else if(!b)
                {
                    grid[i][j].setX(i+1);
                    grid[i][j].setY(j+1);
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
                            grid[curr.getX()-1][curr.getY()-1] = new Zombie(i+1,j+1);
                            curr.setX(i+1);
                            curr.setY(j+1);
                            grid[i][j] = curr;
                        }
                        else
                        {
                            curr.decreaseHealth(a.getWeapon().getDamage());
                            if(curr.getHealth()<=0)
                            {
                                grid[i][j] = new freeSpace(true,i+1,j+1);
                            }
                            else
                            {
                                curr.setX(i+1);
                                curr.setY(j+1);
                                grid[i][j] = curr;
                            }
                        }
                    }
                    else if(a.getType()=='E' || a.getType()=='F')
                    {
                        grid[curr.getX()-1][curr.getY()-1] = curr;
                        grid[i][j] = new freeSpace(true,i+1,j+1);
                    }
                }
                else if(!b)
                {
                    grid[i][j].setX(i);
                    grid[i][j].setY(j);
                }
            }
        }
    }
    ++day;
}
void World::printLn()
{
    for(int i=0; i<17; i++)
    {
        cout << "_";
    }
    cout << endl;
}
void World::printGrid()
{
    cout << "Days: " << day << endl;
    printLn();
    for(int i=0; i<8; i++)
    {
        cout << "| ";
        for(int j=0; j<8; j++)
        {
            cout << grid[i][j].getType() << " |";
        }
        cout << endl;
        printLn();
    }
}
