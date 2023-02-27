#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, int newColor, int iniColor, vector<vector<int>> &ans, vector<vector<int>> &image, vector<int> &deltaRow, vector<int> &deltaCol)
{
  ans[row][col] = newColor;
  for (int i = 0; i < 4; i++)
  {
    int nrow = row + deltaRow[i];
    int ncol = col + deltaCol[i];
    if (nrow >= 0 && nrow < image.size() && ncol >= 0 && ncol <= image[0].size() && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
    {
      dfs(nrow, ncol, newColor, iniColor, ans, image, deltaRow, deltaCol);
    }
  }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
  int iniColor = image[sr][sc];
  vector<vector<int>> ans = image;
  vector<int> deltaRow = {-1, 0, 1, 0};
  vector<int> deltaCol = {0, 1, 0, -1};
  dfs(sr, sc, newColor, iniColor, ans, image, deltaRow, deltaCol);
  return ans;
}

int main()
{
  int n, m, newColor, sr, sc;
  cin >> n >> m >> newColor >> sr >> sc;

  vector<vector<int>> image(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> image[i][j];
  }

  vector<vector<int>> result = floodFill(image, sr, sc, newColor);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[0].size(); j++)
      cout << image[i][j] << " ";
    cout << "\n";
  }

  return 0;
}