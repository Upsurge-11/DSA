#include <bits/stdc++.h>

using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
  long long ans = 0, zeroFilledSubarray = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 0)
      ans += ++zeroFilledSubarray;
    else
      zeroFilledSubarray = 0;
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

  cout << zeroFilledSubarray(nums) << "\n";

  return 0;
}