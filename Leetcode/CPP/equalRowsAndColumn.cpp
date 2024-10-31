#include <bits/stdc++.h>

using namespace std;

int equalPairs(vector<vector<int>> &grid) {
  int n = grid.size(), ans = 0;
  map<vector<int>, int> freq;
  for (int i = 0; i < n; i++) {
    freq[grid[i]]++;
  }
  for (int i = 0; i < n; i++) {
    vector<int> col;
    for (int j = 0; j < n; j++) {
      col.emplace_back(grid[j][i]);
    }
    ans += freq[col];
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cout << equalPairs(grid) << "\n";

  return 0;
}
