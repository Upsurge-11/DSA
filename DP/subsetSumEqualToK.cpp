#include <bits/stdc++.h>

using namespace std;

bool subsetSumEqualToTarget(vector<int> &nums, int target, int ind, vector<vector<int>> &dp)
{
  if (target == 0)
    return true;
  if (ind == 0)
    return (nums[ind] == target);
  if (dp[ind][target] != -1)
    return dp[ind][target];
  bool notTake = subsetSumEqualToTarget(nums, target, ind + 1, dp);
  bool take = false;
  if (nums[ind] <= target)
    take = subsetSumEqualToTarget(nums, target - nums[ind], ind + 1, dp);
  return dp[ind][target] = (take || notTake);
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  vector<vector<int>> dp(n, vector<int>(target + 1, -1));
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  if (subsetSumEqualToTarget(nums, target, n - 1, dp))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}