#include <bits/stdc++.h>

using namespace std;

void util(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<bool>> &visited)
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(move);
    return;
  }
  if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1)
  {
    visited[i][j] = true;
    util(i + 1, j, maze, n, ans, move + 'D', visited);
    visited[i][j] = false;
  }
  if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1)
  {
    visited[i][j] = true;
    util(i, j - 1, maze, n, ans, move + 'L', visited);
    visited[i][j] = false;
  }
  if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1)
  {
    visited[i][j] = true;
    util(i, j + 1, maze, n, ans, move + 'R', visited);
    visited[i][j] = false;
  }
  if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1)
  {
    visited[i][j] = true;
    util(i - 1, j, maze, n, ans, move + 'U', visited);
    visited[i][j] = false;
  }
}

vector<string> findPath(vector<vector<int>> &maze, int n)
{
  vector<string> ans;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  if (maze[0][0] == 1)
    util(0, 0, maze, n, ans, "", visited);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> maze[i][j];
  }

  vector<string> ans = findPath(maze, n);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  return 0;
}