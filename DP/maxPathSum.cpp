#include <bits/stdc++.h>

using namespace std;

int func(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
  if (row == 0)
    return grid[row][col];
  if (row < 0 || col < 0 || col >= grid.size())
    return INT_MIN;
  if (dp[row][col] != -1)
    return dp[row][col];
  int up = func(grid, row - 1, col, dp) + grid[row][col];
  int left = func(grid, row - 1, col - 1, dp) + grid[row][col];
  int right = func(grid, row - 1, col + 1, dp) + grid[row][col];
  return dp[row][col] = max(up, max(left, right));
}

int maxPathSum(vector<vector<int>> &grid)
{
  int ans = INT_MIN;
  vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
  for (int i = 0; i < grid[0].size(); i++)
    ans = max(ans, func(grid, grid.size() - 1, i, dp));
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  }
  cout << maxPathSum(grid) << "\n";

  return 0;
}