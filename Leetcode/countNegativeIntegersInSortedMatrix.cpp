#include <bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  int i = 0, j = n - 1, count = 0;
  while (i < m && j >= 0) {
    if (grid[i][j] < 0) {
      count += m - i;
      j--;
    } else {
      i++;
    }
  }
  return count;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  cout << countNegatives(grid) << "\n";
  return 0;
}
