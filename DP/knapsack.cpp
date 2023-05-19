#include <bits/stdc++.h>

using namespace std;

int knapsack(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
  if (ind == 0)
    return (wt[0] <= W) ? val[0] : 0;
  if (dp[ind][W] != -1)
    return dp[ind][W];
  int nonTake = knapsack(ind - 1, W, val, wt, dp);
  int take = INT_MIN;
  if (W >= wt[ind])
    take = val[ind] + knapsack(ind, W - wt[ind], val, wt, dp);
  return dp[ind][W] = max(nonTake, take);
}

int main()
{
  int n, W;
  cin >> n >> W;
  vector<int> val(n), wt(n);
  for (int i = 0; i < n; i++)
    cin >> val[i] >> wt[i];
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  cout << knapsack(n - 1, W, val, wt, dp) << "\n";
  return 0;
}