#include <bits/stdc++.h>

using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
  int n = nums.size();
  int count = 0;
  int sum = 0;
  unordered_map<int, int> mp;
  mp[0] = 1;

  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    int rem = sum % k;
    if (rem < 0)
      rem += k;
    if (mp.find(rem) != mp.end())
      count += mp[rem];
    mp[rem]++;
  }

  return count;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << subarraysDivByK(nums, k) << "\n";

  return 0;
}