#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
  vector<int> column(matrix[0].size(), 1);
  vector<int> row(matrix.size(), 1);
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (matrix[i][j] == 0)
      {
        column[j] = 0;
        row[i] = 0;
      }
    }
  }
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (column[j] == 0 || row[i] == 0)
      {
        matrix[i][j] = 0;
      }
    }
    cout << "\n";
  }
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  setZeroes(matrix);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}