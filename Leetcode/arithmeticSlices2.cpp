#include <bits/stdc++.h>

using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
  long long ans = 0, n = nums.size();
  vector<unordered_map<long, long>> dp(n);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      long long diff = (long long)nums[i] - (long long)nums[j];
      dp[i][diff]++;
      if (dp[j].count(diff))
      {
        dp[i][diff] += dp[j][diff];
        ans += dp[j][diff];
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];

  cout << numberOfArithmeticSlices(nums) << "\n";

  return 0;
}