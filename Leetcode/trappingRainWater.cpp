#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
  int n = height.size();
  int lmax = height[0];
  int rmax = height[n - 1];
  int lpos = 1;
  int rpos = n - 2;
  int water = 0;
  while (lpos <= rpos)
  {
    if (height[lpos] >= lmax)
    {
      lmax = height[lpos];
      lpos++;
    }
    else if (height[rpos] >= rmax)
    {
      rmax = height[rpos];
      rpos--;
    }
    else if (lmax <= rmax && height[lpos] < lmax)
    {
      water += lmax - height[lpos];
      lpos++;
    }
    else
    {
      water += rmax - height[rpos];
      rpos--;
    }
  }
  return water;
}

int main()
{
  int n;
  cin >> n;
  vector<int> height(n);
  for (int i = 0; i < n; i++)
    cin >> height[i];

  cout << trap(height) << "\n";

  return 0;
}