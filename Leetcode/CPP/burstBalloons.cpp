#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
  
    return dp[i][j];
  int ans = INT_MIN;
  for (int ind = i; ind <= j; ind++)
    ans = max(ans, (nums[i - 1] * nums[ind] * nums[j + 1]) + func(i, ind - 1, nums, dp) + func(ind + 1, j, nums, dp));
  return dp[i][j] = ans;
}

int maxCoins(vector<int> &nums)
{
  int n = nums.size();
  nums.push_back(1);
  nums.insert(nums.begin(), 1);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return func(1, n, nums, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << maxCoins(nums) << "\n";

  return 0;
}