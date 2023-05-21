#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, unordered_set<int> &visited)
{
  int m = grid.size();
  int n = grid[0].size();
  if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || visited.find(i * n + j) != visited.end())
    return;
  visited.insert(i * n + j);
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  for (auto dir : directions)
  {
    int ni = i + dir[0];
    int nj = j + dir[1];
    dfs(grid, ni, nj, visited);
  }
}

int shortestBridge(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  bool found = false;
  unordered_set<int> visited;
  for (int i = 0; i < m; i++)
  {
    if (found)
      break;
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == 1)
      {
        dfs(grid, i, j, visited);
        found = true;
        break;
      }
    }
  }

  queue<int> q;
  for (int cell : visited)
    q.push(cell);

  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int level = 0;

  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      int curr = q.front();
      q.pop();
      int currI = curr / n;
      int currJ = curr % n;
      for (auto dir : directions)
      {
        int ni = currI + dir[0];
        int nj = currJ + dir[1];
        int neighbor = ni * n + nj;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited.find(neighbor) == visited.end())
        {
          if (grid[ni][nj] == 1)
            return level;
          q.push(neighbor);
          visited.insert(neighbor);
        }
      }
    }
    level++;
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  cout << shortestBridge(grid) << "\n";

  return 0;
}