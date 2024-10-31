#include <bits/stdc++.h>

using namespace std;

vector<int> findBall(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<int> ans;
  for (int j = 0; j < n; j++)
  {
    int row = 0, col = j;
    while (row < m)
    {
      if (grid[row][col] == 1)
      {
        if (col + 1 >= n || grid[row][col + 1] == -1)
        {
          ans.push_back(-1);
          break;
        }
        col++;
      }
      else if (grid[row][col] == -1)
      {
        if (col - 1 < 0 || grid[row][col - 1] == 1)
        {
          ans.push_back(-1);
          break;
        }
        col--;
      }
      row++;
    }
    if (row == m)
    {
      ans.push_back(col);
    }
  }
  return ans;
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<int> ans = findBall(grid);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}