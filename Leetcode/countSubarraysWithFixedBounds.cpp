#include <bits/stdc++.h>

using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
  int n = nums.size();
  int leftBound = -1;
  int lastMin = -1, lastMax = -1;
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= minK && nums[i] <= maxK)
    {
      if (nums[i] == minK)
        lastMin = i;
      if (nums[i] == maxK)
        lastMax = i;
      ans += max(0, min(lastMin, lastMax) - leftBound);
    }
    else
    {
      leftBound = i;
      lastMin = -1;
      lastMax = -1;
    }
  }
  return ans;
}

int main()
{
  int n, minK, maxK;
  cin >> n >> minK >> maxK;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << countSubarrays(nums, minK, maxK) << "\n";

  return 0;
}