#include <bits/stdc++.h>

using namespace std;

// bool util(int ind, vector<int> &nums)
// {
//   if (ind == nums.size() - 1)
//     return true;
//   if (ind >= nums.size())
//     return false;
//   bool ans = false;
//   for (int i = 1; i <= nums[ind]; i++)
//   {
//     ans = ans || util(ind + i, nums);
//   }
//   return ans;
// }

// bool canJump(vector<int> &nums)
// {
//   return util(0, nums);
// }

bool canJump(vector<int> &nums)
{
  int n = nums.size();
  int maxReach = 0;
  for (int i = 0; i < n; i++)
  {
    if (i > maxReach)
      return false;
    maxReach = max(maxReach, i + nums[i]);
  }
  return true;
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

  if (canJump(nums))
  {
    cout << "Jump is possible.\n";
  }
  else
  {
    cout << "Jump is not possible.\n";
  }

  return 0;
}