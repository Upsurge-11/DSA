#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums)
{
  int n = nums.size();
  int i = 0;
  while (i < n - 1 && nums[i] <= nums[i + 1])
    i++;
  if (i == n - 1)
    return true;
  i++;
  while (i < n - 1 && nums[i] <= nums[i + 1])
    i++;
  if (i == n - 1 && nums[n - 1] <= nums[0])
    return true;
  return false;
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
  if (check)
    cout << "Sorted\n";
  else
    cout << "Unsorted\n";

  return 0;
}