#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &nums, int i, vector<int> &dp)
{
  if (i == nums.size())
    return true;
  if (dp[i] != -1)
    return dp[i];

  if (i + 1 < nums.size() && nums[i] == nums[i + 1])
  {
    if (func(nums, i + 2, dp))
      return true;
    if (i + 2 < nums.size() && nums[i] == nums[i + 2])
    {
      if (func(nums, i + 3, dp))
        return true;
    }
  }
  if (i + 2 < nums.size() && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2)
  {
    if (func(nums, i + 3, dp))
      return true;
  }
  return dp[i] = false;
}

bool validPartition(vector<int> &nums)
{
  vector<int> dp(nums.size(), -1);
  return func(nums, 0, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << validPartition(nums) << "\n";
  return 0;
}