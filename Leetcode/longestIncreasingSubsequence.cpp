#include <bits/stdc++.h>

using namespace std;

int func(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
{
  if (ind == nums.size())
    return 0;
  if (dp[ind][prev_ind + 1] != -1)
    return dp[ind][prev_ind + 1];
  int take = INT_MIN;
  if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    take = 1 + func(ind + 1, ind, nums, dp);
  int nonTake = func(ind + 1, prev_ind, nums, dp);
  return dp[ind][prev_ind + 1] = max(take, nonTake);
}

int lengthOfLIS(vector<int> &nums)
{
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
  return func(0, -1, nums, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  cout << lengthOfLIS(v) << "\n";

  return 0;
}