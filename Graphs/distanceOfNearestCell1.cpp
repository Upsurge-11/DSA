#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nearestCell1(vector<vector<int>> &grid)
{
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<int>> dist(n, vector<int>(m, 0));
  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1)
      {
        q.push({{i, j}, 0});
        vis[i][j] = 1;
      }
      else
      {
        vis[i][j] = 0;
      }
    }
  }
  while (!q.empty())
  {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int steps = q.front().second;
    q.pop();
    dist[row][col] = steps;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
      int x = row + dx[i];
      int y = col + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0)
      {
        q.push({{x, y}, steps + 1});
        vis[x][y] = 1;
      }
    }
  }
  return dist;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<int>> ans = nearestCell1(grid);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
  }
  cout << "\n";
  return 0;
}