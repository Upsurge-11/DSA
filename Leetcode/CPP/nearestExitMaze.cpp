#include <bits/stdc++.h>

using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
  int n = maze.size();
  int m = maze[0].size();
  int x = entrance[0];
  int y = entrance[1];
  int ans = 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  maze[x][y] = '+';
  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      auto curr = q.front();
      q.pop();
      int i = curr.first;
      int j = curr.second;
      if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (i != x || j != y))
        return ans;
      if (i > 0 && maze[i - 1][j] == '.')
      {
        q.push({i - 1, j});
        maze[i - 1][j] = '+';
      }
      if (i < n - 1 && maze[i + 1][j] == '.')
      {
        q.push({i + 1, j});
        maze[i + 1][j] = '+';
      }
      if (j > 0 && maze[i][j - 1] == '.')
      {
        q.push({i, j - 1});
        maze[i][j - 1] = '+';
      }
      if (j < m - 1 && maze[i][j + 1] == '.')
      {
        q.push({i, j + 1});
        maze[i][j + 1] = '+';
      }
    }
    ans++;
  }
  return -1;
}

int main()
{

  return 0;
}