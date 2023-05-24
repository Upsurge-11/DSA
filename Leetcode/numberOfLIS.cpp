#include <bits/stdc++.h>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
  vector<int> dp(nums.size(), 1), count(nums.size(), 1);
  int maxi = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    for (int prev = 0; prev < i; prev++)
      if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
      {
        dp[i] = 1 + dp[prev];
        count[i] = count[prev];
      }
      else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
        count[i] += count[prev];
    maxi = max(maxi, dp[i]);
  }
  int ans = 0;
  for (int i = 0; i < nums.size(); i++)
    if (dp[i] == maxi)
      ans += count[i];
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << findNumberOfLIS(nums) << "\n";

  return 0;
}