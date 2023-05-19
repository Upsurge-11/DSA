#include <bits/stdc++.h>

using namespace std;

int func(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
  if (ind == 0)
    return (amount % coins[0] == 0);
  if (dp[ind][amount] != -1)
    return dp[ind][amount];
  int nonTake = func(ind - 1, amount, coins, dp);
  int take = 0;
  if (amount >= coins[ind])
    take = func(ind, amount - coins[ind], coins, dp);
  return dp[ind][amount] = nonTake + take;
}

int change(int amount, vector<int> &coins)
{
  vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
  return func(coins.size() - 1, amount, coins, dp);
}

int main()
{
  int n, amount;
  cin >> n >> amount;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  cout << change(amount, coins) << "\n";

  return 0;
}