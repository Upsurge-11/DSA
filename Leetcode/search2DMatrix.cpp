#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix[0].size(), m = matrix.size(), row = 0;
  for (int i = 0; i < n; i++)
  {
    if (matrix[i][0] == target)
      return true;
    if (matrix[i][0] > target && i > 0)
    {
      row == i - 1;
      break;
    }
  }
  for (int i = 0; i < m; i++)
  {
    if (matrix[row][i] == target)
      return true;
  }
  return false;
}

int main()
{
  int n, m, target;
  cin >> n >> m >> target;
  vector<vector<int>> matrix(m);

  for (int i = 0; i < m; i++)
  {
    vector<int> row(n);
    for (int j = 0; j < n; j++)
    {
      cin >> row[j];
    }
    matrix.push_back(row);
  }

  if (searchMatrix(matrix, target))
  {
    cout << "Target Found\n";
  }
  else
  {
    cout << "Target Not Found\n";
  }

  return 0;
}