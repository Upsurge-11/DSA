#include <bits/stdc++.h>

using namespace std;

int mirrorReflection(int p, int q)
{
  while (p % 2 == 0 && q % 2 == 0)
  {
    p /= 2;
    q /= 2;
  }
  if (q % 2 == 0)
    return 0;
  else if (q % 2 != 0 && p % 2 != 0)
    return 1;
  else
    return 2;
}

int main()
{
  int p, q;
  cin >> p >> q;
  cout << mirrorReflection(p, q) << "\n";
  return 0;
}