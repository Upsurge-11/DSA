#include <bits/stdc++.h>

using namespace std;

int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
  vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < group.size(); i++)
  {
    for (int j = n; j >= group[i]; j--)
    {
      for (int k = minProfit; k >= 0; k--)
      {
        dp[j][k] += dp[j - group[i]][max(0, k - profit[i])];
        dp[j][k] %= 1000000007;
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= n; i++)
  {
    res += dp[i][minProfit];
    res %= 1000000007;
  }
  return res;
}

int main()
{
  int n, minProfit, groupSize, profitSize;
  cin >> n >> minProfit >> groupSize >> profitSize;
  vector<int> group(groupSize), profit(profitSize);
  for (int i = 0; i < groupSize; i++)
    cin >> group[i];
  for (int i = 0; i < profitSize; i++)
    cin >> profit[i];
  cout << profitableSchemes(n, minProfit, group, profit) << "\n";

  return 0;
}