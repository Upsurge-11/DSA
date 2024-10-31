#include <bits/stdc++.h>

using namespace std;

double func(int n, int k, int r, int c, vector<vector<vector<double>>> &dp)
{
  if (r < 0 || c < 0 || r >= n || c >= n)
    return 0;
  if (k == 0)
    return 1;
  if (dp[r][c][k] != -1)
    return dp[r][c][k];
  vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
  vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
  double ans = 0;
  for (int i = 0; i < 8; i++)
    ans += func(n, k - 1, r + dx[i], c + dy[i], dp) / 8;
  return dp[r][c][k] = ans;
}
double knightProbability(int n, int k, int r, int c)
{
  vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
  return func(n, k, r, c, dp);
}

int main()
{
  int n, k, r, c;
  cin >> n >> k >> r >> c;
  cout << knightProbability(n, k, r, c) << "\n";
  return 0;
}