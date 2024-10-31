#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  int count = 0;
  int sum = 0;
  unordered_map<int, int> map;
  map[sum] = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    if (map.find(sum - k) != map.end())
    {
      count += map[sum - k];
    }
    map[sum]++;
  }
  return count;
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