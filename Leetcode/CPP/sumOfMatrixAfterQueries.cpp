#include <bits/stdc++.h>

using namespace std;

// 2718. Sum of Matrix After Queries

long long matrixSumQueries(int n, vector<vector<int>> &queries) {
  long long ans = 0;
  int row = n, col = n;
  vector<int> visrow(n, 0), viscol(n, 0);
  for (int i = queries.size() - 1; i >= 0; i--) {
    int type = queries[i][0];
    int index = queries[i][1];
    int value = queries[i][2];
    if (type == 0 && !visrow[index]) {
      ans += value * col;
      visrow[index] = 1;
      row--;
    } else if (type == 1 && !viscol[index]) {
      ans += value * row;
      viscol[index] = 1;
      col--;
    }
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> queries(x, vector<int>(3));
  for (int i = 0; i < x; i++) {
    cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
  }
  cout << matrixSumQueries(n, queries) << "\n";
  return 0;
}
