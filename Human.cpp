#include <cstdlib>
#include <iostream>
#include "Human.h"


using namespace std;

Human::Human()
{
 	x = 0;
 	y = 0; 
	health = 100;
	Weapon = "none";
	
}
Human::Human(int xVal, int yVal)
{
	setX(xVal);
	setY(yVal);
	setHealth((rand()%100)+1);
	String a = weaponArr[rand()%14];
	weapon = new Weapon(a);
}
Human::Human(Human& human)
{
	
  
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




