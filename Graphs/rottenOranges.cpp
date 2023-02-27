#include <bits/stdc++.h>

using namespace std;

int orangeRotting(vector<vector<int>> &grid)
{
  int n = grid.size(), m = grid[0].size(), countFresh = 0;
  queue<pair<pair<int, int>, int>> q;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][i] == 2)
      {
        q.push({{i, j}, 0});
        vis[i][j] = 1;
      }
      if (grid[i][j] == 1)
        countFresh++;
    }
  }
  int tm = 0, rotted = 0;
  vector<int> delRow = {-1, 0, 1, 0};
  vector<int> delCol = {0, 1, 0, -1};
  while (!q.empty())
  {
    int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
    tm = max(t, tm);
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nrow = r + delRow[i];
      int ncol = c + delCol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 0 && grid[nrow][ncol] == 1)
      {
        q.push({{nrow, ncol}, t + 1});
        vis[nrow][ncol] = 1;
        rotted++;
      }
    }
  }
  if (countFresh != rotted)
    return -1;

  return tm;
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

  cout << orangeRotting(grid) << "\n";

  return 0;
}