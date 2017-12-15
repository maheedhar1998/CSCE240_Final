#include <iostream>
#include <cstdlib>
#include <string>
#include "World.cpp"
using namespace std;
int main()
{
  World universe;
  for(int i=0; i<50; i++)
  {
      char ans;
      universe.printGrid();
      cout << "See next Day: y/n\n";
      cin >> ans;
      if(ans=='y')
      {
          universe.updateGrid();
      }
      else
      {
          exit(0);
      }
  }
}
