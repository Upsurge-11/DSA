#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int> &nums)
{
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << maxCoins(nums) << "\n";

  return 0;
}