#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
private:
  int b, m, s;

public:
  ParkingSystem(int big, int medium, int small)
  {
    b = big;
    m = medium;
    s = small;
  }

  bool addCar(int carType)
  {
    if (carType == 1 && b > 0)
    {
      b--;
      return true;
    }
    else if (carType == 2 && m > 0)
    {
      m--;
      return true;
    }
    else if (carType == 3 && s > 0)
    {
      s--;
      return true;
    }
    return false;
  }
};

int main()
{

  return 0;
}