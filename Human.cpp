#include <cstdlib>
#include <iostream>
#include "Human.h"
using namespace std;
Human::Human()
{
 	x = 0;
 	y = 0;
	health = 100;
    type = 'H';
	Weapon weapon("none",0);
}
Human::Human(int xVal, int yVal)
{
	setX(xVal);
	setY(yVal);
    type = 'H';
	setHealth((rand()%100)+1);
    setWeapon();
}
Human::Human(Human& human)
{
    x = human.x;
    y = human.y;
    type = 'H';
    health = human.health;
    weapon =  human.weapon;
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
char getType()
{
    return type;
}
void Human::setX(int _x)
{
	if(x <= 0 || x > 8)
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
	if(y <= 0 || y > 8)
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
  String a = weaponArr[rand()%14];
  Weapon weapon(a);
}
void Human::setWeapon(string a, int b)
{
    weapon = new Weapon(a,b);
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
