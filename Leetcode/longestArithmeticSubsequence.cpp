#include <bits/stdc++.h>

using namespace std;

int func(int ind, int diff, vector<int> &nums, unordered_map<int, int> dp[])
{
  if (ind < 0)
    return 0;
  if (dp[ind].count(diff))
    return dp[ind][diff];
  int ans = 0;
  for (int j = 0; j < ind; j++)
  {
    if (nums[ind] - nums[j] == diff)
    {
      ans = max(ans, 1 + func(j, diff, nums, dp));
    }
  }
  return dp[ind][diff] = ans;
}

int longestArithSeqLength(vector<int> &nums)
{
  int n = nums.size();
  if (n <= 2)
    return n;
  int ans = 0;
  unordered_map<int, int> dp[n + 1];
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = i + 1; j < n; j++)
  //     ans = max(ans, 2 + func(i, nums[j] - nums[i], nums, dp));
  // }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      int diff = nums[i] - nums[j];
      int cnt = 1;
      if (dp[j].count(diff))
      {
        cnt = dp[j][diff];
      }
      dp[i][diff] = 1 + cnt;
      ans = max(ans, dp[i][diff]);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << longestArithSeqLength(nums) << "\n";
  return 0;
}