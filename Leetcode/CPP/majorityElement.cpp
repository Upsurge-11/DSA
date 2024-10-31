#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
  int times = nums.size();
  times /= 2;
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    if (m.find(nums[i]) != m.end())
    {
      m[nums[i]]++;
    }
    else
    {
      m[nums[i]] = 1;
    }
    if (m[nums[i]] > times)
    {
      return nums[i];
    }
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
  cout << majorityElement(nums) << "\n";

  return 0;
}