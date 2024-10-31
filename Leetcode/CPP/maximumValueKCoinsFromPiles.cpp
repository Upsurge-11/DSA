#include <bits/stdc++.h>

using namespace std;

int coinSelector(int ind, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
{
  if (dp[ind][k] > 0)
    return dp[ind][k];
  if (ind == piles.size() || k == 0)
    return 0;
  int ans = coinSelector(ind + 1, k, piles, dp), curr = 0;
  for (int i = 0; i < piles[ind].size() && i < k; i++)
  {
    curr += piles[ind][i];
    ans = max(ans, coinSelector(ind + 1, k - i - 1, piles, dp) + curr);
  }
  dp[ind][k] = ans;
  return ans;
}

int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
  vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, 0));
  return coinSelector(0, k, piles, dp);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> piles(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vector<int> temp(x);
    for (int j = 0; j < x; j++)
      cin >> temp[j];
    piles[i] = temp;
  }
  cout << maxValueOfCoins(piles, k) << "\n";

  return 0;
}