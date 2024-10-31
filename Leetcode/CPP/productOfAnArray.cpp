#include <bits/stdc++.h>

using namespace std;

int arraySign(vector<int> &nums)
{
  int negCount = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 0)
      return 0;
    if (nums[i] < 0)
      negCount++;
  }
  return negCount % 2 == 0 ? 1 : -1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << arraySign(nums) << "\n";

  return 0;
}