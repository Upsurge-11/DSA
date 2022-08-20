#include <bits/stdc++.h>

using namespace std;

// int lengthOfLIS(vector<int> &nums)
// {
//   int count = INT_MIN;
//   for (int i = 0; i < nums.size(); i++)
//   {
//     int temp = 1;
//     int prev = INT_MIN;
//     for (int j = i + 1; j < nums.size(); j++)
//     {
//       if ((nums[j] > nums[i]) && nums[j] > prev)
//       {
//         prev = nums[j];
//         temp++;
//       }
//     }
//     count = max(count, temp);
//   }
//   return count;
// }

int lengthOfLIS(vector<int> &nums)
{
  vector<int> dp(nums.size(), 1);
  int ans = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (nums[i] > nums[j])
      {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
  {
    cin >> i;
  }
  cout << lengthOfLIS(v) << "\n";

  return 0;
}