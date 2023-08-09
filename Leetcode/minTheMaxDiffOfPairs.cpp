#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &nums, int p, int mid)
{
  int count = 0;
  for (int i = 1; i < nums.size() && count < p; ++i)
  {
    if (nums[i] - nums[i - 1] <= mid)
    {
      count++;
      i++;
    }
  }
  return count >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
  sort(nums.begin(), nums.end());
  int left = 0, right = nums[nums.size() - 1] - nums[0];
  while (left < right)
  {
    int mid = left + (right - left) / 2;
    if (func(nums, p, mid))
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main()
{
  int n, p;
  cin >> n >> p;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << minimizeMax(nums, p) << "\n";
  return 0;
}