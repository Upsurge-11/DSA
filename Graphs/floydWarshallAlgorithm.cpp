#include <bits/stdc++.h>

using namespace std;

void shortestDistance(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
          continue;
        if (matrix[i][j] > matrix[i][k] + matrix[k][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  }
  shortestDistance(matrix);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << matrix[i][j] << " ";
    cout << "\n";
  }

  return 0;
}