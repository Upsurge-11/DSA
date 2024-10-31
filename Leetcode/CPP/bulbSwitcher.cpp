#include <bits/stdc++.h>

using namespace std;

int bulbSwitch(int n)
{
  int count = 0;
  for (int i = 1; i * i <= n; i++)
    count++;
  return count;
}

int main()
{
  int n;
  cin >> n;
  cout << bulbSwitch(n) << "\n";

  return 0;
}