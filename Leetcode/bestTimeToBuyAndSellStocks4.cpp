#include <bits/stdc++.h>

using namespace std;

int func(int ind, bool buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int cap)
{
  if (ind == prices.size() || cap == 0)
    return 0;
  if (dp[ind][buy][cap] != -1)
    return dp[ind][buy][cap];
  if (buy)
    return dp[ind][buy][cap] = max(func(ind + 1, false, prices, dp, cap) - prices[ind], func(ind + 1, true, prices, dp, cap));
  else
    return dp[ind][buy][cap] = max(func(ind + 1, true, prices, dp, cap - 1) + prices[ind], func(ind + 1, false, prices, dp, cap));
}

int maxProfit(int k, vector<int> &prices)
{
  vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
  return func(0, true, prices, dp, k);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  cout << maxProfit(k, prices) << "\n";

  return 0;
}