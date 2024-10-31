#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
  int maxi = 0, ans = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    maxi += nums[i];
    ans = max(ans, maxi);
    if (maxi < 0)
      maxi = 0;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << maxSubArray(nums) << "\n";

  return 0;
}