#ifndef WORLD_CPP
#define WORLD_CPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "World.h"
using namespace std;
World::World()
{
    srand(time(0));
    day = 0;
    int humansI = 0;
    int zombiesI = 0;
    int humanL = 16;
    int zombieL = 16;
    int h(0),z(0),f(0),e(0);
    grid = new Human*[8];
    for(int i=0; i<8; i++)
    {
        grid[i] = new Human[8];
    }
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
                Human temp(j+1,i+1);
                grid [i][j] = temp;//new Human(j+1,i+1);
                humansI++;
                h++;
            }
            else if(choice=='Z' && zombiesI<zombieL)
            {
                // cout << "zombies\n";
                Zombie temp(j+1,i+1);
                grid [i][j] = temp;
                zombiesI++;
                z++;
            }
            else if(choice=='H' && humansI>=humanL)
            {
                freeSpace temp(false,j+1,i+1);
                grid[i][j] = temp;
                f++;
            }
            else if(choice=='Z' && zombiesI>=zombieL)
            {
                freeSpace temp(true,j+1,i+1);
                grid[i][j] = temp;
                e++;
            }
            else if(choice=='F')
            {
                // cout << "food\n";
                freeSpace temp(false,j+1,i+1);
                grid[i][j] = temp;
                f++;
            }
            else if(choice=='E')
            {
                // cout << "empty\n";
                freeSpace temp(true,j+1,i+1);
                grid[i][j] = temp;
                e++;
            }
        }
    }
    //cout << "H: " << h << "\nZ: " << z << "\nF: " << f << "\nE: " << e << endl;
}
World::~World()
{
    delete [] *grid;
    delete [] grid;
}
int World::getDay()
{
    return day;
}
// Human* World::getHumans()
// {
//     return humans;
// }
// Zombie* World::getZombies()
// {
//     return zombies;
// }
Human** World::getGrid()
{
    return grid;
}
void World::setDay(int x)
{
    day = x;
}
// void World::setHumans(Human h[16])
// {
//     for(int i=0; i<16; i++)
//     {
//         humans[i] = h[i];
//     }
// }
// void World::setZombies(Zombie z[16])
// {
//     for(int i=0; i<16; i++)
//     {
//         zombies[i] = z[i];
//     }
// }
void World::setGrid(Human** grd)
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
            grid[i][j].setMoved(false);
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            Human curr;
            char typ;
            Human a;
            bool b;
            curr = grid[i][j];
            typ = curr.getType();
            //cout << typ << endl;
            if(typ == 'F' || typ == 'E')
            {
                continue;
            }
            else if(typ == 'H')
            {
                if(curr.getMoved() == false)
                {
                    curr.move();
                    a = grid[curr.getX()-1][curr.getY()-1];
                    b = curr.isValidMove(a.getType());
                    if(b)
                    {
                        if(a.getType()=='Z')
                        {
                            cout << "Battle Adv: Human\n";
                            a.decreaseHealth(curr.getWeapon().getDamage());
                            if(a.getHealth()<=0)
                            {
                                cout << "Zombie died\n";
                                grid[curr.getX()-1][curr.getY()-1] = curr;
                                grid[curr.getX()-1][curr.getY()-1].setMoved(true);
                                freeSpace temp(true,j+1,i+1);
                                grid[i][j] = temp;
                            }
                            else
                            {
                                curr.decreaseHealth(a.getWeapon().getDamage());
                                if(curr.getHealth()<=0)
                                {
                                    cout << "Human died\n";
                                    Zombie temp(j+1,i+1);
                                    grid[i][j] = temp;
                                }
                                else
                                {
                                    cout << "Tie\n";
                                    curr.setX(j+1);
                                    curr.setY(i+1);
                                    grid[i][j] = curr;
                                }
                            }
                        }
                        else if(a.getType()=='F')
                        {
                            cout << "Human Health++\n";
                            curr.increaseHealth(a.getHealth());
                            grid[curr.getX()-1][curr.getY()-1] = curr;
                            grid[curr.getX()-1][curr.getY()-1].setMoved(true);
                            freeSpace temp(true,j+1,i+1);
                            grid[i][j] = temp;
                        }
                        else if(a.getType()=='E')
                        {
                            grid[curr.getX()-1][curr.getY()-1] = curr;
                            grid[curr.getX()-1][curr.getY()-1].setMoved(true);
                            freeSpace temp(true,j+1,i+1);
                            grid[i][j] = temp;
                        }
                    }
                    else if(!b)
                    {
                        grid[i][j].setX(j+1);
                        grid[i][j].setY(i+1);
                    }
                }
            }
            else if(typ == 'Z')
            {
                //cout << "innn\n";
                if(curr.getMoved() == false)
                {
                    //cout << "in\n";
                    curr.move();
                    a = grid[curr.getX()-1][curr.getY()-1];
                    b = curr.isValidMove(a.getType());
                    //cout << b << endl;
                    if(b)
                    {
                        if(a.getType()=='H')
                        {
                            cout << "Battle Adv: Zombie\n";
                            a.decreaseHealth(curr.getWeapon().getDamage());
                            if(a.getHealth()<=0)
                            {
                                cout << "Human dieeed\n";
                                Zombie temp(j+1,i+1);
                                grid[curr.getX()-1][curr.getY()-1] = temp;
                                curr.setX(j+1);
                                curr.setY(i+1);
                                grid[i][j] = curr;
                            }
                            else
                            {
                                curr.decreaseHealth(a.getWeapon().getDamage());
                                if(curr.getHealth()<=0)
                                {
                                    cout << "Zombie dieeed\n";
                                    freeSpace temp(true,j+1,i+1);
                                    grid[i][j] = temp;
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
                            grid[curr.getX()-1][curr.getY()-1].setMoved(true);
                            freeSpace temp(true,j+1,i+1);
                            grid[i][j] = temp;
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
#endif
