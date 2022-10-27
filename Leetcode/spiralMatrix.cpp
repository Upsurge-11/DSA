#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
}

int main()
{
  int m, n;
  cin >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  vector<int> ans = spiralOrder(matrix);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  cout << "\n";

  return 0;
}