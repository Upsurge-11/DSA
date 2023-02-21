#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
  int low = 0;
  int high = nums.size() - 1;
  int mid;
  while (low < high)
  {
    mid = (low + high) / 2;
    if (mid % 2 == 1)
      mid--;
    if (nums[mid] == nums[mid + 1])
      low = mid + 2;
    else
      high = mid;
  }
  return nums[low];
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << singleNonDuplicate(nums) << "\n";

  return 0;
}