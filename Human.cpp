#ifndef HUMAN_CPP
#define HUMAN_CPP
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "Human.h"
using namespace std;
Human::Human()
{
 	x = 1;
 	y = 1;
	health = 100;
    setType('H');
    moved = false;
	Weapon weapon("none",0);
}
Human::Human(int xVal, int yVal)
{
    //cout << xVal << " " << yVal << endl;
    setX(xVal);
	setY(yVal);
    setType('H');
    moved = false;
    setHealth((rand()%100)+1);
    setWeapon();
}
Human::Human(Human& human)
{
    x = human.x;
    y = human.y;
    setType('H');
    moved = false;
    health = human.health;
    Weapon weapon(human.weapon);
}
Human::~Human()
{
}
int Human::getX()
{
	return x;
}
int Human::getY()
{
	return y;
}
int Human::getHealth()
{
	return health;
}
Weapon Human::getWeapon()
{
	return weapon;
}
char Human::getType()
{
    return type;
}
bool Human::getMoved()
{
    return moved;
}
void Human::setX(int _x)
{
    if(_x < 0 || _x > 8)
	{
		cout << "Index out of bounds" << endl;
	}
	else
	{
		x = _x;
	}
}
void Human::setY(int _y)
{
    if(_y <= 0 || _y > 8)
	{
		cout << "Index out of bounds" << endl;
	}
	else
	{
		y = _y;
	}
}
void Human::setHealth(int a)
{
	if(x <= 0 || x > 100)
	{
		cout << "Invalid Health!" << endl;
	}
	else
	{
		health = a;
	}
}
void Human::increaseHealth(int b)
{
	health = health+b;
	if(health > 100)
	{
		health = 100;
	}
}
void Human::decreaseHealth(int c)
{
	health = health-c;
	if(health <= 0)
	{
		health = 0;
	}
}
void Human::setWeapon()
{
  string a = weaponArr[rand()%14];
  Weapon weapon(a);
}
void Human::setWeapon(string a, int b)
{
    Weapon weapon(a,b);
}
void Human::setMoved(bool a)
{
    moved = a;
}
void Human::move()
{
  char b = moveArr[rand()%4];
  if(b == 'U')
  {
    y = y-1;
    if(y <= 0)
    {
      y = 1;
    }
  }
  if(b == 'D')
  {
    y = y+1;
    if(y > 8)
    {
      y = 8;
    }
  }
  if(b == 'R')
  {
    x = x+1;
    if(x > 8)
    {
      x = 8;
    }
  }
  if(b == 'L')
  {
    x = x-1;
    if(x <= 0)
    {
      x = 1;
    }
  }
}
void Human::setType(char a)
{
    if(a == 'Z' || a == 'F' || a == 'E' || a == 'H')
    {
        //cout << a << endl;
        type = a;
    }
}
bool Human::isValidMove(char a)
{
    if(a == 'H')
    {
        return false;
    }
    return true;
}
Human& Human::operator=(Human* rhs)
{
    x = rhs->x;
    y = rhs->y;
    health = rhs->health;
    type = rhs->type;
    moved = rhs->moved;
    setWeapon(rhs->getWeapon().getName(), rhs->getWeapon().getDamage());
    return *this;
}
string Human::toString()
{
    ostringstream ss;
    ss << getX() << " " << getY();
    string coord = ss.str();
    ostringstream ss1;
    ss1 << getHealth();
    return "Human\nCoordinates: "+coord+"\nHealth: "+ss.str()+"Weapon\n"+weapon.toString();
}
#endif
