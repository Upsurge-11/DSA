#include <bits/stdc++.h>

using namespace std;

int combinationHelper(vector<int> &nums, int T, int n, vector<int> &dp)
{
  if (T == 0)
    return 1;
  int ans = 0;
  if (dp[T] != -1)
    return dp[T];

  for (int i = 0; i < n; i++)
  {
    if (nums[i] <= T)
    {
      ans += combinationHelper(nums, T - nums[i], n, dp);
    }
  }
  return dp[T] = ans;
}

int combinationSum4(vector<int> &nums, int target)
{
  int n = nums.size();
  vector<int> dp(target + 1, -1);
  return combinationHelper(nums, target, n, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &i : nums)
    cin >> i;
  int target;
  cin >> target;
  cout << combinationSum4(nums, target) << "\n";
  return 0;
}