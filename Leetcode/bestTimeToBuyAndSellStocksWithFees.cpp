#include <bits/stdc++.h>

using namespace std;

int func(int ind, bool buy, vector<int> &prices, int fee,
         vector<vector<int>> &dp) {
  if (ind >= prices.size())
    return 0;
  if (dp[ind][buy] != -1)
    return dp[ind][buy];
  if (buy)
    return dp[ind][buy] =
               max(func(ind + 1, false, prices, fee, dp) - prices[ind] - fee,
                   func(ind + 1, true, prices, fee, dp));
  else
    return dp[ind][buy] =
               max(func(ind + 1, true, prices, fee, dp) + prices[ind],
                   func(ind + 1, false, prices, fee, dp));
}

int maxProfit(vector<int> &prices, int fee) {
  vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
  return func(0, true, prices, fee, dp);
}

int main() {
  int n, fee;
  cin >> n >> fee;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  cout << maxProfit(prices, fee) << "\n";
  return 0;
}
