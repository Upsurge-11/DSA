#include <bits/stdc++.h>

using namespace std;

int paths(int i, int j, int &m, int &n, vector<vector<int>> &dp)
{
  if (i == m - 1 || j == n - 1)
    return 1;
  if (dp[i][j] != 0)
    return dp[i][j];
  dp[i][j] = paths(i, j + 1, m, n, dp) + paths(i + 1, j, m, n, dp);
  return dp[i][j];
}

int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, 0));
  return paths(0, 0, m, n, dp);
}

int main()
{
  int m, n;
  cin >> m >> n;
  int ans = uniquePaths(m, n);
  cout << ans << "\n";
  return 0;
}