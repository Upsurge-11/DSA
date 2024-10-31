#include <bits/stdc++.h>

using namespace std;

int numSubseq(vector<int> &nums, int target)
{
  int n = nums.size();
  int mod = 1e9 + 7;
  sort(nums.begin(), nums.end());
  vector<int> pows(n, 1);
  for (int i = 1; i < n; i++)
    pows[i] = (pows[i - 1] * 2) % mod;
  int ans = 0;
  int l = 0, r = n - 1;
  while (l <= r)
  {
    if (nums[l] + nums[r] > target)
      r--;
    else
    {
      ans = (ans + pows[r - l]) % mod;
      l++;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int target;
  cin >> target;
  cout << numSubseq(nums, target) << "\n";

  return 0;
}