#include <bits/stdc++.h>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
  int n = grid.size();
  if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
    return -1;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  queue<pair<int, int>> q;
  q.push({0, 0});
  int ans = 1;
  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      pair<int, int> p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      if (i == n - 1 && j == n - 1)
        return ans;
      for (int k = 0; k < 8; k++)
      {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0)
        {
          q.push({x, y});
          grid[x][y] = 1;
        }
      }
    }
    ans++;
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
  cout << shortestPathBinaryMatrix(grid) << "\n";

  return 0;
}