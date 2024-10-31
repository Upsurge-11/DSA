#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
  int low = 0;
  int high = nums.size();
  int mid;
  if (target > nums[high - 1])
    return high;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    if (target < nums[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << searchInsert(nums, target) << "\n";

  return 0;
}