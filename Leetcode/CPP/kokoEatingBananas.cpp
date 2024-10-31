#include <bits/stdc++.h>

using namespace std;

int canEatAll(vector<int> &piles, int speed)
{
  int time = 0;
  for (int i = 0; i < piles.size(); i++)
  {
    time += ceil((double)piles[i] / (double)speed);
    if (time > 1e9)
      return -1;
  }
  return time;
}

int minEatingSpeed(vector<int> &piles, int h)
{
  int left = 1;
  int right = *max_element(piles.begin(), piles.end());
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (canEatAll(piles, mid) <= h && canEatAll(piles, mid) != -1)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return left;
}

int main()
{
  int n, h;
  cin >> n >> h;
  vector<int> piles(n);
  for (int i = 0; i < n; i++)
    cin >> piles[i];
  cout << minEatingSpeed(piles, h) << "\n";

  return 0;
}
