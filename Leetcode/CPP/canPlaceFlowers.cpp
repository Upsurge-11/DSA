#include <bits/stdc++.h>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
  int count = 0;
  for (int i = 0; i < flowerbed.size(); i++)
  {
    if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
    {
      flowerbed[i] = 1;
      count++;
    }
  }
  return count >= n;
}

int main()
{
  int pots, n;
  cin >> pots >> n;
  vector<int> flowerbed(pots);
  for (int i = 0; i < pots; i++)
    cin >> flowerbed[i];

  cout << canPlaceFlowers(flowerbed, n) << "\n";

  return 0;
}