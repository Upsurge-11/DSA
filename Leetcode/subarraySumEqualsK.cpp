#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  int ans = 0, sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == k || sum == k)
    {
      ans++;
      sum = 0;
      continue;
    }
    else if (sum > k)
    {
      sum = 0;
      continue;
    }
    sum += nums[i];
  }
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << subarraySum(nums, k) << "\n";

  return 0;
}