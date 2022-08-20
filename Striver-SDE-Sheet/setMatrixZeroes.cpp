// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &v)
{
  vector<int> column(v[0].size(), 1);
  vector<int> row(v.size(), 1);
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[0].size(); j++)
    {
      if (v[i][j] == 0)
      {
        column[j] = 0;
        row[i] = 0;
      }
    }
  }
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[0].size(); j++)
    {
      if (column[j] == 0 || row[i] == 0)
      {
        v[i][j] = 0;
      }
    }
    cout << "\n";
  }
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> v(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> v[i][j];
    }
  }

  setZeroes(v);

  return 0;
}