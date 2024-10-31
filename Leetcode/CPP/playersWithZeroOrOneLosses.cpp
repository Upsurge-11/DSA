#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
  map<int, int> lost;
  for (auto m : matches)
  {
    if (!lost.count(m[0]))
      lost[m[0]] = 0;
    lost[m[1]]++;
  }

  vector<int> zero, ones;
  for (auto [k, l] : lost)
  {
    if (l == 0)
      zero.push_back(k);
    if (l == 1)
      ones.push_back(k);
  }

  return {zero, ones};
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matches(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> matches[i][j];
    }
  }
  vector<vector<int>> ans = findWinners(matches);
  return 0;
}