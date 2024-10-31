#include <bits/stdc++.h>
#include <climits>

using namespace std;

int func(int i, int j, int &a, int &b, int p, vector<vector<int>> &dp,
         vector<int> &v1, vector<int> &v2) {
  if (i == a) {
    return 0;
  }
  j = upper_bound(v2.begin() + j, v2.end(), p) - v2.begin();
  if (dp[i][j] != -1)
    return dp[i][j];
  if (j == b && v1[i] <= p)
    return 1e+9;
  int take = 1e+9, nottake = 1e+9;
  if (j != b)
    take = func(i + 1, j + 1, a, b, v2[j], dp, v1, v2) + 1;
  if (v1[i] > p)
    nottake = func(i + 1, j, a, b, v1[i], dp, v1, v2);
  return dp[i][j] = min(take, nottake);
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
  int n = arr1.size(), m = arr2.size();
  vector<vector<int>> dp(n, vector<int>(m + 1, -1));
  sort(arr2.begin(), arr2.end());
  int a = func(0, 0, n, m, -1, dp, arr1, arr2);
  if (a > n)
    return -1;
  return a;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];
  cout << makeArrayIncreasing(arr1, arr2) << "\n";
  return 0;
}
