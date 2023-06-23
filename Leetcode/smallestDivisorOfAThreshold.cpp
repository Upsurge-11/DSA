#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &nums, int mid, int threshold)
{
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
    sum += ceil((double)nums[i] / mid);
  return sum <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
  int low = 1, high = *max_element(nums.begin(), nums.end());
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (func(nums, mid, threshold))
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main()
{
  int n, threshold;
  cin >> n >> threshold;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << smallestDivisor(nums, threshold) << "\n";
  return 0;
}