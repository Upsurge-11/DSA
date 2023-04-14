#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0)
{
  vis[row][col] = 1;
  vec.push_back({row - row0, col - col0});
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, -1, 0, 1};
  for (int i = 0; i < 4; i++)
  {
    int x = row + dx[i];
    int y = col + dy[i];
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && !vis[x][y])
      dfs(x, y, grid, vis, vec, row0, col0);
  }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  set<vector<pair<int, int>>> st;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1 && !vis[i][j])
      {
        vector<pair<int, int>> vec;
        dfs(i, j, grid, vis, vec, i, j);
        st.insert(vec);
      }
    }
  }
  return st.size();
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  }
  cout << countDistinctIslands(grid) << "\n";

  return 0;
}