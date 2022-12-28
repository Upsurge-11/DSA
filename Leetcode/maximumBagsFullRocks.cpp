#include <bits/stdc++.h>

using namespace std;

int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
{
  vector<int> remain;
  for (int i = 0; i < rocks.size(); i++)
    remain.push_back(capacity[i] - rocks[i]);
  sort(remain.begin(), remain.end());
  int i = 0;
  while (additionalRocks > 0 && i < capacity.size())
  {
    additionalRocks -= remain[i];
    i++;
  }
  return additionalRocks < 0 ? i - 1 : i;
}

int main()
{
  int n, additionalRocks;
  cin >> n >> additionalRocks;
  vector<int> capacity(n), rocks(n);

  for (int i = 0; i < n; i++)
  {
    cin >> capacity[i] >> rocks[i];
  }

  cout << maximumBags(capacity, rocks, additionalRocks);

  return 0;
}