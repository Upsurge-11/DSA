// Given an integer numRows, return the first numRows of Pascal's triangle.

#include <bits/stdc++.h>

using namespace std;

// vector<vector<int>> generate(int numRows)
// {
//   vector<vector<int>> v(numRows);
//   v[0].push_back(1);
//   v[1].push_back(1);
//   v[1].push_back(1);

//   for (int i = 2; i < numRows; i++)
//   {
//     // vector<int> temp(i + 1, 0);
//     // v[i] = temp;
//     for (int j = 0; j <= i; j++)
//     {
//       if (j == 0 || j == (i))
//       {
//         v[i].push_back(1);
//       }
//       else
//       {
//         v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]);
//       }
//     }
//   }

//   return v;
// }

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> v(numRows);
  for (int i = 0; i < numRows; i++)
  {
    v[i].resize(i + 1);
    v[i][0] = v[i][i] = 1;
    for (int j = 0; j < i; j++)
    {
      v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
    }
  }
  return v;
}

int main()
{
  int numRows;
  cin >> numRows;
  vector<vector<int>> ans = generate(numRows);

  return 0;
}