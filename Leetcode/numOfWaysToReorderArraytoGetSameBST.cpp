#include <bits/stdc++.h>

using namespace std;

long long dfs(vector<int> &nums, long long mod,
              vector<vector<long long>> &comb) {
  int n = nums.size();
  if (n <= 2)
    return 1;
  vector<int> left, right;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[0])
      left.push_back(nums[i]);
    else
      right.push_back(nums[i]);
  }
  long long left_res = dfs(left, mod, comb) % mod;
  long long right_res = dfs(right, mod, comb) % mod;
  int left_len = left.size(), right_len = right.size();
  return (((comb[n - 1][left_len] * left_res) % mod) * right_res) % mod;
}

int numOfWays(vector<int> &nums) {
  long long mod = 1e9 + 7;
  int n = nums.size();
  vector<vector<long long>> comb(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    comb[i] = vector<long long>(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    }
  }
  long long ans = dfs(nums, mod, comb);
  return (ans % mod - 1) % mod;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  cout << numOfWays(nums) << "\n";
  return 0;
}
