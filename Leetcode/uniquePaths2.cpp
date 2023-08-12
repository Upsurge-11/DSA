#include <bits/stdc++.h>

using namespace std;

int func(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
  if (row == obstacleGrid.size() || col == obstacleGrid[0].size())
    return 0;
  if (dp[row][col] != -1)
    return dp[row][col];
  if (obstacleGrid[row][col] == 1)
    return 0;
  if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1)
    return 1;
  return dp[row][col] = func(row + 1, col, obstacleGrid, dp) + func(row, col + 1, obstacleGrid, dp);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
  vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
  return func(0, 0, obstacleGrid, dp);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> obstacleGrid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> obstacleGrid[i][j];
  }
  cout << uniquePathsWithObstacles(obstacleGrid) << "\n";

  return 0;
}