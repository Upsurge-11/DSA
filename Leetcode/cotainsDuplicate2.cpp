#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++)
  {
    if (map.find(nums[i]) != map.end())
    {
      if (i - map[nums[i]] <= k)
      {
        return true;
      }
    }
    map[nums[i]] = i;
  }
  return false;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < nums.size(); i++)
  {
    cin >> nums[i];
  }

  if (containsNearbyDuplicate(nums, k))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }

  return 0;
}