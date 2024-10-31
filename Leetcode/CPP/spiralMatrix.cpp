#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  vector<int> ans;
  int m = matrix.size();
  int n = matrix[0].size();
  int top = 0, bottom = m - 1, left = 0, right = n - 1;
  int dir = 0;
  while (top <= bottom && left <= right)
  {
    if (dir == 0)
    {
      for (int i = left; i <= right; i++)
        ans.push_back(matrix[top][i]);
      top++;
    }
    else if (dir == 1)
    {
      for (int i = top; i <= bottom; i++)
        ans.push_back(matrix[i][right]);
      right--;
    }
    else if (dir == 2)
    {
      for (int i = right; i >= left; i--)
        ans.push_back(matrix[bottom][i]);
      bottom--;
    }
    else if (dir == 3)
    {
      for (int i = bottom; i >= top; i--)
        ans.push_back(matrix[i][left]);
      left++;
    }
    dir = (dir + 1) % 4;
  }
  return ans;
}

int main()
{
  int m, n;
  cin >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  }
  vector<int> ans = spiralOrder(matrix);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  cout << "\n";

  return 0;
}