#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
  if (i == j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];
  int mini = INT_MAX;
  for (int k = i; k < j; k++)
    mini = min((nums[i - 1] * nums[k] * nums[j] + func(i, k, nums, dp) + func(k + 1, j, nums, dp)), mini);
  return dp[i][j] = mini;
}

int mcm(vector<int> &nums)
{
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
  return func(1, nums.size() - 1, nums, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << mcm(nums) << "\n";

  return 0;
}