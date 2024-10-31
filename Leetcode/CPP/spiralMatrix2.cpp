#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
  int num = 1;
  while (rowStart <= rowEnd && colStart <= colEnd)
  {
    for (int i = colStart; i <= colEnd; i++)
      matrix[rowStart][i] = num++;
    rowStart++;
    for (int i = rowStart; i <= rowEnd; i++)
      matrix[i][colEnd] = num++;
    colEnd--;
    if (rowStart <= rowEnd)
    {
      for (int i = colEnd; i >= colStart; i--)
        matrix[rowEnd][i] = num++;
    }
    rowEnd--;
    if (colStart <= colEnd)
    {
      for (int i = rowEnd; i >= rowStart; i--)
        matrix[i][colStart] = num++;
    }
    colStart++;
  }
  return matrix;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix = generateMatrix(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << "\n";
  }

  return 0;
}