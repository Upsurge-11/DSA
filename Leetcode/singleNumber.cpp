#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    if (m.find(nums[i]) == m.end())
    {
      m[nums[i]] = 1;
    }
    else
      m[nums[i]]++;
  }
  for (auto i : m)
  {
    if (i.second == 1)
      return i.first;
  }
  return -1;
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
  cout << singleNumber(nums) << "\n";

  return 0;
}