#include <bits/stdc++.h>

using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  int n = grid.size(), m = grid[0].size();
  q.push({row, col});
  while (!q.empty())
  {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        int neighbourRow = row + i;
        int neighbourCol = col + i;
        if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && grid[neighbourRow][neighbourCol] == '1' && !vis[neighbourRow][neighbourCol])
        {
          vis[neighbourRow][neighbourCol] = 1;
          q.push({neighbourRow, neighbourCol});
        }
      }
    }
  }
}

int numIslands(vector<vector<int>> &grid)
{
  int n = grid.size(), m = grid[0].size(), count = 0;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!vis[i][j] && grid[i][j] == '1')
      {
        count++;
        bfs(i, j, vis, grid);
      }
    }
  }
  return count;
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
  cout << "Number of Islands: " << numIslands(grid) << "\n";

  return 0;
}