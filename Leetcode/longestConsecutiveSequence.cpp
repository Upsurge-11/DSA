#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int count = 0, ans = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == nums[i - 1] + 1)
    {
      count++;
    }
    else
    {
      ans = max(ans, count);
      count = 1;
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
  {
    cin >> nums[i];
  }

  cout << longestConsecutive(nums) << "\n";

  return 0;
}