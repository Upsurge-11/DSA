#include <bits/stdc++.h>

using namespace std;

int func(int n, int ind, int m, bool alice, vector<int> &piles, vector<vector<vector<int>>> &dp)
{
  if (ind == n)
    return 0;
  if (dp[ind][m][alice] != -1)
    return dp[ind][m][alice];
  int ans = 0, curr = 0;
  if (alice)
  {
    for (int i = ind; i < ind + 2 * m && i < n; i++)
    {
      curr += piles[i];
      ans = max(ans, curr + func(n, i + 1, max(m, i - ind + 1), !alice, piles, dp));
    }
  }
  else
  {
    ans = 1e7;
    for (int i = ind; i < ind + 2 * m && i < n; i++)
      ans = min(ans, func(n, i + 1, max(m, i - ind + 1), !alice, piles, dp));
  }
  return dp[ind][m][alice] = ans;
}

int stoneGameII(vector<int> &piles)
{
  vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
  return func(piles.size(), 0, 1, true, piles, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> piles(n);
  for (int i = 0; i < n; i++)
    cin >> piles[i];
  cout << stoneGameII(piles) << "\n";

  return 0;
}
