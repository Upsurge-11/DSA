#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
  int n = mat.size(), m = mat[0].size();
  vector<vector<int>> ans(n, vector<int>(m, INT_MAX - 1));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < m; j++)
    {
      if (!mat[i][j])
      {
        ans[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  while (!q.empty())
  {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int x = p.first + dir[i].first, y = p.second + dir[i].second;
      if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] > ans[p.first][p.second] + 1)
      {
        ans[x][y] = ans[p.first][p.second] + 1;
        q.push({x, y});
      }
    }
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  vector<vector<int>> ans = updateMatrix(mat);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}