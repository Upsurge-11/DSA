#include <bits/stdc++.h>

using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
  int trials = minutesToTest / minutesToDie;
  trials++;
  int pig = 0, x = 1;
  while (x < buckets)
  {
    x *= trials;
    pig++;
  }
  return pig;
}

int main()
{
  int buckets, minutesToDie, minutesToTest;
  cin >> buckets >> minutesToDie >> minutesToTest;
  cout << poorPigs(buckets, minutesToDie, minutesToTest) << "\n";
  return 0;
}