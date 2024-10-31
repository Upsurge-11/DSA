#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int mini = INT_MAX;
  for (int k = i; k <= j; k++)
    mini = min(mini, cuts[j + 1] - cuts[i - 1] + func(i, k - 1, cuts, dp) + func(k + 1, j, cuts, dp));
  return dp[i][j] = mini;
}

int minCost(int n, vector<int> &cuts)
{
  int c = cuts.size();
  cuts.push_back(n);
  cuts.insert(cuts.begin(), 0);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
  return func(1, c, cuts, dp);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> cuts(n);
  for (int i = 0; i < n; i++)
    cin >> cuts[i];
  cout << minCost(k, cuts) << "\n";

  return 0;
}