#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int ans = INT_MIN;
  int cmp = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      cmp++;
      ans = max(cmp, ans);
    }
    else
    {
      ans = max(cmp, ans);
      cmp = 0;
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

  cout << findMaxConsecutiveOnes(nums) << "\n";

  return 0;
}