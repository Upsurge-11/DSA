#include <bits/stdc++.h>

using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
  int n = mat.size();
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += mat[i][i];
    sum += mat[i][n - i - 1];
  }

  return n % 2 == 0 ? sum : sum - mat[n / 2][n / 2];
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];
  }

  cout << diagonalSum(mat) << "\n";

  return 0;
}